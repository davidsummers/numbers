#pragma once

// IntX_t
// Has Infinity.

/*
 * S N
 * 0 0 = 0
 * 0 1 = 1
 * 1 0 = INF
 * 1 1 = -1
 */

#include <cstdint>
#include <iostream>
#include <limits>
#include <sstream>

template< typename OTYPE_, typename UTYPE_ >
class IntX_t
{
  public:

    // Types
    using Otype = OTYPE_;
    using Utype = UTYPE_;

    // Definitions
    static constexpr const Utype one   = 1ull;
    static constexpr const Utype shift = ( sizeof( Otype ) * 8 ) - 1;
    static constexpr const Utype INF   = one << shift;

    // Constructors
    constexpr IntX_t( )
    {
    }

    constexpr IntX_t( const Otype value_ )
      : m_Value( value_ )
    {
    }

    // Special numbers
    constexpr void SetInfinity( )
    {
      m_Value = IntX_t< Otype, Utype >::INF;
    }

    constexpr void SetMin( )
    {
      m_Value = IntX_t< Otype, Utype >::INF;
      m_Value++;
    }

    constexpr void SetMax( )
    {
      m_Value = IntX_t< Otype, Utype >::INF;
      m_Value++;
      m_Value = -m_Value ;
    }

    // Math operators
    IntX_t< Otype, Utype > operator +( const IntX_t< Otype, Utype > rhs_ ) const
    {
      return m_Value + rhs_.m_Value;
    }

    IntX_t< Otype, Utype > operator -( const IntX_t< Otype, Utype > rhs_ ) const
    {
      return m_Value - rhs_.m_Value;
    }

    IntX_t< Otype, Utype > operator *( const IntX_t< Otype, Utype > rhs_ ) const
    {
      return m_Value * rhs_.m_Value;
    }

    IntX_t< Otype, Utype > operator /( const IntX_t< Otype, Utype > rhs_ ) const
    {
      return m_Value / rhs_.m_Value;
    }

    // Comparison operators
    bool operator ==( const IntX_t< Otype, Utype > &rhs_ ) const
    {
      return m_Value == rhs_.m_Value;
    }

    // Conversion to Otype
    explicit operator Otype( )
    {
      return m_Value;
    }

    // Conversion to Utype
    explicit operator Utype( )
    {
      return m_Value;
    }

    // Conversion to string output.
    std::string ToString( ) const
    {
      std::stringstream ss;

      if ( m_Value == INF )
      {
        ss << "INF";
      }
      else
      {
        ss << (int64_t) m_Value;
      }

      return ss.str( );
    }

    // Encode/Decode
    Otype GetEncodedValue( ) const
    {
      return m_Value;
    }

    void SetEncodedValue( const Otype & value_ )
    {
      m_Value = value_;
    }

    constexpr const char *Name( )
    {
      static_assert( sizeof( Otype ) == 1 ||
                     sizeof( Otype ) == 2 ||
                     sizeof( Otype ) == 4 ||
                     sizeof( Otype ) == 8,
                     "Invalid size for IntX_t type." );

      if constexpr ( sizeof( Otype ) == 1 )
      {
        return "Int8_t";
      }
      else if constexpr ( sizeof( Otype ) == 2 )
      {
        return "Int16_t";
      }
      else if constexpr ( sizeof( Otype ) == 4 )
      {
        return "Int32_t";
      }
      else if constexpr ( sizeof( Otype ) == 8 )
      {
        return "Int64_t";
      }
      else
      {
        return "Unknown size for IntX_t type";
      }

    }

  protected:

  private:

    Otype m_Value = 0;
};


using Int8_t  = IntX_t< int8_t,  uint8_t  >;
using Int16_t = IntX_t< int16_t, uint16_t >;
using Int32_t = IntX_t< int32_t, uint32_t >;
using Int64_t = IntX_t< int64_t, uint64_t >;


//////////////////////////////////////////
template < typename TYPE, typename UTYPE >
std::ostream &operator <<( std::ostream &s_, const IntX_t< TYPE, UTYPE > &value_ )
{
  s_ << value_.ToString( );
  return s_;
}


namespace std
{
  template < typename Otype, typename UTYPE >
  class numeric_limits< IntX_t< Otype, UTYPE > >
  {
    public:

      static constexpr const bool has_infinity = true;

      static constexpr const bool is_signed = true;

      static constexpr const bool is_specialized = true;

      static constexpr const bool is_exact = true;

      static constexpr const bool is_modulo = true;

      static constexpr const bool is_integer = true;

      static constexpr IntX_t< Otype, UTYPE > infinity( )
      {
        IntX_t< Otype, UTYPE > value;
        value.SetInfinity( );
        return value;
      }

      static constexpr IntX_t< Otype, UTYPE > lowest( )
      {
        IntX_t< Otype, UTYPE > value;
        value.SetMin( );
        return value;
      }

      static constexpr IntX_t< Otype, UTYPE > min( )
      {
        IntX_t< Otype, UTYPE > value;
        value.SetMin( );
        return value;
      }

      static constexpr IntX_t< Otype, UTYPE > max( )
      {
        IntX_t< Otype, UTYPE > value;
        value.SetMax( );
        return value;
      }
  };
}
