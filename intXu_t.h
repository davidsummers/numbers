#pragma once

// IntXu_t
// Has Infinity.
// Has 'uncertainty' bit as lowest bit.
// This reduces the min/max to half the "normal" min/max.

/*
 * S NN U
 * 0 00 0 = 0
 * 0 00 1 = 0... ( between 0 and 1 )
 * 0 01 0 = 1
 * 0 01 1 = 1...
 * 0 10 0 = 2
 * 0 10 1 = 2...
 * 0 11 0 = 3
 * 0 11 1 = 3...
 * 1 00 0 = INF
 * 1 00 1 = -3...
 * 1 01 0 = -3
 * 1 01 1 = -2...
 * 1 10 0 = -2
 * 1 10 1 = -1...
 * 1 11 0 = -1
 * 1 11 1 = -0... ( between -1 and 0 )
 */

#include <cstdint>
#include <iostream>
#include <limits>
#include <sstream>

template< typename TYPE >
class IntXu_t
{
  public:

    using Otype = TYPE;
    using Utype = TYPE;

    // Definitions.
    static constexpr const TYPE INF = 1ull << ( ( sizeof( TYPE ) * 8 ) - 1 );

    // Constructors.
    constexpr IntXu_t( )
    {
    }

    constexpr IntXu_t( const TYPE value_ )
      : m_Value( value_ * 2 )
    {
      TYPE max = static_cast< TYPE >( std::numeric_limits< IntXu_t< TYPE > >::max( ) );
      if ( value_ > max  )
      {
        m_Value = max * 2 + 1;
      }

      TYPE min = static_cast< TYPE >( std::numeric_limits< IntXu_t< TYPE > >::min( ) );
      if ( value_ < min  )
      {
        m_Value = max * 2 - 1;
      }
    }

    // Special numbers
    void SetInfinity( )
    {
      SetEncodedValue( IntXu_t< TYPE >::INF );
    }

    void SetMin( )
    {
      SetEncodedValue( IntXu_t< TYPE >::INF + 2 );
    }

    void SetMax( )
    {
      SetEncodedValue( - ( IntXu_t< TYPE >::INF + 2 ) );
    }

    void SetUncertain( const bool uncertain_ = true )
    {
      m_Value = ( m_Value & ( ~0ull << 1 ) ) | uncertain_;
    }

    bool GetUncertain( ) const
    {
      return m_Value & 1;
    }

    // Conversion operators
    explicit operator TYPE( ) const
    {
      TYPE value = m_Value >> 1;
      return value;
    }

    operator uint64_t( )
    {
      return m_Value >> 1;
    }

    // Binary operators
    IntXu_t< TYPE > operator *( const IntXu_t< TYPE > rhs_ )
    {
      const TYPE lhs = static_cast< TYPE >( *this );
      const TYPE rhs = static_cast< TYPE >( rhs_ );
      TYPE result = lhs * rhs;
      IntXu_t res( result );
      TYPE min = std::numeric_limits< IntXu_t< TYPE > >::min( );
      TYPE max = std::numeric_limits< IntXu_t< TYPE > >::max( );
      res.SetUncertain( GetUncertain( ) || rhs_.GetUncertain( ) ||
                        result < min ||
                        result > max );
      return res;
    }

    IntXu_t< TYPE > operator /( const IntXu_t< TYPE > rhs_ )
    {
      const TYPE lhs = static_cast< TYPE >( *this );
      const TYPE rhs = static_cast< TYPE >( rhs_ );
      TYPE result = lhs / rhs;
      IntXu_t res( result );
      res.SetUncertain( ( lhs % rhs ) != 0 );
      return res;
    }

    // Conversion to string output.
    std::string ToString( ) const
    {
      std::stringstream ss;

      bool uncertain = ( m_Value & 1 ) != 0;
      TYPE value = m_Value >> 1;

      if ( m_Value == INF )
      {
        ss << "INF";
      }
      else
      {
        if ( m_Value < 0 && uncertain )
        {
          value = ~value;
          value = -value; // Negative of one's complement.
        }

        if ( m_Value < 0 && uncertain && value == 0 )
        {
          ss << "-";
        }

        ss << (int) value;

        if ( uncertain )
        {
          ss << "...";
        }
      }

      return ss.str( );
    }


    // Comparisons
    bool operator <( const TYPE &rhs ) const;

    // Self Comparisons.
    bool operator ==( const IntXu_t< TYPE > &rhs ) const;

    // Encode/Decode
    TYPE GetEncodedValue( ) const
    {
      return m_Value;
    }

    void SetEncodedValue( const TYPE & value_ )
    {
      m_Value = value_;
    }

    const char *Name( )
    {
      if constexpr ( sizeof( Utype ) == 1 )
      {
        return "Int8u_t";
      }
      else if constexpr ( sizeof( Utype ) == 2 )
      {
        return "Int16u_t";
      }
      else if constexpr ( sizeof( Utype ) == 4 )
      {
        return "Int32u_t";
      }
      else if constexpr ( sizeof( Utype ) == 8 )
      {
        return "Int64u_t";
      }

      // FIXME - static_assert( false, "Unknown IntX_t type." );
      return "Unknown IntXu_t type";
    }

  protected:

  private:

    TYPE m_Value = 0;
};

using Int8u_t  = IntXu_t< int8_t  >;
using Int16u_t = IntXu_t< int16_t >;
using Int32u_t = IntXu_t< int32_t >;
using Int64u_t = IntXu_t< int64_t >;


template< typename TYPE >
std::ostream &operator <<( std::ostream &s_, const IntXu_t< TYPE > &value_ )
{
  s_ << value_.ToString( );
  return s_;
}


bool operator <( const int8_t &lhs_, const Int8u_t &rhs_ );


namespace std
{
  template < typename TYPE >
  class numeric_limits< IntXu_t< TYPE > >
  {
    public:

      static constexpr const bool has_infinity = true;

      static constexpr const bool is_signed = true;

      static constexpr const bool is_specialized = true;

      static constexpr const bool is_exact = false;

      static constexpr IntXu_t< TYPE > infinity( )
      {
        IntXu_t< TYPE > value;
        value.SetInfinity( );
        return value;
      }

      static constexpr IntXu_t< TYPE > lowest( )
      {
        IntXu_t< TYPE > value;
        value.SetMin( );
        return value;
      }

      static constexpr IntXu_t< TYPE > min( )
      {
          IntXu_t< TYPE > value;
          value.SetMin( );
          return value;
      }

      static constexpr IntXu_t< TYPE > max( )
      {
          IntXu_t< TYPE > value;
          value.SetMax( );
          return value;
      }
  };
}
