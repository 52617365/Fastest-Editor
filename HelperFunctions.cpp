#include "HelperFunctions.h"
#include <algorithm>

std::string helper_functions::get_letters(const std::string_view combo) {
  std::string line;
  line.reserve(combo.size() / 4);
  for (const char i : combo) {
    if (isalpha(i) || ispunct(i)) {
      line += i;
    }
  }
  return line;
}

std::string helper_functions::get_numbers(const std::string_view combo) {
  std::string line;
  line.reserve(combo.size());
  for (const char &i : combo) {
    if (isdigit(i)) {
      line += i;
    }
  }
  return line;
}

bool helper_functions::has_numbers(const std::string_view line) {
  for (const auto x : line) {
    if (isdigit(x)) {
      return true;
    }
  }
  return false;
}
