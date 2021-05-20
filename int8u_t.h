#pragma once

// Int8u_t
// Has Infinity.
// Has 'uncertainty' bit as lowest bit.
// This reduces the min/max to -63 / 63.

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

class Int8u_t
{
  public:

    static constexpr const int8_t INF = 0x80;

    constexpr Int8u_t( )
    {
    }

    std::string ToString( ) const;

    // Comparisons
    bool operator <(  const int8_t rhs ) const;

    // Self Comparisons.
    bool operator ==( const Int8u_t &rhs ) const;

    // Encode/Decode
    int8_t GetEncodedValue( ) const;
    void SetEncodedValue( const int8_t & );

  protected:

  private:

    int8_t m_Value = 0;
};


std::ostream &operator <<( std::ostream &s_, const Int8u_t &value_ );


bool operator <( const int8_t &lhs_, const Int8u_t &rhs_ );


namespace std
{
  template < >
  class numeric_limits< Int8u_t >
  {
    public:

      static constexpr const bool has_infinity = true;

      static constexpr const bool is_specialized = true;

      static constexpr const bool is_exact = false;

      static constexpr Int8u_t infinity( )
      {
        Int8u_t value;
        value.SetEncodedValue( Int8u_t::INF );
        return value;
      }

      static constexpr Int8u_t lowest( )
      {
        Int8u_t value;
        value.SetEncodedValue( -127 ); // Is -63 encoded.
        return value;
      }

      static constexpr Int8u_t min( )
      {
          Int8u_t value;
          value.SetEncodedValue( -127 ); // Is -63 encoded.
          return value;
      }

      static constexpr Int8u_t max( )
      {
          Int8u_t value;
          value.SetEncodedValue( 127 ); // Is 63 encoded.
          return value;
      }
  };
}
