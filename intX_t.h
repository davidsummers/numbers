#pragma once

// IntX_t
// Has Infinity.

#include <cstdint>
#include <iostream>
#include <limits>
#include <sstream>

template< typename STYPE, typename UTYPE >
class IntX_t
{
  public:

    // Types
    using Stype = STYPE;
    using Utype = UTYPE;

    // Definitions
    static constexpr const Stype INF = 1ULL << ( ( sizeof( Stype ) * 8 ) - 1 );

    // Constructors
    constexpr IntX_t( )
    {
    }

    constexpr IntX_t( const Stype value_ )
      : m_Value( value_ )
    {
    }

    // Special numbers
    void SetInfinity( )
    {
      m_Value = IntX_t< Stype, Utype >::INF;
    }

    void SetMin( )
    {
      m_Value = IntX_t< Stype, Utype >::INF + 1;
    }

    void SetMax( )
    {
      m_Value = - ( IntX_t< Stype, Utype >::INF + 1 );
    }

    // Binary operators
    IntX_t< Stype, Utype > operator -( const IntX_t< Stype, Utype > rhs_ )
    {
      return m_Value - rhs_.m_Value;
    }

    IntX_t< Stype, Utype > operator *( const IntX_t< Stype, Utype > rhs_ )
    {
      return m_Value * rhs_.m_Value;
    }

    // Conversion to Stype
    explicit operator Stype( )
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
    Stype GetEncodedValue( ) const
    {
      return m_Value;
    }

    void SetEncodedValue( const Stype & value_ )
    {
      m_Value = value_;
    }

  protected:

  private:

    Stype m_Value = 0;
};


using Int8_t  = IntX_t< int8_t,  uint8_t  >;
using Int16_t = IntX_t< int16_t, uint16_t >;
using Int32_t = IntX_t< int32_t, uint32_t >;
using Int64_t = IntX_t< int64_t, uint64_t >;


template < typename TYPE, typename UTYPE >
std::ostream &operator <<( std::ostream &s_, const IntX_t< TYPE, UTYPE > &value_ )
{
  s_ << value_.ToString( );
  return s_;
}


namespace std
{
  template < typename STYPE, typename UTYPE >
  class numeric_limits< IntX_t< STYPE, UTYPE > >
  {
    public:

      static constexpr const bool has_infinity = true;

      static constexpr const bool is_signed = true;

      static constexpr const bool is_specialized = true;

      static constexpr const bool is_exact = true;

      static constexpr IntX_t< STYPE, UTYPE > infinity( )
      {
        IntX_t< STYPE, UTYPE > value;
        value.SetInfinity( );
        return value;
      }

      static constexpr IntX_t< STYPE, UTYPE > lowest( )
      {
        IntX_t< STYPE, UTYPE > value;
        value.SetMin( );
        return value;
      }

      static constexpr IntX_t< STYPE, UTYPE > min( )
      {
        IntX_t< STYPE, UTYPE > value;
        value.SetMin( );
        return value;
      }

      static constexpr IntX_t< STYPE, UTYPE > max( )
      {
        IntX_t< STYPE, UTYPE > value;
        value.SetMax( );
        return value;
      }
  };
}
