#include "intX_t.h"
#include "intXu_t.h"

/////////////////////////
template< typename TYPE >
void test( )
{
  using utype = typename TYPE::Utype;
  utype midType = (utype) std::numeric_limits< TYPE >::max( );
  utype mid = midType + 1;

  if ( ! std::numeric_limits< TYPE >::is_exact )
  {
    mid = mid * 2;
  }

  uint64_t min = ( (utype) std::numeric_limits< TYPE >::max( ) ) * 2;

  if ( ! std::numeric_limits< TYPE >::is_exact )
  {
    min = min * 2;
  }

  uint64_t counter = 0;

  TYPE myVal;

  std::cout << "======" << std::endl;
  std::cout << myVal.Name( ) << std::endl;
  std::cout << "======" << std::endl;

  std::cout << "Size (bits): " << sizeof( TYPE ) * 8 << std::endl;

  std::cout << "Is Integer: " << std::numeric_limits< TYPE >::is_integer << std::endl;

  std::cout << "Is Signed: " << std::numeric_limits< TYPE >::is_signed << std::endl;

  std::cout << "Is Exact: " << std::numeric_limits< TYPE >::is_exact << std::endl;

  std::cout << "Modulo: " << std::numeric_limits< TYPE >::is_modulo << std::endl;

  std::cout << "Has Infinity: " << std::numeric_limits< TYPE >::has_infinity << std::endl;

  std::cout << "Infinity: " << std::numeric_limits< TYPE >::infinity( ) << std::endl;

  std::cout << "Min:    " << std::numeric_limits< TYPE >::min( ) << std::endl;

  // std::cout << "Mid: " << (uint64_t) mid << std::endl;

  std::cout << "Max:     " << std::numeric_limits< TYPE >::max( ) << std::endl;

  std::cout << "Lowest: " << std::numeric_limits< TYPE >::lowest( ) << std::endl;

  for ( counter = 0; counter <= 5; counter++ )
  {
    myVal.SetEncodedValue( counter );
    std::cout << "Unsigned " << (uint64_t) counter << " -> Signed " << myVal << std::endl;
  }

  std::cout << "..." << std::endl;

  for ( counter = mid - 5; counter <= mid + 5; counter++ )
  {
    myVal.SetEncodedValue( counter );
    std::cout << "Unsigned " << (uint64_t) counter << " -> Signed " << myVal << std::endl;
  }

  std::cout << "..." << std::endl;

  myVal.SetEncodedValue( min - 3 );
  counter = myVal.GetEncodedValue( );

  for ( int i = 0; i < 5; i++ )
  {
    myVal.SetEncodedValue( counter );
    std::cout << "Unsigned " << (uint64_t) counter << " -> Signed " << myVal << std::endl;
    counter++;
  }
}

///////////
int main( )
{
  test< Int8_t >( );

  test< Int16_t >( );

  test< Int32_t >( );

  test< Int64_t >( );

  test< Int8u_t >( );

  test< Int16u_t >( );

  test< Int32u_t >( );

  test< Int64u_t >( );

  return 0;
}
