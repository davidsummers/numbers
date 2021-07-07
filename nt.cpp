#include "intX_t.h"
#include "intXu_t.h"

/////////////////////////
template< typename TYPE >
void test( )
{
  using utype = typename TYPE::Utype;
  uint64_t midType = (utype) std::numeric_limits< TYPE >::max( );
  uint64_t mid = ( midType ) + 1;
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

  std::cout << "Is Signed: " << std::numeric_limits< TYPE >::is_signed << std::endl;

  std::cout << "Is Exact: " << std::numeric_limits< TYPE >::is_exact << std::endl;

  std::cout << "Modulo: " << std::numeric_limits< TYPE >::is_modulo << std::endl;

  std::cout << "Has Infinity: " << std::numeric_limits< TYPE >::has_infinity << std::endl;

  std::cout << "Infinity: " << std::numeric_limits< TYPE >::infinity( ) << std::endl;

  std::cout << "Min: " << std::numeric_limits< TYPE >::min( ) << std::endl;

  // std::cout << "Mid: " << (uint64_t) mid << std::endl;

  std::cout << "Max: " << std::numeric_limits< TYPE >::max( ) << std::endl;

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

/////////////////////////
template< typename TYPE >
bool test_add( const TYPE &lhs_, const TYPE &rhs_, const TYPE &res_, const char *file_ = __FILE__, const int line_ = __LINE__ )
{
  TYPE res = lhs_ + rhs_;

  std::stringstream ss;
  ss << res;

  bool okStatus = ss.str( ) == res_.ToString( );
  std::string okString = okStatus ? "PASS" : "FAIL";

  std::cout << okString << ": test_add< " << res.Name( ) << " > => " << lhs_ << " + " << rhs_ << " = " << res_;

  if ( !okStatus )
  {
    std::cout << " => Expected '" << res_ << "', but got '" << res << "' at '" << file_ << "(" << line_ << ")";
  }

  std::cout << std::endl;

  return okStatus; // OK
}

/////////////////////////
template< typename TYPE >
bool test_sub( const TYPE &lhs_, const TYPE &rhs_, const TYPE &res_, const char *file_ = __FILE__, const int line_ = __LINE__ )
{
  TYPE res = lhs_ - rhs_;

  std::stringstream ss;
  ss << res;

  bool okStatus = ss.str( ) == res_.ToString( );
  std::string okString = okStatus ? "PASS" : "FAIL";

  std::cout << okString << ": test_sub< " << res.Name( ) << " > => " << lhs_ << " - " << rhs_ << " = " << res_;

  if ( !okStatus )
  {
    std::cout << " => Expected '" << res_ << "', but got '" << res << "' at '" << file_ << "(" << line_ << ")";
  }

  std::cout << std::endl;

  return okStatus; // OK
}

/////////////////////////
template< typename TYPE >
bool test_mul( const TYPE &lhs_, const TYPE &rhs_, const TYPE &res_, const char *file_ = __FILE__, const int line_ = __LINE__ )
{
  TYPE res = lhs_ * rhs_;

  std::stringstream ss;
  ss << res;

  bool okStatus = ss.str( ) == res_.ToString( );
  std::string okString = okStatus ? "PASS" : "FAIL";

  std::cout << okString << ": test_mul< " << res.Name( ) << " > => " << lhs_ << " * " << rhs_ << " = " << res_;

  if ( !okStatus )
  {
    std::cout << " => Expected '" << res_ << "', but got '" << res << "' at '" << file_ << "(" << line_ << ")";
  }

  std::cout << std::endl;

  return okStatus; // OK
}

/////////////////////////
template< typename TYPE >
bool test_div( const TYPE &lhs_, const TYPE &rhs_, const TYPE &res_, const char *file_ = __FILE__, const int line_ = __LINE__ )
{
  TYPE res = lhs_ / rhs_;

  std::stringstream ss;
  ss << res;

  bool okStatus = ss.str( ) == res_.ToString( );
  std::string okString = okStatus ? "PASS" : "FAIL";

  std::cout << okString << ": test_div< " << res.Name( ) << " > => " << lhs_ << " / " << rhs_ << " = " << res_;

  if ( !okStatus )
  {
    std::cout << " => Expected '" << res_ << "', but got '" << res << "' at '" << file_ << "(" << line_ << ")";
  }

  std::cout << std::endl;

  return okStatus; // OK
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

  //////////////
  std::cout << "===============" << std::endl;
  std::cout << "= Now do math =" << std::endl;
  std::cout << "===============" << std::endl;

  bool ok = true;

  ok &= test_add< Int8_t   >(   -1,          1,      0         );
  ok &= test_add< Int8_t   >(  127,          1,    Int8_t::INF );
  ok &= test_add< Int8_t   >(  Int8_t::INF,  1,   -127         );

  ok &= test_sub< Int8_t   >( -127,          1,    Int8_t::INF );

  ok &= test_mul< Int8_t   >(   5,    10,    50    );
  ok &= test_mul< Int8_t   >(   7,    10,    70    );

  ok &= test_mul< Int8u_t  >(   "5"_i8u,    "10"_i8u,    "50"_i8u    );
  ok &= test_mul< Int8u_t  >(   "7"_i8u,    "10"_i8u,    "63..."_i8u );

  ok &= test_mul< Int16u_t >(   "5"_i16u,    "10"_i16u,    "50"_i16u    );
  ok &= test_mul< Int16u_t >(   "3"_i16u, "16000"_i16u, "16383..."_i16u );

  ok &= test_div< Int16u_t >(  "63"_i16u,     "2"_i16u,    "31..."_i16u );
  ok &= test_div< Int16u_t >(  "50"_i16u,    "10"_i16u,     "5"_i16u    );

  if ( !ok )
  {
    std::cout << "ERROR: One or more tests failed." << std::endl;
  }

  int exitStatus = !ok;  // Return if OK, else 1.

  return exitStatus;
}
