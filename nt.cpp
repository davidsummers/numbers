#include "intX_t.h"
#include "intXu_t.h"

template< typename TYPE >
void test( const std::string &nameOfType_, uint64_t min_, uint64_t mid_, uint64_t max_ )
{
  uint64_t counter = 0;

  TYPE myVal;

  std::cout << nameOfType_ << std::endl;
  std::cout << "======" << std::endl;

  std::cout << "Is Exact: " << std::numeric_limits< TYPE >::is_exact << std::endl;

  std::cout << "Has Infinity: " << std::numeric_limits< TYPE >::has_infinity << std::endl;

  std::cout << "Infinity: " << std::numeric_limits< TYPE >::infinity( ) << std::endl;

  std::cout << "Min: " << std::numeric_limits< TYPE >::min( ) << std::endl;

  std::cout << "Max: " << std::numeric_limits< TYPE >::max( ) << std::endl;

  std::cout << "Lowest: " << std::numeric_limits< TYPE >::lowest( ) << std::endl;

  for ( counter = min_; counter <= 5; counter++ )
  {
    myVal.SetEncodedValue( counter );
    std::cout << "Unsigned " << counter << " -> Signed " << myVal << std::endl;
  }

  std::cout << "..." << std::endl;

  for ( counter = mid_ - 5; counter <= mid_ + 5; counter++ )
  {
    myVal.SetEncodedValue( counter );
    std::cout << "Unsigned " << counter << " -> Signed " << myVal << std::endl;
  }

  std::cout << "..." << std::endl;

  for ( counter = max_ - 5; counter <= max_; counter++ )
  {
    myVal.SetEncodedValue( counter );
    std::cout << "Unsigned " << counter << " -> Signed " << myVal << std::endl;
  }
}

int main( )
{
  test< Int8_t >( "Int8_t", 0, 128, 255 );

  test< Int16_t >( "Int16_t", 0, 32768, 65535 );

  test< Int8u_t >( "Int8_t", 0, 128, 255 );

  test< Int16u_t >( "Int16u_t", 0, 32768, 65535 );

  {
    Int16_t x = 5;
    Int16_t y = 10;
    Int16_t z = x * y;

    std::cout << "Int16_t: " << x << " * " << y << " = " << z << std::endl;
  }

  {
    Int16u_t x = 5;
    Int16u_t y = 10;
    Int16u_t z = x * y;

    std::cout << "Int16u_t: " << x << " * " << y << " = " << z << std::endl;
  }

  {
    Int16u_t x = 10;
    Int16u_t y = 30000;
    Int16u_t z = x * y;

    std::cout << "Int16u_t: (10)=" << x << " * (30000)=" << y << " = " << z << std::endl;
  }

  {
    Int16u_t x = 63;
    Int16u_t y = 2;
    Int16u_t z = x / y;

    std::cout << "Int16u_t: (63)=" << x << " / (2)=" << y << " = " << z << std::endl;
  }

  {
    Int16u_t x = 50;
    Int16u_t y = 10;
    Int16u_t z = x / y;

    std::cout << "Int16u_t: (50)=" << x << " / (10)=" << y << " = " << z << std::endl;
  }

  return 0;
}
