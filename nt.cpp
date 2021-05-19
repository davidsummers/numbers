#include <cstdint>
#include <iostream>
#include <limits>
#include <sstream>

class Int8_t
{
  public:

    static constexpr const int8_t INF = 0x80;

    constexpr Int8_t( );

    constexpr Int8_t( uint16_t );

    std::string ToString( ) const;

  protected:

  private:

    int8_t m_Value = 0;
};


std::ostream &operator <<( std::ostream &s_, const Int8_t &value_ )
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


constexpr Int8_t::Int8_t( )
{
}

constexpr Int8_t::Int8_t( const uint16_t value_ )
  : m_Value( (int8_t) value_ )
{
}


std::string Int8_t::ToString( ) const
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


int main( )
{
  Int8_t i8;

  std::cout << "Infinity: " << std::numeric_limits< Int8_t >::infinity( ) << std::endl;

  std::cout << "Min: " << std::numeric_limits< Int8_t >::min( ) << std::endl;

  std::cout << "Max: " << std::numeric_limits< Int8_t >::max( ) << std::endl;

  std::cout << "Lowest: " << std::numeric_limits< Int8_t >::lowest( ) << std::endl;

  for ( uint16_t u16 = 0; u16 <= 255; u16++ )
  {
    i8 = u16;
    std::cout << "Unsigned " << (int) u16 << " -> Signed " << i8 << std::endl;
  }

  return 0;
}
