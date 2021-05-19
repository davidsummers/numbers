#include "int8_t.h"


std::ostream &operator <<( std::ostream &s_, const Int8_t &value_ )
{
  s_ << value_.ToString( );
  return s_;
}


std::string Int8_t::ToString( ) const
{
  std::stringstream ss;

  if ( ( ( m_Value & 0x80 ) != 0 ) && ( ( m_Value & 0x7f ) == 0 ) )
  {
    ss << "INF";
  }
  else
  {
    ss << (int) m_Value;
  }

  return ss.str( );
}

