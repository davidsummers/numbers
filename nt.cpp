#include "intX_t.h"
#include "intXu_t.h"

#define TEST_ADD( type, lhs, rhs, exp ) test_add< type >( lhs, rhs, exp, __FILE__, __LINE__ )
#define TEST_SUB( type, lhs, rhs, exp ) test_sub< type >( lhs, rhs, exp, __FILE__, __LINE__ )
#define TEST_MUL( type, lhs, rhs, exp ) test_mul< type >( lhs, rhs, exp, __FILE__, __LINE__ )
#define TEST_DIV( type, lhs, rhs, exp ) test_div< type >( lhs, rhs, exp, __FILE__, __LINE__ )

#define TEST_SIZE(         type, exp ) test_size<         type >( exp, __FILE__, __LINE__ )
#define TEST_IS_INTEGER(   type, exp ) test_is_integer<   type >( exp, __FILE__, __LINE__ )
#define TEST_IS_SIGNED(    type, exp ) test_is_signed<    type >( exp, __FILE__, __LINE__ )
#define TEST_IS_EXACT(     type, exp ) test_is_exact<     type >( exp, __FILE__, __LINE__ )
#define TEST_IS_MODULO(    type, exp ) test_is_modulo<    type >( exp, __FILE__, __LINE__ )
#define TEST_HAS_INFINITY( type, exp ) test_has_infinity< type >( exp, __FILE__, __LINE__ )
#define TEST_MIN(          type, exp ) test_min<          type >( exp, __FILE__, __LINE__ )
#define TEST_MAX(          type, exp ) test_max<          type >( exp, __FILE__, __LINE__ )

/////////////////////////
template< typename TYPE >
bool test_add( const TYPE &lhs_, const TYPE &rhs_, const TYPE &exp_, const char *file_ = "", const int line_ = -1 )
{
  TYPE res = lhs_ + rhs_;

  std::stringstream ss;
  ss << res;

  bool okStatus = ss.str( ) == exp_.ToString( );
  std::string okString = okStatus ? "PASS" : "FAIL";

  std::cout << okString << ": test_add< " << res.Name( ) << " > => " << lhs_ << " + " << rhs_ << " = " << exp_;

  if ( !okStatus )
  {
    std::cout << " => Expected '" << exp_ << "', but got '" << res << "' at '" << file_ << "(" << line_ << ")";
  }

  std::cout << std::endl;

  return okStatus; // OK
}

/////////////////////////
template< typename TYPE >
bool test_sub( const TYPE &lhs_, const TYPE &rhs_, const TYPE &exp_, const char *file_ = "", const int line_ = -1 )
{
  TYPE res = lhs_ - rhs_;

  std::stringstream ss;
  ss << res;

  bool okStatus = ss.str( ) == exp_.ToString( );
  std::string okString = okStatus ? "PASS" : "FAIL";

  std::cout << okString << ": test_sub< " << res.Name( ) << " > => " << lhs_ << " - " << rhs_ << " = " << exp_;

  if ( !okStatus )
  {
    std::cout << " => Expected '" << exp_ << "', but got '" << res << "' at '" << file_ << "(" << line_ << ")";
  }

  std::cout << std::endl;

  return okStatus; // OK
}

/////////////////////////
template< typename TYPE >
bool test_mul( const TYPE &lhs_, const TYPE &rhs_, const TYPE &exp_, const char *file_ = "", const int line_ = -1 )
{
  TYPE res = lhs_ * rhs_;

  std::stringstream ss;
  ss << res;

  bool okStatus = ss.str( ) == exp_.ToString( );
  std::string okString = okStatus ? "PASS" : "FAIL";

  std::cout << okString << ": test_mul< " << res.Name( ) << " > => " << lhs_ << " * " << rhs_ << " = " << exp_;

  if ( !okStatus )
  {
    std::cout << " => Expected '" << exp_ << "', but got '" << res << "' at '" << file_ << "(" << line_ << ")";
  }

  std::cout << std::endl;

  return okStatus; // OK
}

