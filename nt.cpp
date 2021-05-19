#include "int8_t.h"

int main( )
{
  Int8_t i8;

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

  return 0;
}
