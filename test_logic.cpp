#include <iostream>

#include "ntest.hpp"
#include "term.hpp"

int main() {
  using namespace term;

  ntest::config::set_show_column_numbers(false);

  {
    auto const init_result = ntest::init();
    std::cout << init_result.num_files_removed << " residual files removed.\n";
    if (init_result.num_files_failed_to_remove)
      std::cout << init_result.num_files_failed_to_remove << " residual files failed to be removed.\n";
  }

  std::string what_str{}; // for ntest::assert_throws
  std::string temp{};
  temp.reserve(100);

  compute_font_effects_str(BOLD | UNDERLINE | FG_RED | BG_WHITE, temp);
  ntest::assert_cstr("1;4;31;47", temp.c_str());

  what_str = ntest::assert_throws<std::runtime_error>([&]() { compute_font_effects_str(FG_BLACK | FG_BRIGHT_BLACK, temp); });
  ntest::assert_cstr("multiple foreground colors set, only one can be set", what_str.c_str());

  what_str = ntest::assert_throws<std::runtime_error>([&]() { compute_font_effects_str(FG_BLACK | FG_BRIGHT_BLACK | FG_BRIGHT_RED, temp); });
  ntest::assert_cstr("multiple foreground colors set, only one can be set", what_str.c_str());

  what_str = ntest::assert_throws<std::runtime_error>([&]() { compute_font_effects_str(BG_BLACK | BG_BRIGHT_BLACK, temp); });
  ntest::assert_cstr("multiple background colors set, only one can be set", what_str.c_str());

  what_str = ntest::assert_throws<std::runtime_error>([&]() { compute_font_effects_str(BG_BLACK | BG_BRIGHT_BLACK | BG_BRIGHT_CYAN, temp); });
  ntest::assert_cstr("multiple background colors set, only one can be set", what_str.c_str());

  {
    auto const report_res = ntest::generate_report("term_report",
      [](ntest::assertion const &a, bool const passed) {
        if (!passed)
          std::cout << "!!! failed: " << a.loc.file_name() << ':' << a.loc.line() << '\n';
      }
    );

    std::cout << report_res.num_fails << " failed, " << report_res.num_passes << " passed.\n";
  }
}
