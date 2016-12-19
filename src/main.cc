// std
#include <iostream>
#include <vector>

// ncurses
#include <ncurses.h>

// uncle
#include "uncle/buffer.h"
#include "uncle/commands.h"
#include "uncle/input_handler.h"

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
   raw();
   keypad(stdscr, TRUE);

   InputHandler input_handler;
   Buffer buffer;

   while (1)
   {
      auto cmd = input_handler.read_input();

      if (cmd == Command::Quit)
      {
         break;
      }
      else if (cmd == Command::Input)
      {
         buffer.add_character(input_handler.get_character());
      }
      else
      {
         buffer.handle_command(cmd);
      }

      clear();
      print_buffer(buffer);
   }

   endwin();

   return 0;
}
