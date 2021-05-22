#pragma once

// IntXu_t
// Has Infinity.
// Has 'uncertainty' bit as lowest bit.
// This reduces the min/max to half the "normal" min/max.

/*
 * S NN U
 * 0 00 0 = 0
 * 0 00 1 = 0...
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
 * 1 11 1 = -0...
 */

#include <cstdint>
#include <iostream>
#include <limits>
#include <sstream>

template< typename TYPE >
class IntXu_t
{
  public:

    // Definitions.
    static constexpr const TYPE INF = 1 << ( ( sizeof( TYPE ) * 8 ) - 1 );

    // Constructors.
    constexpr IntXu_t( )
    {
      std::cout << "IntXu_t: Set Value = 0" << std::endl;
    }

    constexpr IntXu_t( const TYPE value_ )
      : m_Value( value_ * 2 )
    {
      if ( value_ > static_cast< TYPE >( std::numeric_limits< IntXu_t< TYPE > >::max( ) ) )
      {
        m_Value = static_cast< TYPE >( std::numeric_limits< IntXu_t< TYPE > >::max( ) ) + 1;
      }
      else if ( value_ < static_cast< TYPE >( std::numeric_limits< IntXu_t< TYPE > >::min( ) ) )
      {
        m_Value = static_cast< TYPE >( std::numeric_limits< IntXu_t< TYPE > >::min( ) ) - 1;
      }

      std::cout << "IntXu_t: Set Value = " << value_ << " Encoded: " << m_Value << std::endl;
    }

    // Special numbers
    void SetInfinity( )
    {
      SetEncodedValue( IntXu_t< TYPE >::INF );
    }

    void SetMin( )
    {
      SetEncodedValue( IntXu_t< TYPE >::INF + 1 );
    }

    void SetMax( )
    {
      SetEncodedValue( - ( IntXu_t< TYPE >::INF + 1 ) );
    }

    // Conversion operators
    explicit operator TYPE( ) const
    {
      TYPE value = m_Value >> 2;
      return value;
    }

    // Binary operators
    IntXu_t< TYPE > operator *( const IntXu_t< TYPE > rhs_ )
    {
      const TYPE value = static_cast< TYPE >( *this );
      std::cout << "LHS: " << value << std::endl;
      const TYPE rhs   = static_cast< TYPE >( rhs_ );
      std::cout << "RHS: " << rhs << std::endl;
      TYPE result = value * rhs;
      std::cout << "Result: " << result << std::endl;
      IntXu_t res( result );
      std::cout << "Converted Result: " << res << std::endl;
      return result;
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
