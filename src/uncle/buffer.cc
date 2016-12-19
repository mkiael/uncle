#include "uncle/buffer.h"
#include "uncle/commands.h"

namespace uncle {

Buffer::Buffer()
: m_buffer()
, m_cursor()
{
   m_buffer.push_back("");
}

Buffer::~Buffer()
{
}

const Buffer::RawBuffer& Buffer::raw_buffer() const
{
   return m_buffer;
}

const Cursor& Buffer::cursor() const
{
   return m_cursor;
}

void Buffer::handle_command(Command cmd)
{
   switch (cmd)
   {
   case Command::Enter:
      {
         auto line_size = line().size();
       
         // Copy the remaining characters on the current line
         auto str = line().substr(m_cursor.column(), line_size);
         
         auto it = begin(line());
         
         // Remove the characters that was just copied
         line().erase(it + m_cursor.column(), it + line_size);
         
         m_cursor.increment_row();
         
         // Add copied characters to the new line
         m_buffer.insert(begin(m_buffer) + m_cursor.row(), str);
         
         m_cursor.reset_column();
      }
      break;
   case Command::DeleteCharInFrontOf:
      if (!is_cursor_at_first_column())
      {
         m_cursor.decrement_column();

         auto it = begin(line());
         
         line().erase(it + m_cursor.column());
      }
      else if (!is_cursor_at_first_row())
      {
         m_cursor.decrement_row();
         m_cursor.set_column(line().size());
      }
      break;
   case Command::DeleteCharAfter:
      if (m_cursor.column() < line().size())
      {
         line().erase(begin(line()) + m_cursor.column());
      }
      break;
   case Command::CursorUp:
      if (!is_cursor_at_first_row())
      {
         m_cursor.decrement_row();
         m_cursor.set_column(line().size());
      }
      break;
   case Command::CursorDown:
      if (!is_cursor_at_last_row())
      {
         m_cursor.increment_row();
         m_cursor.set_column(line().size());
      }
      break;
   case Command::CursorLeft:
      if (!is_cursor_at_first_column())
      {
         m_cursor.decrement_column();
      }
      break;
   case Command::CursorRight:
      if (!is_cursor_at_end_of_line())
      {
         m_cursor.increment_column();
      }
      break;
   default:
      break;
   }
}

void Buffer::add_character(char c)
{
   line() += c;
   m_cursor.increment_column();
}

bool Buffer::is_cursor_at_first_column() const
{
   return m_cursor.column() == 0;
}

bool Buffer::is_cursor_at_end_of_line() const
{
   return m_cursor.column() == line().size();
}

bool Buffer::is_cursor_at_first_row() const
{
   return m_cursor.row() == 0;
}

bool Buffer::is_cursor_at_last_row() const
{
   return m_cursor.row() == m_buffer.size();
}

std::string& Buffer::line()
{
   return m_buffer[m_cursor.row()];
}

const std::string& Buffer::line() const
{
   return m_buffer[m_cursor.row()];
}

} // namespace uncle
