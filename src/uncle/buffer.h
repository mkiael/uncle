#pragma once

// std
#include <string>
#include <vector>

// uncle
#include "uncle/cursor.h"

namespace uncle {

enum class Command;

class Buffer
{
public:
   using RawBuffer = std::vector<std::string>;
   
   Buffer();
   
   ~Buffer();

   const RawBuffer& raw_buffer() const;

   const Cursor& cursor() const;

   void handle_command(Command cmd);

   void add_character(char c);

private:

   bool is_cursor_at_first_column() const;

   bool is_cursor_at_end_of_line() const;

   bool is_cursor_at_first_row() const;

   bool is_cursor_at_last_row() const;

   std::string& line();

   const std::string& line() const;

   RawBuffer m_buffer;

   Cursor m_cursor;
};

} // namespace uncle
