#include <cstdio>

#include "term.hpp"

int main() {
  using namespace term::color;

  printf(fore::WHITE | back::BLACK, "WHITE | BLACK"); printf("\n");
  printf(fore::RED | back::WHITE, "RED | WHITE"); printf("\n");
  printf(fore::GREEN | back::CYAN, "GREEN | CYAN"); printf("\n");
  printf(fore::YELLOW | back::MAGENTA, "YELLOW | MAGENTA"); printf("\n");
  printf(fore::BLUE | back::GREEN, "BLUE | GREEN"); printf("\n");
  printf(fore::MAGENTA | back::BLUE, "MAGENTA | BLUE"); printf("\n");
  printf(fore::CYAN | back::YELLOW, "CYAN | YELLOW"); printf("\n");
  printf(fore::GRAY | back::RED, "GRAY | RED"); printf("\n");
  printf(fore::GREY | back::RED, "GREY | RED"); printf("\n");
  printf(fore::LIGHT_RED | back::BLACK, "LIGHT_RED | BLACK"); printf("\n");
  printf(fore::LIGHT_GREEN | back::BLACK, "LIGHT_GREEN | BLACK"); printf("\n");
  printf(fore::LIGHT_YELLOW | back::BLACK, "LIGHT_YELLOW | BLACK"); printf("\n");
  printf(fore::LIGHT_BLUE | back::BLACK, "LIGHT_BLUE | BLACK"); printf("\n");
  printf(fore::LIGHT_MAGENTA | back::BLACK, "LIGHT_MAGENTA | BLACK"); printf("\n");
  printf(fore::LIGHT_CYAN | back::BLACK, "LIGHT_CYAN | BLACK"); printf("\n");

  printf("\n");

  printf("Good text, bad text\n");
  term::cursor::move_up(1);
  printf("Good text");
  term::clear_to_end_of_line();

  std::printf("\n\n");
  std::printf("Sample text");
  term::clear_curr_line();

  printf("[ ] [ ] [ ]\n");
  printf("[ ] [ ] [ ]\n");
  printf("[ ] [ ] [ ]\n");
  term::cursor::move_up(3);
  term::cursor::move_right(9);
  printf("X");
  term::cursor::move_down(2);
  term::cursor::move_left(9);
  printf("X");
  term::cursor::move_up(1);
  term::cursor::move_right(3);
  term::cursor::save_pos();
  term::cursor::move_down(1);
  term::cursor::move_right(4);
  printf("X");
  term::cursor::restore_pos();
  printf("X");
  term::cursor::move_down(2);
  printf("\n");

  printf("Text to be cleared");
  term::clear_curr_line();
  printf("\n");

  return 0;
}
