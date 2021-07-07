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
template< typename type >
type Str2Num( const std::string &str_ ) // can be called with a 'char*' argument as well
{
    int64_t num;
    std::istringstream( str_ ) >> num;
    return num;
}

/////////////////////////
template< typename TYPE >
bool test_add( const std::string &lhs_, const std::string &rhs_, const std::string &res_ )
{
  TYPE lhs = Str2Num< typename TYPE::Otype >( lhs_ );
  TYPE rhs = Str2Num< typename TYPE::Otype >( rhs_ );
  TYPE res = lhs + rhs;

  std::stringstream ss;
  ss << res;

  bool okStatus = ss.str( ) == res_;
  std::string okString = okStatus ? "PASS" : "FAIL";

  std::cout << okString << ": test_add< " << res.Name( ) << " > => " << lhs_ << " + " << rhs_ << " = " << res_ << std::endl;

  if ( !okStatus )
  {
    std::cout << "FAIL: Expected '" << res_ << "', but got " << res << "'" << std::endl;
  }

  return okStatus; // OK
}

/////////////////////////
template< typename TYPE >
bool test_sub( const std::string &lhs_, const std::string &rhs_, const std::string &res_ )
{
  TYPE lhs = Str2Num< typename TYPE::Otype >( lhs_ );
  TYPE rhs = Str2Num< typename TYPE::Otype >( rhs_ );
  TYPE res = lhs - rhs;

  std::stringstream ss;
  ss << res;

  bool okStatus = ss.str( ) == res_;
  std::string okString = okStatus ? "PASS" : "FAIL";

  std::cout << okString << ": test_sub< " << res.Name( ) << " > => " << lhs_ << " - " << rhs_ << " = " << res_ << std::endl;

  if ( !okStatus )
  {
    std::cout << "FAIL: Expected '" << res_ << "', but got " << res << "'" << std::endl;
  }

  return okStatus; // OK
}

/////////////////////////
template< typename TYPE >
bool test_mul( const std::string &lhs_, const std::string &rhs_, const std::string &res_ )
{
  TYPE lhs = Str2Num< typename TYPE::Otype >( lhs_ );
  TYPE rhs = Str2Num< typename TYPE::Otype >( rhs_ );
  TYPE res = lhs * rhs;

  std::stringstream ss;
  ss << res;

  bool okStatus = ss.str( ) == res_;
  std::string okString = okStatus ? "PASS" : "FAIL";

  std::cout << okString << ": test_mul< " << res.Name( ) << " > => " << lhs_ << " * " << rhs_ << " = " << res_ << std::endl;

  if ( !okStatus )
  {
    std::cout << "FAIL: Expected '" << res_ << "', but got " << res << "'" << std::endl;
  }

  return okStatus; // OK
}

/////////////////////////
template< typename TYPE >
bool test_div( const std::string &lhs_, const std::string &rhs_, const std::string &res_ )
{
  TYPE lhs = Str2Num< typename TYPE::Otype >( lhs_ );
  TYPE rhs = Str2Num< typename TYPE::Otype >( rhs_ );
  TYPE res = lhs / rhs;

  std::stringstream ss;
  ss << res;

  bool okStatus = ss.str( ) == res_;
  std::string okString = okStatus ? "PASS" : "FAIL";

  std::cout << okString << ": test_div< " << res.Name( ) << " > => " << lhs_ << " / " << rhs_ << " = " << res_ << std::endl;

  if ( !okStatus )
  {
    std::cout << "FAIL: Expected '" << res_ << "', but got " << res << "'" << std::endl;
  }

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

  std::cout << "===============" << std::endl;
  std::cout << "= Now do math =" << std::endl;
  std::cout << "===============" << std::endl;

  bool ok = true;

  ok &= test_add< Int8_t   >(   "-1",    "1",     "0"    );
  ok &= test_add< Int8_t   >(  "127",    "1",    "INF"   );
  // ok &= test_add< Int8_t   >(  "INF",    "1",   "-127"   ); // FIXME

  ok &= test_sub< Int8_t   >( "-127",    "1",    "INF"   );

  ok &= test_mul< Int8_t   >(   "5",    "10",    "50"    );
  ok &= test_mul< Int8_t   >(   "7",    "10",    "70"    );

  ok &= test_mul< Int8u_t  >(   "5",    "10",    "50"    );
  ok &= test_mul< Int8u_t  >(   "7",    "10",    "63..." );

  ok &= test_mul< Int16u_t >(   "5",    "10",    "50"    );
  ok &= test_mul< Int16u_t >(   "3", "16000", "16383..." );

  ok &= test_div< Int16u_t >(  "63",     "2",    "31..." );
  ok &= test_div< Int16u_t >(  "50",    "10",     "5"    );

  if ( !ok )
  {
    std::cout << "ERROR: One or more tests failed." << std::endl;
  }

  int exitStatus = !ok;  // Return if OK, else 1.

  return exitStatus;
}
