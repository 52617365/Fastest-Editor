#include "HandleWriting.h"
#include "Logic.h"
#include "ModeEnum.h"
#include "UserInputs.h"
#include <chrono>
#include <functional>
#include <iostream>
#include <map>

template <class T> void HandleWriting<T>::start_writing() {
  std::string shell;
  std::string edit;

  std::map<int, T> names{
      {REMOVE_SPECIAL_CHARACTERS, handle_writing(remove_special_characters())},
      {EMAILS_TO_USERNAME, handle_writing(emails_to_username())},
      {USERNAMES_TO_EMAIL, handle_writing(usernames_to_email())},
      {APPEND_TO_END, handle_writing(append_to_end())},
      {APPEND_TO_USERNAME, handle_writing(append_to_username())},
      {TO_LOWER_CASE, handle_writing(to_lower_case())},
      {TO_UPPER_CASE, handle_writing(to_upper_case())},
      {SWAP_PASS_CASE_FIRST_LETTER,
       handle_writing(swap_pass_case_first_letter())},
      {SWAP_PASS_NUMBERS_TO_USER, handle_writing(swap_pass_numbers_to_user())},
      {SWAP_USER_NUMBER_TO_PASS, handle_writing(swap_user_numbers_to_pass())},
      {EXTRACT_X_FROM_PASS, handle_writing(extract_x_from_pass())},
      {SWAP_NUMBERS, handle_writing(swap_numbers())},
  };
}
template <class T> void HandleWriting<T>::handle_writing(T &func, int mode) {
  std::cout << "Editing has been started.\n";
  const auto start = std::chrono::high_resolution_clock::now();
  if (mode == APPEND_TO_END || mode == APPEND_TO_USERNAME) {
    std::string append = UserInputs::get_append();
    std::string combo;
    while (read >> combo) {
      std::string edit = func(combo, append);
      if (!edit.empty()) {
        write << edit << '\n';
      }
    }
  } else if (mode == EXTRACT_X_FROM_PASS) {
    int length = UserInputs::get_length();
    std::string combo;
    while (read >> combo) {
      std::string edit = func(combo, length);
      if (!edit.empty()) {
        write << edit << '\n';
      }
    }
  } else {
    std::string combo;
    while (read >> combo) {
      std::string edit = func(combo);
      if (!edit.empty()) {
        write << edit << '\n';
      }
    }
  }

  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed_seconds = end - start;
  std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
  std::cin.get();
}
