#pragma once

namespace uncle {

class Cursor
{
public:
   Cursor();

   ~Cursor();

   void set_column(unsigned int col);

   void set_row(unsigned int row);

   void add_to_column(unsigned int col);

   void add_to_row(unsigned int row);

   void remove_from_column(unsigned int col);

   void remove_from_row(unsigned int row);
   
   void increment_column();

   void increment_row();

   void decrement_column();

   void decrement_row();

   void reset();

   void reset_column();

   void reset_row();

   unsigned int row() const;

   unsigned int column() const;

private:
   unsigned int m_row;
   unsigned int m_column;
};

} // namespace uncle
