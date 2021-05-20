#include "int8u_t.h"

// Non-member functions.

bool operator <( const int8_t &lhs_, const Int8u_t &rhs_ )
{
    return lhs_ < rhs_.GetEncodedValue( );
}


std::ostream &operator <<( std::ostream &s_, const Int8u_t &value_ )
{
  s_ << value_.ToString( );
  return s_;
}

// Member methods.

std::string Int8u_t::ToString( ) const
{
  std::stringstream ss;

  bool negative  = ( m_Value & 0x80 ) != 0;
  bool uncertain = ( m_Value & 1 ) != 0;
  int8_t value = m_Value >> 1;

  if ( negative && ( ( m_Value & 0x7f ) == 0 ) )
  {
    ss << "INF";
  }
  else
  {
    if ( negative && uncertain )
    {
      value = -( ~value ); // Negative of one's complement.
    }

    if ( negative && uncertain && value == 0 )
    {
      ss << "-";
    }

    ss << (int) value;

    if ( m_Value & 1 )
    {
        ss << "...";
    }
  }

  return ss.str( );
}


int8_t Int8u_t::GetEncodedValue( ) const
{
  return m_Value;
}


void Int8u_t::SetEncodedValue( const int8_t &value_ )
{
  m_Value = value_;
}


bool Int8u_t::operator ==( const Int8u_t &rhs_ ) const
{
  return m_Value == rhs_.m_Value;
}


