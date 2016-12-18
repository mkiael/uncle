#include "uncle/cursor.h"

namespace uncle {

Cursor::Cursor()
: m_row(0)
, m_column(0)
{
}

Cursor::~Cursor()
{
}

void Cursor::set_column(unsigned int col)
{
   m_column = col;
}

void Cursor::set_row(unsigned int row)
{
   m_row = row;
}

void Cursor::add_to_column(unsigned int col)
{
   m_column += col;
}

void Cursor::add_to_row(unsigned int row)
{
   m_row += row;
}

void Cursor::remove_from_column(unsigned int col)
{
   m_column -= col;
}

void Cursor::remove_from_row(unsigned int row)
{
   m_row -= row;
}

void Cursor::increment_column()
{
   ++m_column;
}

void Cursor::increment_row()
{
   ++m_row;
}

void Cursor::decrement_column()
{
   --m_column;
}

void Cursor::decrement_row()
{
   --m_row;
}

void Cursor::reset()
{
   m_column = 0;
   m_row = 0;
}

void Cursor::reset_column()
{
   m_column = 0;
}

void Cursor::reset_row()
{
   m_row = 0;
}

unsigned int Cursor::column() const
{
   return m_column;
}

unsigned int Cursor::row() const
{
   return m_row;
}

} // namespace uncle
