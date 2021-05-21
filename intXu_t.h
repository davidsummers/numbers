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
        value.SetEncodedValue( IntXu_t< TYPE >::INF );
        return value;
      }

      static constexpr IntXu_t< TYPE > lowest( )
      {
        IntXu_t< TYPE > value;
        value.SetEncodedValue( IntXu_t< TYPE >::INF + 1 );
        return value;
      }

      static constexpr IntXu_t< TYPE > min( )
      {
          IntXu_t< TYPE > value;
          value.SetEncodedValue( IntXu_t< TYPE >::INF + 1 );
          return value;
      }

      static constexpr IntXu_t< TYPE > max( )
      {
          IntXu_t< TYPE > value;
          value.SetEncodedValue( - ( IntXu_t< TYPE >::INF + 1 ) );
          return value;
      }
  };
}
