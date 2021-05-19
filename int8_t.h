#pragma once

#include <cstdint>
#include <iostream>
#include <limits>
#include <sstream>

class Int8_t
{
  public:

    static constexpr const int8_t INF = 0x80;

    constexpr Int8_t( )
    {
    }

    constexpr Int8_t( const uint16_t value_ )
      : m_Value( (int8_t) value_ )
    {
    }

    std::string ToString( ) const;

  protected:

  private:

    int8_t m_Value = 0;
};


std::ostream &operator <<( std::ostream &s_, const Int8_t &value_ );


namespace std
{
  template < >
  class numeric_limits< Int8_t >
  {
    public:

      static constexpr const bool has_infinity = true;

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

