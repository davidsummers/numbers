#pragma once

// IntX_t
// Has Infinity.

#include <cstdint>
#include <iostream>
#include <limits>
#include <sstream>

template< typename TYPE >
class IntX_t
{
  public:

    static constexpr const TYPE INF = 0x80;

    constexpr IntX_t( )
    {
    }

    constexpr IntX_t( const TYPE value_ )
      : m_Value( value_ )
    {
    }

    std::string ToString( ) const
    {
      std::stringstream ss;

      if ( ( ( m_Value & 0x80 ) != 0 ) && ( ( m_Value & 0x7f ) == 0 ) )
      {
        ss << "INF";
      }
      else
      {
        ss << (int) m_Value;
      }

      return ss.str( );
    }

  protected:

  private:

    TYPE m_Value = 0;
};


using Int8_t  = IntX_t< int8_t >;
using Int16_t = IntX_t< int16_t >;
using Int32_t = IntX_t< int32_t >;
using Int64_t = IntX_t< int64_t >;


template < typename TYPE >
std::ostream &operator <<( std::ostream &s_, const IntX_t< TYPE > &value_ )
{
  s_ << value_.ToString( );
  return s_;
}


namespace std
{
  template < >
  class numeric_limits< Int8_t >
  {
    public:

      static constexpr const bool has_infinity = true;

      static constexpr const bool is_specialized = true;

      static constexpr const bool is_exact = true;

      static constexpr Int8_t infinity( )
      {
        return Int8_t::INF;
      }

      static constexpr Int8_t lowest( )
      {
        return -127;
      }

      static constexpr Int8_t min( )
      {
        return -127;
      }

      static constexpr Int8_t max( )
      {
        return 127;
      }
  };
}



