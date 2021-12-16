//
// Created by xdlol on 12/16/2021.
//

#include <iostream>
#include "HandleMode.h"
#include "ModeEnum.h"
#include <limits>
#include <fstream>
#include <chrono>
#include "Logic.h"
#include "UserInputs.h"

// Extract x length from password.
void HandleMode::init_mode()
{
  int mode = UserInputs::input_and_validate_mode();
  std::fstream read(UserInputs::input_file_path(), std::ios::in);
  std::fstream write(init_mode_name(mode) + ".txt", std::ios::app);

  if (read.is_open() && write.is_open()) {
    std::cout << "Editing has been started.\n";
    const auto start_timer = std::chrono::high_resolution_clock::now();
    switch (mode)
    {
      std::string shell;
      std::string edit;
      case REMOVE_SPECIAL_CHARACTERS:
          logic::remove_special_characters(shell, edit);
          write << edit << '\n';
        }

    }

  }
}

int HandleMode::get_length()
{
  int length = 0;
  std::cout << "Enter length\n";
  std::cin >> length;

  while (std::cin.fail())
  {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter length:\n";
    std::cin >> length;
  }
  return length;
}

std::string HandleMode::get_append()
{
  std::string append;
  while((std::cout << "Enter append or domain:\n") && std::cin >> append && std::empty(append)) {}
  return append;
}
// pass in the function here, make like 3 overloads ngl
void HandleMode::handle_writing(std::function <int(std::string_view, std::string&)> mode_func, std::fstream &read, std::fstream &write)
{
  std::string shell;

  while (read >> shell)
  {
    std::string edit;
    mode_func(shell, edit);
  }
}

std::string HandleMode::init_mode_name(const int mode)
{
  switch (mode)
  {
    case REMOVE_SPECIAL_CHARACTERS: return "remove_special_characters";
    case EMAILS_TO_USERNAME: return "emails_to_username";
    case USERNAMES_TO_EMAIL: return "usernames_to_email";
    case APPEND_TO_END: return "append_to_end";
    case APPEND_TO_USERNAME: return"append_to_username";
    case TO_LOWER_CASE: return "to_lower_case";
    case TO_UPPER_CASE: return "to_upper_case";
    case SWAP_PASS_CASE_FIRST_LETTER: return "swap_pass_case_first_letter";
    case SWAP_PASS_NUMBERS_TO_USER: return "swap_pass_numbers_to_user";
    case SWAP_USER_NUMBER_TO_PASS: return "swap_user_numbers_to_pass";
    case EXTRACT_X_FROM_PASS: return "extract_x_from_pass";
    case SWAP_NUMBERS: return "swap_numbers";
    default: return {};
  }
}

