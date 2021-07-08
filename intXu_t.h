#pragma once

// IntXu_t
// Has Infinity.
// Has 'uncertainty' bit as lowest bit.
// This reduces the min/max to half the "normal" min/max.

/*
 * S N U
 * 0 0 0 = 0
 * 0 0 1 = 0... ( between 0 and 1 )
 * 0 1 0 = 1
 * 0 1 1 = 1...
 * 1 0 0 = INF
 * 1 0 1 = -1...
 * 1 1 0 = -1
 * 1 1 1 = -0... ( between -1 and 0 )
 */

#include <cstdint>
#include <iostream>
#include <limits>
#include <sstream>

template< typename OTYPE_, typename UTYPE_ >
class IntXu_t
{
  public:

    // Types
    using Otype = OTYPE_;
    using Utype = UTYPE_;

    // Definitions.
    static constexpr const Utype one   = 1ull;
    static constexpr const Utype shift = ( sizeof( Utype ) * 8 ) - 1;
    static constexpr const Utype INF   = one << shift;

    // Constructors.
    constexpr IntXu_t( )
    {
    }

    constexpr IntXu_t( const Otype value_ )
      : m_Value( value_ * 2 )
    {
      Otype max = static_cast< Otype >( std::numeric_limits< IntXu_t< Otype, Utype > >::max( ) );
      if ( value_ > max  )
      {
        m_Value = max * 2 + 1;
      }

      Otype min = static_cast< Otype >( std::numeric_limits< IntXu_t< Otype, Utype > >::min( ) );
      if ( value_ < min  )
      {
        m_Value = max * 2 - 1;
      }
    }

    explicit IntXu_t( const char *str_ )
    {
      std::string str = str_ == nullptr ? "" : str_;

      if ( str == "INF" )
      {
        m_Value = INF;
        return;
      }

      std::stringstream ss( str );
      int64_t value;
      ss >> value;

      m_Value = value * 2;

      std::size_t pos = str.find( "..." );

      if ( pos != 0 && pos != std::string::npos )
      {
        SetUncertain( );
      }
    }

    // Special numbers
    constexpr void SetInfinity( )
    {
      SetEncodedValue( IntXu_t< Otype, Utype >::INF );
    }

    constexpr void SetMin( )
    {
      m_Value = INF;
      m_Value++;
      m_Value++;
    }

