#pragma once

// IntXu_t
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

template< typename TYPE >
class IntXu_t
{
  public:

    static constexpr const TYPE INF = 1 << ( ( sizeof( TYPE ) * 8 ) - 1 );

    constexpr IntXu_t( )
    {
    }

    constexpr IntXu_t( const TYPE value_ )
      : m_Value( value_ )
    {
    }

    std::string ToString( ) const
    {
      std::stringstream ss;

      bool negative  = ( m_Value & 0x80 ) != 0;
      bool uncertain = ( m_Value & 1 ) != 0;
      int8_t value = m_Value >> 1;

      if ( negative && ( ( m_Value & 0x7f ) == 0 ) )
      {
        ss << "INF";
      }
      else
      {
        if ( negative && uncertain )
        {
          value = -( ~value ); // Negative of one's complement.
        }

        if ( negative && uncertain && value == 0 )
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

    int8_t m_Value = 0;
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
