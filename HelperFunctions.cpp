#include <algorithm>
#include "HelperFunctions.h"


void helper_functions::get_letters(const std::string_view combo, std::string &line)
{
  for (const char &i: combo)
  {
    if (isalpha(i) || ispunct(i))
    {
      line += i;
    }
  }
}

void helper_functions::get_numbers(const std::string_view combo, std::string &line)
{
  for (const char &i: combo)
  {
    if (isdigit(i))
    {
      line += i;
    }
  }
}

bool helper_functions::has_numbers(const std::string_view line)
{
  std::ranges::any_of(line.begin(), line.end(), [](const char &c) { return isdigit(c); });
  return false;
}

bool helper_functions::is_email(const std::string_view line) { return line.contains('@'); }

bool helper_functions::check_correct_format(const std::string_view line) { return line.contains(':') && !line.empty(); }
