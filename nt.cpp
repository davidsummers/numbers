#include "int8_t.h"
#include "int8u_t.h"

int main( )
{
  {
    Int8_t i8;

    std::cout << "Int8_t" << std::endl;
    std::cout << "======" << std::endl;

    std::cout << "Is Exact: " << std::numeric_limits< Int8_t >::is_exact << std::endl;

    std::cout << "Has Infinity: " << std::numeric_limits< Int8_t >::has_infinity << std::endl;

    std::cout << "Infinity: " << std::numeric_limits< Int8_t >::infinity( ) << std::endl;

    std::cout << "Min: " << std::numeric_limits< Int8_t >::min( ) << std::endl;

    std::cout << "Max: " << std::numeric_limits< Int8_t >::max( ) << std::endl;

    std::cout << "Lowest: " << std::numeric_limits< Int8_t >::lowest( ) << std::endl;

    for ( uint16_t u16 = 0; u16 <= 255; u16++ )
    {
      i8 = u16;
      std::cout << "Unsigned " << (int) u16 << " -> Signed " << i8 << std::endl;
    }
  }


  {
    Int8u_t i8u;

    std::cout << "Int8u_t" << std::endl;
    std::cout << "======" << std::endl;

    std::cout << "Is Exact: " << std::numeric_limits< Int8u_t >::is_exact << std::endl;

    std::cout << "Has Infinity: " << std::numeric_limits< Int8u_t >::has_infinity << std::endl;

    std::cout << "Infinity: " << std::numeric_limits< Int8u_t >::infinity( ) << std::endl;

    std::cout << "Min: " << std::numeric_limits< Int8u_t >::min( ) << std::endl;

    std::cout << "Max: " << std::numeric_limits< Int8u_t >::max( ) << std::endl;

    std::cout << "Lowest: " << std::numeric_limits< Int8u_t >::lowest( ) << std::endl;

    for ( uint16_t u16 = 0; u16 <= 255; u16++ )
    {
      i8u.SetEncodedValue( u16 );
      std::cout << "Unsigned " << (int) u16 << " -> Signed " << i8u << std::endl;
    }
  }

  return 0;
}
