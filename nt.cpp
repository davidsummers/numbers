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

  std::cout << "Is Integer: " << std::numeric_limits< TYPE >::is_integer << std::endl;

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

/////////////////////////
template< typename TYPE >
bool test_size( const int expectedSize_, const char *file_ = __FILE__, const int line_ = __LINE__ )
{
  int size = sizeof( TYPE ) * 8;
  bool okStatus = size == expectedSize_;
  std::string okString = okStatus ? "PASS" : "FAIL";
  TYPE res;

  std::cout << okString << ": test_size< " << res.Name( ) << " > => " << size;

  if ( !okStatus )
  {
    std::cout << " => Expected '" << expectedSize_ << "', but got '" << size << "' at " << file_ << "(" << line_ << ")";
  }

  std::cout << std::endl;

  return okStatus;
}

/////////////////////////
template< typename TYPE >
bool test_is_integer( bool expectedStatus_, const char *file_ = __FILE__, const int line_ = __LINE__ )
{
  bool status = std::numeric_limits< TYPE >::is_integer;
  bool okStatus = status == expectedStatus_;
  std::string okString = okStatus ? "PASS" : "FAIL";
  TYPE res;

  std::cout << okString << ": test_is_integer< " << res.Name( ) << " > => " << status;

  if ( !okStatus )
  {
    std::cout << " => Expected '" << expectedStatus_ << "', but got '" << status << "' at " << file_ << "(" << line_ << ")";
  }

  std::cout << std::endl;

  return okStatus;
}

/////////////////////////
template< typename TYPE >
bool test_is_signed( bool expectedStatus_, const char *file_ = __FILE__, const int line_ = __LINE__ )
{
  bool status = std::numeric_limits< TYPE >::is_signed;
  bool okStatus = status == expectedStatus_;
  std::string okString = okStatus ? "PASS" : "FAIL";
  TYPE res;

  std::cout << okString << ": test_is_signed< " << res.Name( ) << " > => " << status;

  if ( !okStatus )
  {
    std::cout << " => Expected '" << expectedStatus_ << "', but got '" << status << "' at " << file_ << "(" << line_ << ")";
  }

  std::cout << std::endl;

  return okStatus;
}

/////////////////////////
template< typename TYPE >
bool test_is_exact( bool expectedStatus_, const char *file_ = __FILE__, const int line_ = __LINE__ )
{
  bool status = std::numeric_limits< TYPE >::is_exact;
  bool okStatus = status == expectedStatus_;
  std::string okString = okStatus ? "PASS" : "FAIL";
  TYPE res;

  std::cout << okString << ": test_is_exact< " << res.Name( ) << " > => " << status;

  if ( !okStatus )
  {
    std::cout << " => Expected '" << expectedStatus_ << "', but got '" << status << "' at " << file_ << "(" << line_ << ")";
  }

  std::cout << std::endl;

  return okStatus;
}

/////////////////////////
template< typename TYPE >
bool test_is_modulo( bool expectedStatus_, const char *file_ = __FILE__, const int line_ = __LINE__ )
{
  bool status = std::numeric_limits< TYPE >::is_modulo;
  bool okStatus = status == expectedStatus_;
  std::string okString = okStatus ? "PASS" : "FAIL";
  TYPE res;

  std::cout << okString << ": test_is_modulo< " << res.Name( ) << " > => " << status;

  if ( !okStatus )
  {
    std::cout << " => Expected '" << expectedStatus_ << "', but got '" << status << "' at " << file_ << "(" << line_ << ")";
  }

  std::cout << std::endl;

  return okStatus;
}

/////////////////////////
template< typename TYPE >
bool test_has_infinity( bool expectedStatus_, const char *file_ = __FILE__, const int line_ = __LINE__ )
{
  bool status = std::numeric_limits< TYPE >::has_infinity;
  bool okStatus = status == expectedStatus_;
  std::string okString = okStatus ? "PASS" : "FAIL";
  TYPE res;

  std::cout << okString << ": test_has_infinity< " << res.Name( ) << " > => " << status;

  if ( !okStatus )
  {
    std::cout << " => Expected '" << expectedStatus_ << "', but got '" << status << "' at " << file_ << "(" << line_ << ")";
  }

  std::cout << std::endl;

  return okStatus;
}

#if 0
  std::cout << "Infinity: " << std::numeric_limits< TYPE >::infinity( ) << std::endl;

  std::cout << "Min: " << std::numeric_limits< TYPE >::min( ) << std::endl;

  // std::cout << "Mid: " << (uint64_t) mid << std::endl;

  std::cout << "Max: " << std::numeric_limits< TYPE >::max( ) << std::endl;

  std::cout << "Lowest: " << std::numeric_limits< TYPE >::lowest( ) << std::endl;
#endif

/////////////
void Usage( )
{
  std::cout << "Usage: nt demo | tests" << std::endl;
}

