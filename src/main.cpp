#include <iostream>
#include <ncurses.h>

int main(int argc, char** argv)
{
   initscr();
   while (true)
   {
      if (auto c = getch() != -1)
      {
         std::cout << "Got: " << c << "\n";
      }
   }

   return 0;
}
