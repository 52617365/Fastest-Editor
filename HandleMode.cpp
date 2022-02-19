#include "HandleMode.h"
#include "HandleWriting.h"
#include "ModeEnum.h"
#include "UserInputs.h"
#include <iostream>
#include <map>
#include <utility>

std::pair<int, std::string> HandleMode::init_mode() {
  std::map<int, std::string> names{
      {REMOVE_SPECIAL_CHARACTERS, "remove_special_characters"},
      {EMAILS_TO_USERNAME, "emails_to_username"},
      {USERNAMES_TO_EMAIL, "usernames_to_email"},
      {APPEND_TO_END, "append_to_end"},
      {APPEND_TO_USERNAME, "append_to_username"},
      {TO_LOWER_CASE, "to_lower_case"},
      {TO_UPPER_CASE, "to_upper_case"},
      {SWAP_PASS_CASE_FIRST_LETTER, "swap_pass_case_first_letter"},
      {SWAP_PASS_NUMBERS_TO_USER, "swap_pass_numbers_to_user"},
      {SWAP_USER_NUMBER_TO_PASS, "swap_user_numbers_to_pass"},
      {EXTRACT_X_FROM_PASS, "extract_x_from_pass"},
      {SWAP_NUMBERS, "swap_numbers"},
  };
  return std::make_pair(mode, names[mode]);
}
