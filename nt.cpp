#include "intX_t.h"
#include "intXu_t.h"

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

/////////////////////////
template< typename TYPE >
bool test_min( TYPE expectedValue_, const char *file_ = __FILE__, const int line_ = __LINE__ )
{
  TYPE value = std::numeric_limits< TYPE >::min( );
  bool okStatus = value == expectedValue_;
  std::string okString = okStatus ? "PASS" : "FAIL";
  TYPE res;

  std::cout << okString << ": test_min< " << res.Name( ) << " > => " << value;

  if ( !okStatus )
  {
    std::cout << " => Expected '" << expectedValue_ << "', but got '" << value << "' at " << file_ << "(" << line_ << ")";
  }

  std::cout << std::endl;

  return okStatus;
}

/////////////////////////
template< typename TYPE >
bool test_max( TYPE expectedValue_, const char *file_ = __FILE__, const int line_ = __LINE__ )
{
  constexpr uint64_t shift = TYPE::shift;
  constexpr uint64_t one = 1ull;
  constexpr uint64_t shifted = one << shift;
  std::cout << "shift = " << shift << ", shifted = " << shifted << std::endl;

  TYPE value = std::numeric_limits< TYPE >::max( );
  bool okStatus = value == expectedValue_;
  std::string okString = okStatus ? "PASS" : "FAIL";
  TYPE res;

  std::cout << okString << ": test_max< " << res.Name( ) << " > => " << value;

  if ( !okStatus )
  {
    std::cout << " => Expected '" << expectedValue_ << "', but got '" << value << "' at " << file_ << "(" << line_ << ")";
  }

  std::cout << std::endl;

  return okStatus;
}

#if 0
  std::cout << "Infinity: " << std::numeric_limits< TYPE >::infinity( ) << std::endl;

  // std::cout << "Mid: " << (uint64_t) mid << std::endl;

  std::cout << "Lowest: " << std::numeric_limits< TYPE >::lowest( ) << std::endl;
#endif


///////////
int main( )
{
  bool ok = true;

  // Int8_t
  {
    ok &= test_size<         Int8_t >( 8 );
    ok &= test_is_integer<   Int8_t >( true );
    ok &= test_is_signed<    Int8_t >( true );
    ok &= test_is_exact<     Int8_t >( true );
    ok &= test_is_modulo<    Int8_t >( true );
    ok &= test_has_infinity< Int8_t >( true );
    ok &= test_min<          Int8_t >( -127 );
    ok &= test_max<          Int8_t >(  127 );

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
    ok &= test_min<          Int16_t >( -32767 );
    ok &= test_max<          Int16_t >(  32767 );
  }

  // Int32_t
  {
    ok &= test_size<         Int32_t >( 32 );
    ok &= test_is_integer<   Int32_t >( true );
    ok &= test_is_signed<    Int32_t >( true );
    ok &= test_is_exact<     Int32_t >( true );
    ok &= test_is_modulo<    Int32_t >( true );
    ok &= test_has_infinity< Int32_t >( true );
    ok &= test_min<          Int32_t >( -2147483647 );
    ok &= test_max<          Int32_t >(  2147483647 );
  }

  // Int64_t
  {
    ok &= test_size<         Int64_t >( 64 );
    ok &= test_is_integer<   Int64_t >( true );
    ok &= test_is_signed<    Int64_t >( true );
    ok &= test_is_exact<     Int64_t >( true );
    ok &= test_is_modulo<    Int64_t >( true );
    ok &= test_has_infinity< Int64_t >( true );
    ok &= test_min<          Int64_t >( -9223372036854775807 );
    ok &= test_max<          Int64_t >(  9223372036854775807 );
  }

  // Int8u_t
  {
    ok &= test_size<         Int8u_t >( 8 );
    ok &= test_is_integer<   Int8u_t >( true );
    ok &= test_is_signed<    Int8u_t >( true );
    ok &= test_is_exact<     Int8u_t >( false );
    ok &= test_is_modulo<    Int8u_t >( false );
    ok &= test_has_infinity< Int8u_t >( true );
    ok &= test_min<          Int8u_t >( -63 );
    ok &= test_max<          Int8u_t >(  63 );

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
    ok &= test_min<          Int16u_t >( -16383 );
    ok &= test_max<          Int16u_t >(  16383 );

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
    ok &= test_min<          Int32u_t >( -1073741823 );
    ok &= test_max<          Int32u_t >(  1073741823 );
  }

  // Int64u_t
  {
    ok &= test_size<         Int64u_t >( 64 );
    ok &= test_is_integer<   Int64u_t >( true );
    ok &= test_is_signed<    Int64u_t >( true );
    ok &= test_is_exact<     Int64u_t >( false );
    ok &= test_is_modulo<    Int64u_t >( false );
    ok &= test_has_infinity< Int64u_t >( true );
#if 1
    ok &= test_min<          Int64u_t >( -9223372036854775807 ); // FIXME
    ok &= test_max<          Int64u_t >(  9223372036854775807 ); // FIXME
#endif
  }

  if ( !ok )
  {
    std::cout << "ERROR: One or more tests failed." << std::endl;
  }

  int exitStatus = !ok;  // Return if OK, else 1.

  return exitStatus;
}
