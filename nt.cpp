#include "intX_t.h"
#include "intXu_t.h"

int main( )
{
  uint64_t counter = 0;

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

    for ( counter = 0; counter <= 5; counter++ )
    {
      i8 = counter;
      std::cout << "Unsigned " << counter << " -> Signed " << i8 << std::endl;
    }

    std::cout << "..." << std::endl;

    for ( counter = 128 - 5; counter <= 128 + 5; counter++ )
    {
      i8 = counter;
      std::cout << "Unsigned " << counter << " -> Signed " << i8 << std::endl;
    }

    std::cout << "..." << std::endl;

    for ( counter = 255 - 5; counter <= 255; counter++ )
    {
      i8 = counter;
      std::cout << "Unsigned " << counter << " -> Signed " << i8 << std::endl;
    }
  }

  {
    Int16_t i16;

    std::cout << "Int16_t" << std::endl;
    std::cout << "======" << std::endl;

    std::cout << "Is Exact: " << std::numeric_limits< Int16_t >::is_exact << std::endl;

    std::cout << "Has Infinity: " << std::numeric_limits< Int16_t >::has_infinity << std::endl;

    std::cout << "Infinity: " << std::numeric_limits< Int16_t >::infinity( ) << std::endl;

    std::cout << "Min: " << std::numeric_limits< Int16_t >::min( ) << std::endl;

    std::cout << "Max: " << std::numeric_limits< Int16_t >::max( ) << std::endl;

    std::cout << "Lowest: " << std::numeric_limits< Int16_t >::lowest( ) << std::endl;

    for ( counter = 0; counter <= 5; counter++ )
    {
      i16 = counter;
      std::cout << "Unsigned " << counter << " -> Signed " << i16 << std::endl;
    }

    std::cout << "..." << std::endl;

    for ( counter = 32768 - 5; counter <= 32768 + 5; counter++ )
    {
      i16 = counter;
      std::cout << "Unsigned " << counter << " -> Signed " << i16 << std::endl;
    }

    std::cout << "..." << std::endl;

    for ( counter = 65535 - 5; counter <= 65535; counter++ )
    {
      i16 = counter;
      std::cout << "Unsigned " << counter << " -> Signed " << i16 << std::endl;
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

    for ( uint16_t u16 = 0; u16 <= 5; u16++ )
    {
      i8u = u16;
      std::cout << "Unsigned " << (int) u16 << " -> Signed " << i8u << std::endl;
    }

    std::cout << "..." << std::endl;

    for ( counter = 128 - 5; counter <= 128 + 5; counter++ )
    {
      i8u = counter;
      std::cout << "Unsigned " << counter << " -> Signed " << i8u << std::endl;
    }

    std::cout << "..." << std::endl;

    for ( counter = 255 - 5; counter <= 255; counter++ )
    {
      i8u = counter;
      std::cout << "Unsigned " << counter << " -> Signed " << i8u << std::endl;
    }
  }

  {
    Int16u_t i16u;

    std::cout << "Int16u_t" << std::endl;
    std::cout << "======" << std::endl;

    std::cout << "Is Exact: " << std::numeric_limits< Int16u_t >::is_exact << std::endl;

    std::cout << "Has Infinity: " << std::numeric_limits< Int16u_t >::has_infinity << std::endl;

    std::cout << "Infinity: " << std::numeric_limits< Int16u_t >::infinity( ) << std::endl;

    std::cout << "Min: " << std::numeric_limits< Int16u_t >::min( ) << std::endl;

    std::cout << "Max: " << std::numeric_limits< Int16u_t >::max( ) << std::endl;

    std::cout << "Lowest: " << std::numeric_limits< Int16u_t >::lowest( ) << std::endl;

    for ( counter = 0; counter <= 5; counter++ )
    {
      i16u = counter;
      std::cout << "Unsigned " << counter << " -> Signed " << i16u << std::endl;
    }

    std::cout << "..." << std::endl;

    for ( counter = 32768 - 5; counter <= 32768 + 5; counter++ )
    {
      i16u = counter;
      std::cout << "Unsigned " << counter << " -> Signed " << i16u << std::endl;
    }

    std::cout << "..." << std::endl;

    for ( counter = 65535 - 5; counter <= 65535; counter++ )
    {
      i16u = counter;
      std::cout << "Unsigned " << counter << " -> Signed " << i16u << std::endl;
    }
  }

  {
    Int16_t x = 5;
    Int16_t y = 10;
    Int16_t z = x * y;

    std::cout << x << " * " << y << " = " << z << std::endl;
  }

  {
    std::cout << "Testing Uncertain 5 * 10" << std::endl;
    Int16u_t x = 5;
    Int16u_t y = 10;
    Int16u_t z = x * y;

    std::cout << x << " * " << y << " = " << z << std::endl;
  }

  return 0;
}