/////////////////////////
template< typename TYPE >
bool test_div( const TYPE &lhs_, const TYPE &rhs_, const TYPE &exp_, const char *file_ = "", const int line_ = -1 )
{
  TYPE res = lhs_ / rhs_;

  std::stringstream ss;
  ss << res;

  bool okStatus = ss.str( ) == exp_.ToString( );
  std::string okString = okStatus ? "PASS" : "FAIL";

  std::cout << okString << ": test_div< " << res.Name( ) << " > => " << lhs_ << " / " << rhs_ << " = " << exp_;

  if ( !okStatus )
  {
    std::cout << " => Expected '" << exp_ << "', but got '" << res << "' at '" << file_ << "(" << line_ << ")";
  }

  std::cout << std::endl;

  return okStatus; // OK
}

/////////////////////////
template< typename TYPE >
bool test_size( const int expectedSize_, const char *file_ = "", const int line_ = -1 )
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
bool test_is_integer( bool expectedStatus_, const char *file_ = "", const int line_ = -1 )
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
bool test_is_signed( bool expectedStatus_, const char *file_ = "", const int line_ = -1 )
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
bool test_is_exact( bool expectedStatus_, const char *file_ = "", const int line_ = -1 )
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
bool test_is_modulo( bool expectedStatus_, const char *file_ = "", const int line_ = -1 )
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
bool test_has_infinity( bool expectedStatus_, const char *file_ = "", const int line_ = -1 )
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
bool test_min( TYPE expectedValue_, const char *file_ = "", const int line_ = -1 )
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
bool test_max( TYPE expectedValue_, const char *file_ = "", const int line_ = -1 )
{
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
    ok &= TEST_SIZE( Int8_t, 8 );
    ok &= TEST_IS_INTEGER(   Int8_t,  true );
    ok &= TEST_IS_SIGNED(    Int8_t, true );
    ok &= TEST_IS_EXACT(     Int8_t, true );
    ok &= TEST_IS_MODULO(    Int8_t, true );
    ok &= TEST_HAS_INFINITY( Int8_t, true );
    ok &= TEST_MIN(          Int8_t, -127 );
    ok &= TEST_MAX(          Int8_t,  127 );

    ok &= TEST_ADD( Int8_t,   -1,         1,      0         );
    ok &= TEST_ADD( Int8_t,  127,         1,    Int8_t::INF );
    ok &= TEST_ADD( Int8_t, Int8_t::INF,  1,   -127         );

    ok &= TEST_SUB( Int8_t, -127,         1,    Int8_t::INF );

    ok &= TEST_MUL( Int8_t,    5,        10,     50         );
    ok &= TEST_MUL( Int8_t,    7,        10,     70         );
  }

  // Int16_t
  {
    ok &= TEST_SIZE(         Int16_t,  16 );
    ok &= TEST_IS_INTEGER(   Int16_t,  true );
    ok &= TEST_IS_SIGNED(    Int16_t,  true );
    ok &= TEST_IS_EXACT(     Int16_t,  true );
    ok &= TEST_IS_MODULO(    Int16_t,  true );
    ok &= TEST_HAS_INFINITY( Int16_t,  true );
    ok &= TEST_MIN(          Int16_t,  -32767 );
    ok &= TEST_MAX(          Int16_t,   32767 );
  }

  // Int32_t
  {
    ok &= TEST_SIZE(         Int32_t, 32 );
    ok &= TEST_IS_INTEGER(   Int32_t, true );
    ok &= TEST_IS_SIGNED(    Int32_t, true );
    ok &= TEST_IS_EXACT(     Int32_t, true );
    ok &= TEST_IS_MODULO(    Int32_t, true );
    ok &= TEST_HAS_INFINITY( Int32_t, true );
    ok &= TEST_MIN(          Int32_t, -2147483647 );
    ok &= TEST_MAX(          Int32_t,  2147483647 );
  }

  // Int64_t
  {
    ok &= TEST_SIZE(         Int64_t, 64 );
    ok &= TEST_IS_INTEGER(   Int64_t, true );
    ok &= TEST_IS_SIGNED(    Int64_t, true );
    ok &= TEST_IS_EXACT(     Int64_t, true );
    ok &= TEST_IS_MODULO(    Int64_t, true );
    ok &= TEST_HAS_INFINITY( Int64_t, true );
    ok &= TEST_MIN(          Int64_t, -9223372036854775807 );
    ok &= TEST_MAX(          Int64_t,  9223372036854775807 );
  }

  // Int8u_t
  {
    ok &= TEST_SIZE(         Int8u_t, 8 );
    ok &= TEST_IS_INTEGER(   Int8u_t, true );
    ok &= TEST_IS_SIGNED(    Int8u_t, true );
    ok &= TEST_IS_EXACT(     Int8u_t, false );
    ok &= TEST_IS_MODULO(    Int8u_t, false );
    ok &= TEST_HAS_INFINITY( Int8u_t, true );
    ok &= TEST_MIN(          Int8u_t, -63 );
    ok &= TEST_MAX(          Int8u_t,  63 );

    ok &= TEST_MUL( Int8u_t,   "5"_i8u,    "10"_i8u,    "50"_i8u    );
    ok &= TEST_MUL( Int8u_t,   "7"_i8u,    "10"_i8u,    "63..."_i8u );
  }

  // Int16u_t
  {
    ok &= TEST_SIZE(         Int16u_t, 16 );
    ok &= TEST_IS_INTEGER(   Int16u_t, true );
    ok &= TEST_IS_SIGNED(    Int16u_t, true );
    ok &= TEST_IS_EXACT(     Int16u_t, false );
    ok &= TEST_IS_MODULO(    Int16u_t, false );
    ok &= TEST_HAS_INFINITY( Int16u_t, true );
    ok &= TEST_MIN(          Int16u_t, -16383 );
    ok &= TEST_MAX(          Int16u_t,  16383 );

    ok &= TEST_MUL( Int16u_t,   "5"_i16u,    "10"_i16u,    "50"_i16u    );
    ok &= TEST_MUL( Int16u_t,   "3"_i16u, "16000"_i16u, "16383..."_i16u );

    ok &= TEST_DIV( Int16u_t,  "63"_i16u,     "2"_i16u,    "31..."_i16u );
    ok &= TEST_DIV( Int16u_t,  "50"_i16u,    "10"_i16u,     "5"_i16u    );
  }

  // Int32u_t
  {
    ok &= TEST_SIZE(         Int32u_t, 32 );
    ok &= TEST_IS_INTEGER(   Int32u_t, true );
    ok &= TEST_IS_SIGNED(    Int32u_t, true );
    ok &= TEST_IS_EXACT(     Int32u_t, false );
    ok &= TEST_IS_MODULO(    Int32u_t, false );
    ok &= TEST_HAS_INFINITY( Int32u_t, true );
    ok &= TEST_MIN(          Int32u_t, -1073741823 );
    ok &= TEST_MAX(          Int32u_t,  1073741823 );
  }

  // Int64u_t
  {
    ok &= TEST_SIZE(         Int64u_t, 64 );
    ok &= TEST_IS_INTEGER(   Int64u_t, true );
    ok &= TEST_IS_SIGNED(    Int64u_t, true );
    ok &= TEST_IS_EXACT(     Int64u_t, false );
    ok &= TEST_IS_MODULO(    Int64u_t, false );
    ok &= TEST_HAS_INFINITY( Int64u_t, true );
    ok &= TEST_MIN(          Int64u_t, -4611686018427387903 );
    ok &= TEST_MAX(          Int64u_t,  4611686018427387903 );
  }

  if ( !ok )
  {
    std::cout << "ERROR: One or more tests failed." << std::endl;
  }

  int exitStatus = !ok;  // Return if OK, else 1.

  return exitStatus;
}
