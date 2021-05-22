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

    // Definitions
    static constexpr const TYPE INF = 1 << ( ( sizeof( TYPE ) * 8 ) - 1 );

    // Constructors
    constexpr IntX_t( )
    {
    }

    constexpr IntX_t( const TYPE value_ )
      : m_Value( value_ )
    {
    }

    // Special numbers
    void SetInfinity( )
    {
      m_Value = IntX_t< TYPE >::INF;
    }

    void SetMin( )
    {
      m_Value = IntX_t< TYPE >::INF + 1;
    }

    void SetMax( )
    {
      m_Value = - ( IntX_t< TYPE >::INF + 1 );
    }

    // Binary operators
    IntX_t< TYPE > operator *( const IntX_t< TYPE > rhs_ )
    {
      return m_Value * rhs_.m_Value;
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
        ss << (int) m_Value;
      }

      return ss.str( );
    }

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
        IntX_t< TYPE > value;
        value.SetInfinity( );
        return value;
      }

      static constexpr IntX_t< TYPE > lowest( )
      {
        IntX_t< TYPE > value;
        value.SetMin( );
        return value;
      }

      static constexpr IntX_t< TYPE > min( )
      {
        IntX_t< TYPE > value;
        value.SetMin( );
        return value;
      }

      static constexpr IntX_t< TYPE > max( )
      {
        IntX_t< TYPE > value;
        value.SetMax( );
        return value;
      }
  };
}
