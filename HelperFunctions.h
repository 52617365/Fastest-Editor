#ifndef EDITOR_C___HELPERFUNCTIONS_H
#define EDITOR_C___HELPERFUNCTIONS_H

#include <string>

class helper_functions {
public:
  static bool has_numbers(std::string_view line);

  static std::string get_numbers(std::string_view combo);

  static std::string get_letters(std::string_view combo);
};

#endif // EDITOR_C___HELPERFUNCTIONS_H
