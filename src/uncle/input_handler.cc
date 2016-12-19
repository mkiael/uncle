#include "uncle/input_handler.h"

// ncurses
#include <ncurses.h>

// uncle
#include "uncle/commands.h"

// TBR
#include <fstream>

namespace uncle {

InputHandler::InputHandler()
: m_input(0)
{
}

InputHandler::~InputHandler()
{
}

Command InputHandler::read_input()
{
   m_input = getch();

   if (m_input >= 0)
   {
      std::fstream f("log.txt", std::fstream::app);
      f << m_input << "\n";
      f.close();
   }

   switch (m_input)
   {
   case 8:
   case 127:
   case KEY_BACKSPACE:
      return Command::DeleteCharInFrontOf;
   case KEY_DC:
      return Command::DeleteCharAfter;
   case 10: // Enter
   case KEY_ENTER:
      return Command::Enter;
   case 17: // ctrl+q
      return Command::Quit;
    case KEY_UP:
      return Command::CursorUp;
   case KEY_DOWN:
      return Command::CursorDown;
   case KEY_LEFT:
      return Command::CursorLeft;
   case KEY_RIGHT:
      return Command::CursorRight;
  default:
      if (m_input > 31 && m_input < 127)
      {
         return Command::Input;
      }
      else
      {
         return Command::None;
      }
   }
}

char InputHandler::get_character() const
{
   return static_cast<char>(m_input);
}

} // namespace uncle
