#pragma once

namespace uncle {

enum class Command
{
   None,
   Quit,
   Input,
   Enter,
   Delete,
   CursorUp,
   CursorDown,
   CursorLeft,
   CursorRight,
   GotoBeginingOfLine,
   GotoEndOfLine,
   GotoBeginningOfBuffer,
   GotoEndOfBuffer,
};

} // namespace uncle
