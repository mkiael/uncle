// std
#include <iostream>
#include <vector>

// ncurses
#include <ncurses.h>

// uncle
#include "uncle/buffer.h"
#include "uncle/commands.h"

using namespace uncle;

void print_buffer(const Buffer& buffer)
{
   int row = 0;
   for (const auto& str : buffer.raw_buffer())
   {
      mvaddstr(row, 0, str.c_str());
      ++row;
   }

   move(buffer.cursor().row(), buffer.cursor().column());

   refresh();
}

int main(int argc, char** argv)
{
   initscr();
   noecho();
   cbreak();
   keypad(stdscr, TRUE);
   
   int ch;

   Buffer buffer;

   while (1)
   {
      ch = getch();

      switch (ch)
      {
      case 10: // Enter
         buffer.handle_command(Command::Enter);
         break;
      case 8: // Backsapce
      case 127: // Delete
         buffer.handle_command(Command::Delete);
         break;
       case KEY_UP:
         buffer.handle_command(Command::CursorUp);
         break;
      case KEY_DOWN:
         buffer.handle_command(Command::CursorDown);
         break;
      case KEY_LEFT:
         buffer.handle_command(Command::CursorLeft);
         break;
      case KEY_RIGHT:
         buffer.handle_command(Command::CursorRight);
         break;
     default:
         buffer.add_character(static_cast<char>(ch));
         break;
      }

      clear();
      print_buffer(buffer);
   }

   getch();
   endwin();

   return 0;
}
