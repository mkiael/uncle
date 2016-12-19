#pragma once

namespace uncle {

enum class Command
{
   None,
   Quit,
   Input,
   Enter,
   DeleteCharInFrontOf,
   DeleteCharAfter,
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