    constexpr void SetMax( )
    {
      m_Value = INF;
      m_Value--;
      m_Value--;
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
    explicit operator Otype( ) const
    {
      Otype value = m_Value >> 1;
      return value;
    }

    explicit operator Utype( ) const
    {
      Utype value = m_Value >> 1;
      return value;
    }

    // Math operators
    IntXu_t< Otype, Utype > operator *( const IntXu_t< Otype, Utype > rhs_ ) const
    {
      const Otype lhs = static_cast< Otype >( *this );
      const Otype rhs = static_cast< Otype >( rhs_ );
      int64_t result = lhs * rhs;
      int64_t min = static_cast< Otype >( std::numeric_limits< IntXu_t< Otype, Utype > >::min( ) );
      int64_t max = static_cast< Otype >( std::numeric_limits< IntXu_t< Otype, Utype > >::max( ) );
      bool overUnderFlow = false;
      if ( result < min )
      {
        result = min;
        overUnderFlow = true;
      }
      if ( result > max )
      {
        result = result > max ? max : result;
        overUnderFlow = true;
      }
      IntXu_t res( result );
      // std::cout << "Res = " << (int64_t) result << ", LHS = " << (int64_t) lhs << ", RHS = " << (int64_t) rhs << std::endl;
      res.SetUncertain( GetUncertain( ) || rhs_.GetUncertain( ) || overUnderFlow );
      return res;
    }

    IntXu_t< Otype, Utype > operator /( const IntXu_t< Otype, Utype > rhs_ ) const
    {
      const Otype lhs = static_cast< Otype >( *this );
      const Otype rhs = static_cast< Otype >( rhs_ );
      Otype result = lhs / rhs;
      IntXu_t res( result );
      res.SetUncertain( ( lhs % rhs ) != 0 );
      return res;
    }

    // Comparison operators
    bool operator ==( const IntXu_t< Otype, Utype > &rhs_ ) const
    {
      return m_Value == rhs_.m_Value;
    }

    // Conversion to string output.
    std::string ToString( ) const
    {
      std::stringstream ss;

      bool uncertain = ( m_Value & 1 ) != 0;
      Otype value = m_Value >> 1;

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

    // Encode/Decode
    constexpr Otype GetEncodedValue( ) const
    {
      return m_Value;
    }

    constexpr void SetEncodedValue( const Otype & value_ )
    {
      m_Value = value_;
    }

    constexpr const char *Name( )
    {
      static_assert( sizeof( Otype ) == 1 ||
                     sizeof( Otype ) == 2 ||
                     sizeof( Otype ) == 4 ||
                     sizeof( Otype ) == 8,
                     "Invalid size for IntXu_t type." );

      if constexpr ( sizeof( Otype ) == 1 )
      {
        return "Int8u_t";
      }
      else if constexpr ( sizeof( Otype ) == 2 )
      {
        return "Int16u_t";
      }
      else if constexpr ( sizeof( Otype ) == 4 )
      {
        return "Int32u_t";
      }
      else if constexpr ( sizeof( Otype ) == 8 )
      {
        return "Int64u_t";
      }
      else
      {
        return "Unknown size for IntXu_t type";
      }
    }

  protected:

  private:

    Otype m_Value = 0;
};

using Int8u_t  = IntXu_t< int8_t,  uint8_t  >;
using Int16u_t = IntXu_t< int16_t, uint16_t >;
using Int32u_t = IntXu_t< int32_t, uint32_t >;
using Int64u_t = IntXu_t< int64_t, uint64_t >;

//////////////////////////////////////////////////////////////////////////
Int8u_t operator "" _i8u( const char *str_, const std::size_t /* size_ */ )
{
  Int8u_t val( str_ );
  return val;
}

///////////////////////////////////////////////////////////////////////////
Int16u_t operator "" _i16u( const char *str_, const std::size_t /* size_ */ )
{
  Int16u_t val( str_ );
  return val;
}

///////////////////////////////////////////////////////////////////////////
Int32u_t operator "" _i32u( const char *str_, const std::size_t /* size_ */ )
{
  Int32u_t val( str_ );
  return val;
}

///////////////////////////////////////////////////////////////////////////
Int64u_t operator "" _i64u( const char *str_, const std::size_t /* size_ */ )
{
  Int64u_t val( str_ );
  return val;
}

template< typename Otype, typename Utype >
std::ostream &operator <<( std::ostream &s_, const IntXu_t< Otype, Utype > &value_ )
{
  s_ << value_.ToString( );
  return s_;
}


bool operator <( const int8_t &lhs_, const Int8u_t &rhs_ );


namespace std
{
  template < typename Otype, typename Utype >
  class numeric_limits< IntXu_t< Otype, Utype > >
  {
    public:

      static constexpr const bool has_infinity = true;

      static constexpr const bool is_signed = true;

      static constexpr const bool is_specialized = true;

      static constexpr const bool is_exact = false;

      static constexpr const bool is_modulo = false;

      static constexpr const bool is_integer = true;

      static constexpr IntXu_t< Otype, Utype > infinity( )
      {
        IntXu_t< Otype, Utype > value;
        value.SetInfinity( );
        return value;
      }

      static constexpr IntXu_t< Otype, Utype > lowest( )
      {
        IntXu_t< Otype, Utype > value;
        value.SetMin( );
        return value;
      }

      static constexpr IntXu_t< Otype, Utype > min( )
      {
          IntXu_t< Otype, Utype > value;
          value.SetMin( );
          return value;
      }

      static constexpr IntXu_t< Otype, Utype > max( )
      {
          IntXu_t< Otype, Utype > value;
          value.SetMax( );
          return value;
      }
  };
}
