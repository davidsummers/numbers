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

    static constexpr const TYPE INF = 1 << ( ( sizeof( TYPE ) * 8 ) - 1 );

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

      if ( m_Value == INF )
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
  template < typename TYPE >
  class numeric_limits< IntX_t< TYPE > >
  {
    public:

      static constexpr const bool has_infinity = true;

      static constexpr const bool is_specialized = true;

      static constexpr const bool is_exact = true;

      static constexpr IntX_t< TYPE > infinity( )
      {
        return IntX_t< TYPE >::INF;
      }

      static constexpr IntX_t< TYPE > lowest( )
      {
        return IntX_t< TYPE >::INF + 1;
      }

      static constexpr IntX_t< TYPE > min( )
      {
        return IntX_t< TYPE >::INF + 1;
      }

      static constexpr IntX_t< TYPE > max( )
      {
        return -( IntX_t< TYPE >::INF + 1 );
      }
  };
}
