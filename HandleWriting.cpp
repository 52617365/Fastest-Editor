#include "HandleWriting.h"
#include "Logic.h"
#include "ModeEnum.h"
#include "UserInputs.h"
#include <chrono>
#include <functional>
#include <iostream>
#include <map>

void HandleWriting::operator()(int mode) {
  switch (mode) {
  case REMOVE_SPECIAL_CHARACTERS: {
    remove_special_characters edit;
    handle_writing(edit, mode);
    break;
  }

  case EMAILS_TO_USERNAME: {
    emails_to_username edit;
    handle_writing(edit, mode);
    break;
  }

  case USERNAMES_TO_EMAIL: {
    usernames_to_email edit;
    handle_writing_domain(edit, mode);
    break;
  }

  case APPEND_TO_END: {
    append_to_end edit;
    handle_writing_append(edit, mode);
    break;
  }

  case APPEND_TO_USERNAME: {
    append_to_username edit;
    handle_writing_append(edit, mode);
    break;
  }

  case TO_LOWER_CASE: {
    to_lower_case edit;
    handle_writing(edit, mode);
    break;
  }

  case TO_UPPER_CASE: {
    to_upper_case edit;
    handle_writing(edit, mode);
    break;
  }

  case SWAP_PASS_CASE_FIRST_LETTER: {
    swap_pass_case_first_letter edit;
    handle_writing(edit, mode);
    break;
  }

  case SWAP_PASS_NUMBERS_TO_USER: {
    swap_pass_numbers_to_user edit;
    handle_writing(edit, mode);
    break;
  }

  case SWAP_USER_NUMBER_TO_PASS: {
    swap_user_numbers_to_pass edit;
    handle_writing(edit, mode);
    break;
  }

  case EXTRACT_X_FROM_PASS: {
    extract_x_from_pass edit;
    handle_writing_extract(edit, mode);
    break;
  }

  case SWAP_NUMBERS: {
    swap_numbers edit;
    handle_writing(edit, mode);
    break;
  }
  }
}

template <class T>
void HandleWriting::handle_writing_domain(T &func, int mode) {

  std::vector<std::string> domains{
      "@gmail.com",     "@hotmail.com", "@live.com", "@protonmail.com",
      "@hotmail.co.uk", "@live.co.uk",  "@mail.com"};
  std::cout << "Editing has been started.\n";
  const auto start = std::chrono::high_resolution_clock::now();

  int domain_index = 0;
  std::string combo;

  while (read >> combo) {
    if (domain_index > domains.size()) {
      domain_index = 0;
    }
    std::string edit = func(combo, domains[domain_index]);
    if (!edit.empty()) {
      write << edit << '\n';
    }
    ++domain_index;
  }
}

template <class T> void HandleWriting::handle_writing(T &func, int mode) {
  std::cout << "Editing has been started.\n";
  const auto start = std::chrono::high_resolution_clock::now();
  std::string combo;
  while (read >> combo) {
    std::string edit = func(combo);
    if (!edit.empty()) {
      write << edit << '\n';
    }
  }
}

template <class T>
void HandleWriting::handle_writing_append(T &func, int mode) {
  std::cout << "Editing has been started.\n";
  const auto start = std::chrono::high_resolution_clock::now();
  std::string append = UserInputs::get_append();
  std::string combo;
  while (read >> combo) {
    std::string edit = func(combo, append);
    if (!edit.empty()) {
      write << edit << '\n';
    }
  }
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed_seconds = end - start;
  std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
  std::cin.get();
}

template <class T>
void HandleWriting::handle_writing_extract(T &func, int mode) {
  int length = UserInputs::get_length();
  std::cout << "Editing has been started.\n";
  const auto start = std::chrono::high_resolution_clock::now();
  std::string combo;
  while (read >> combo) {
    std::string edit = func(combo, length);
    if (!edit.empty()) {
      write << edit << '\n';
    }
  }
  auto end = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed_seconds = end - start;
  std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
  std::cin.get();
}