///////////
int main( int argc_, char **argv_ )
{
  if ( argc_ < 2 || argc_ > 2 )
  {
    Usage( );
    return 1;
  }

  std::string cmd = argv_[ 1 ];

  if ( cmd != "demo" && cmd != "tests" )
  {
    Usage( );
    return 1;
  }

  if ( cmd == "demo" )
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

  bool ok = true;

  // Int8_t
  {
    ok &= test_size<         Int8_t >( 8 );
    ok &= test_is_integer<   Int8_t >( true );
    ok &= test_is_signed<    Int8_t >( true );
    ok &= test_is_exact<     Int8_t >( true );
    ok &= test_is_modulo<    Int8_t >( true );
    ok &= test_has_infinity< Int8_t >( true );

    ok &= test_add< Int8_t   >(   -1,          1,      0         );
    ok &= test_add< Int8_t   >(  127,          1,    Int8_t::INF );
    ok &= test_add< Int8_t   >(  Int8_t::INF,  1,   -127         );

    ok &= test_sub< Int8_t   >( -127,          1,    Int8_t::INF );

    ok &= test_mul< Int8_t   >(   5,    10,    50    );
    ok &= test_mul< Int8_t   >(   7,    10,    70    );
  }

  // Int16_t
  {
    ok &= test_size<         Int16_t >( 16 );
    ok &= test_is_integer<   Int16_t >( true );
    ok &= test_is_signed<    Int16_t >( true );
    ok &= test_is_exact<     Int16_t >( true );
    ok &= test_is_modulo<    Int16_t >( true );
    ok &= test_has_infinity< Int16_t >( true );
  }

  // Int32_t
  {
    ok &= test_size<         Int32_t >( 32 );
    ok &= test_is_integer<   Int32_t >( true );
    ok &= test_is_signed<    Int32_t >( true );
    ok &= test_is_exact<     Int32_t >( true );
    ok &= test_is_modulo<    Int32_t >( true );
    ok &= test_has_infinity< Int32_t >( true );
  }

  // Int64_t
  {
    ok &= test_size<         Int64_t >( 64 );
    ok &= test_is_integer<   Int64_t >( true );
    ok &= test_is_signed<    Int64_t >( true );
    ok &= test_is_exact<     Int64_t >( true );
    ok &= test_is_modulo<    Int64_t >( true );
    ok &= test_has_infinity< Int64_t >( true );
  }

  // Int8u_t
  {
    ok &= test_size<         Int8u_t >( 8 );
    ok &= test_is_integer<   Int8u_t >( true );
    ok &= test_is_signed<    Int8u_t >( true );
    ok &= test_is_exact<     Int8u_t >( false );
    ok &= test_is_modulo<    Int8u_t >( false );
    ok &= test_has_infinity< Int8u_t >( true );

    ok &= test_mul< Int8u_t  >(   "5"_i8u,    "10"_i8u,    "50"_i8u    );
    ok &= test_mul< Int8u_t  >(   "7"_i8u,    "10"_i8u,    "63..."_i8u );
  }

  // Int16u_t
  {
    ok &= test_size<         Int16u_t >( 16 );
    ok &= test_is_integer<   Int16u_t >( true );
    ok &= test_is_signed<    Int16u_t >( true );
    ok &= test_is_exact<     Int16u_t >( false );
    ok &= test_is_modulo<    Int16u_t >( false );
    ok &= test_has_infinity< Int16u_t >( true );

    ok &= test_mul< Int16u_t >(   "5"_i16u,    "10"_i16u,    "50"_i16u    );
    ok &= test_mul< Int16u_t >(   "3"_i16u, "16000"_i16u, "16383..."_i16u );

    ok &= test_div< Int16u_t >(  "63"_i16u,     "2"_i16u,    "31..."_i16u );
    ok &= test_div< Int16u_t >(  "50"_i16u,    "10"_i16u,     "5"_i16u    );
  }

  // Int32u_t
  {
    ok &= test_size<         Int32u_t >( 32 );
    ok &= test_is_integer<   Int32u_t >( true );
    ok &= test_is_signed<    Int32u_t >( true );
    ok &= test_is_exact<     Int32u_t >( false );
    ok &= test_is_modulo<    Int32u_t >( false );
    ok &= test_has_infinity< Int32u_t >( true );
  }

  // Int64u_t
  {
    ok &= test_size<         Int64u_t >( 64 );
    ok &= test_is_integer<   Int64u_t >( true );
    ok &= test_is_signed<    Int64u_t >( true );
    ok &= test_is_exact<     Int64u_t >( false );
    ok &= test_is_modulo<    Int64u_t >( false );
    ok &= test_has_infinity< Int64u_t >( true );
  }

  if ( !ok )
  {
    std::cout << "ERROR: One or more tests failed." << std::endl;
  }

  int exitStatus = !ok;  // Return if OK, else 1.

  return exitStatus;
}
