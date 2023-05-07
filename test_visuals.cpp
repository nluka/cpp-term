#include <cstdio>

#include "term.hpp"

int main() {
  using namespace term;

  clear_screen();
  move_cursor_to(1, 1);

  printf(0, "no effects\n");
  printf(BOLD, "BOLD\n");
  printf(UNDERLINE, "UNDERLINE\n");
  printf(REVERSE_VIDEO, "REVERSE_VIDEO\n");
  std::printf("making sure style is reset to default...\n");
  printf(CROSSED_OUT, "CROSSED_OUT\n");
  printf(BOLD | UNDERLINE | CROSSED_OUT, "BOLD | UNDERLINE | CROSSED_OUT\n");
  // FG normal
  printf(FG_BLACK | BG_WHITE, "FG_BLACK | BG_WHITE\n");
  printf(FG_RED, "FG_RED\n");
  printf(FG_GREEN, "FG_GREEN\n");
  printf(FG_YELLOW, "FG_YELLOW\n");
  printf(FG_BLUE, "FG_BLUE\n");
  std::printf("making sure style is reset to default...\n");
  printf(FG_MAGENTA, "FG_MAGENTA\n");
  printf(FG_CYAN, "FG_CYAN\n");
  printf(FG_WHITE, "FG_WHITE\n");
  // FG bright
  printf(FG_BRIGHT_BLACK, "FG_BRIGHT_BLACK\n");
  printf(FG_BRIGHT_RED, "FG_BRIGHT_RED\n");
  printf(FG_BRIGHT_GREEN, "FG_BRIGHT_GREEN\n");
  std::printf("making sure style is reset to default...\n");
  printf(FG_BRIGHT_YELLOW, "FG_BRIGHT_YELLOW\n");
  printf(FG_BRIGHT_BLUE, "FG_BRIGHT_BLUE\n");
  printf(FG_BRIGHT_MAGENTA, "FG_BRIGHT_MAGENTA\n");
  printf(FG_BRIGHT_CYAN, "FG_BRIGHT_CYAN\n");
  printf(FG_BRIGHT_WHITE, "FG_BRIGHT_WHITE\n");
  // BG regular
  printf(BG_BLACK, "BG_BLACK\n");
  printf(BG_RED, "BG_RED\n");
  printf(BG_GREEN, "BG_GREEN\n");
  printf(BG_YELLOW, "BG_YELLOW\n");
  std::printf("making sure style is reset to default...\n");
  printf(BG_BLUE, "BG_BLUE\n");
  printf(BG_MAGENTA, "BG_MAGENTA\n");
  printf(BG_CYAN, "BG_CYAN\n");
  printf(BG_WHITE | FG_BLACK, "BG_WHITE | FG_BLACK\n");
  // BG bright
  printf(BG_BRIGHT_BLACK, "BG_BRIGHT_BLACK\n");
  printf(BG_BRIGHT_RED, "BG_BRIGHT_RED\n");
  printf(BG_BRIGHT_GREEN, "BG_BRIGHT_GREEN\n");
  printf(BG_BRIGHT_YELLOW, "BG_BRIGHT_YELLOW\n");
  printf(BG_BRIGHT_BLUE, "BG_BRIGHT_BLUE\n");
  printf(BG_BRIGHT_MAGENTA, "BG_BRIGHT_MAGENTA\n");
  std::printf("making sure style is reset to default...\n");
  printf(BG_BRIGHT_CYAN, "BG_BRIGHT_CYAN\n");
  printf(BG_BRIGHT_WHITE, "BG_BRIGHT_WHITE\n");
  // other
  printf(BG_BRIGHT_CYAN | FG_RED, "BG_BRIGHT_CYAN | FG_RED\n");
  set_font_effects(CROSSED_OUT | BG_RED | FG_BLACK);
  std::printf("line 1 of CROSSED_OUT | BG_RED | FG_BLACK\n");
  std::printf("line 2 of CROSSED_OUT | BG_RED | FG_BLACK\n");
  std::printf("line 3 of CROSSED_OUT | BG_RED | FG_BLACK\n");
  reset_font_effects();
  std::printf("making sure style is reset to default...\n");

  std::printf("Good text, bad text\n");
  move_cursor_up(1);
  std::printf("Good text");
  clear_to_end_of_line();
  std::printf("\n");

  std::printf("Sample text");
  clear_current_line();

  std::printf("[ ] [ ] [ ]\n");
  std::printf("[ ] [ ] [ ]\n");
  std::printf("[ ] [ ] [ ]\n");
  move_cursor_up(3);
  move_cursor_right(9);
  std::printf("X");
  move_cursor_down(2);
  move_cursor_left(9);
  std::printf("X");
  move_cursor_up(1);
  move_cursor_right(3);
  save_cursor_position();
  move_cursor_down(1);
  move_cursor_right(4);
  std::printf("X");
  restore_cursor_position();
  std::printf("X");
  move_cursor_down(2);

  move_cursor_left(999);

  return 0;
}
