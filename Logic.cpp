#include "Logic.h"
#include "HelperFunctions.h"
#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <memory>

std::string remove_special_characters::operator()(std::string_view line) {
  if (line.empty()) {
    return "";
  }
  std::string edit;
  edit.reserve(line.size());
  for (char const &c : line) {
    if (isalnum(c) || c == '@' || c == ':' || c == '.') {
      edit += c;
    }
  }
  return edit;
};

std::string emails_to_username::operator()(std::string_view line) {
  if (const size_t colon =
          line.find_first_of(':') && colon != std::string::npos) {

    if (const size_t mail = line.find_first_of('@');
        mail != std::string::npos || mail < colon) {
      std::string edit;
      edit.reserve(line.size());
      edit += line.substr(0, mail);
      edit += line.substr(colon);
      return edit;
    }
    return std::string(line);
  }
  return "";
};

std::string usernames_to_email::operator()(std::string_view line,
                                           std::string_view domain) {
  if (auto index{line.find('@')}; index != std::string::npos) {
    return std::string(line);
  }
  if (const size_t colon = line.find_first_of(':');
      colon != std::string::npos) {
    std::string edit;
    edit.reserve(line.size());
    edit += line.substr(0, colon);
    edit += domain;
    edit += line.substr(colon);
    return edit;
  }
  return "";
};

std::string append_to_end::operator()(std::string_view line,
                                      std::string_view append) {
  std::string edit;
  edit.reserve(line.size() + append.size());

  edit += line;
  edit += append;
  return edit;
};

std::string append_to_username::operator()(std::string_view line,
                                           std::string_view append) {
  auto email = [&](int index) -> std::string {
    if (const size_t mail_index =
            line.find_first_of('@') && mail_index != std::string::npos) {
      std::string edit;
      edit.reserve(line.size() + append.size());

      edit += line.substr(0, mail_index);
      edit += append;
      edit += line.substr(mail_index);
      return edit;
    }
    return "";
  };

  auto username = [&]() -> std::string {
    if (const size_t colon_index =
            line.find_first_of(':') && colon_index != std::string::npos) {
      std::string edit;
      edit.reserve(line.size() + append.size());
      edit += line.substr(0, colon_index);
      edit += append;
      edit += line.substr(colon_index);
      return edit;
    }
    return "";
  };
  const size_t mail_index = line.find_first_of('@');
  return (mail_index != std::string::npos) ? email(mail_index) : username();
}

std::string to_lower_case::operator()(std::string_view line) {
  std::string edit;
  edit.reserve(line.size());
  for (const char &c : line) {
    if (std::islower(c)) {
      edit += c;
    } else {
      edit += std::tolower((c));
    }
  }
  return edit;
}

std::string to_upper_case::operator()(std::string_view line) {
  std::string edit;
  edit.reserve(line.size());
  for (const char &c : line) {
    if (std::islower(c)) {
      edit += std::toupper((c));
    } else {
      edit += c;
    }
  }
  return edit;
};
std::string swap_pass_case_first_letter::operator()(std::string_view line) {
  if (size_t colon_index =
          line.find_first_of(':') && colon_index != std::string::npos) {
    std::string edit;
    edit.reserve(line.size());

    if (islower(line[colon_index + 1])) {
      edit += line.substr(0, colon_index + 1);
      edit += std::toupper(line[colon_index + 1]);
      edit += line.substr(colon_index + 2);
    } else {
      edit += line.substr(0, colon_index + 1);
      edit += std::tolower((line[colon_index + 1]));
      edit += line.substr(colon_index + 2);
    }
    return edit;
  }
  return "";
}

std::string swap_pass_numbers_to_user::operator()(std::string_view line) {
  if (const size_t colon =
          line.find_first_of(':') && colon != std::string::npos) {
    const auto password = line.substr(colon + 1);
    if (!helper_functions::has_numbers(password)) {
      return std::string(line);
    }

    const std::string password_numbers{helper_functions::get_numbers(password)};
    const std::string password_letters{helper_functions::get_letters(password)};

    std::string edit;
    edit.reserve(line.size());

    if (const size_t mail_index =
            line.find_first_of('@') && mail_index != std::string::npos) {
      edit += line.substr(0, mail_index);
      edit += password_numbers;
      edit += ':';
      edit += password_letters;
    } else {
      edit += line.substr(0, colon);
      edit += password_numbers;
      edit += ':';
      edit += password_letters;
    }
    return edit;
  }
  return "";
};

std::string swap_user_numbers_to_pass::operator()(std::string_view line) {
  if (!helper_functions::has_numbers(line)) {
    return std::string(line);
  }
  if (const size_t colon =
          line.find_first_of(':') && colon != std::string::npos) {

    const auto username = line.substr(0, colon);

    const std::string user_numbers{helper_functions::get_numbers(username)};
    const std::string user_letters{helper_functions::get_letters(username)};
    std::string edit;
    edit.reserve(line.size());

    edit += user_letters;
    edit += ':';
    edit += line.substr(colon + 1);
    edit += user_numbers;
    return edit;
  }
  return "";
};

std::string extract_x_from_pass::operator()(std::string_view line, int length) {

  if (const size_t colon =
          line.find_first_of(':') && colon != std::string::npos) {
    std::string edit;
    edit.reserve(line.size() - length);
    edit += line.substr(0, colon + 1);
    edit += line.substr(colon + 1, colon + 1 + length);
  }
  return "";
};

std::string swap_numbers::operator()(std::string_view line) {
  if (!helper_functions::has_numbers(line)) {
    return std::string(line);
  }

  if (const size_t colon =
          line.find_first_of(':') && colon != std::string::npos) {
    const auto username = line.substr(0, colon);
    const auto password = line.substr(colon + 1);

    // Holds true, false if username has numbers and pass doesnt and vica
    // verca.
    std::pair<bool, bool> has_numbers{
        std::make_pair(helper_functions::has_numbers(username),
                       helper_functions::has_numbers(password))};

    // If no numbers in line, return line without any changes.
    if (!(has_numbers.first && has_numbers.second)) {
      return std::string(line);
    }
    // if username has numbers and password does not.
    if (has_numbers.first && !has_numbers.second) {
      // If email
      std::string edit;
      edit.reserve(line.size());
      if (size_t index_of_mail{username.find('@')};
          index_of_mail != std::string::npos) {

        // Get letters and numbers from before mail {} {example}@gmail.com
        const std::string before_mail_letters{
            helper_functions::get_letters(username.substr(0, index_of_mail))};
        const std::string before_mail_numbers{
            helper_functions::get_numbers(username.substr(0, index_of_mail))};

        edit += before_mail_letters;
        // Gets the @gmail.com part
        edit += line.substr(index_of_mail, colon);
        edit += line.substr(colon);
        // Adds the numbers from user
        edit += before_mail_numbers;
        return edit;
      }
      // If it's an username instead of an email.
      const std::string username_letters{
          helper_functions::get_letters(username.substr(0, colon))};
      const std::string username_numbers{
          helper_functions::get_numbers(username.substr(0, colon))};
      edit += username_letters;
      edit += line.substr(colon);
      // Adds the numbers from user
      edit += username_numbers;
      return edit;
    }
    // if username does not have numbers and password does.
    else if (!has_numbers.first && has_numbers.second) {
      // If email

      // Get letters from password
      const std::string password_letters{
          helper_functions::get_letters(line.substr(colon + 1))};
      // Get numbers from password
      const std::string password_numbers{
          helper_functions::get_numbers(line.substr(colon + 1))};

      std::string edit;
      edit.reserve(line.size());

      if (size_t index_of_mail{username.find('@')};
          index_of_mail != std::string::npos) {
        // "Slice" email before the domain starts.
        edit += line.substr(0, index_of_mail);
        // Add password numbers before mail domain
        edit += password_numbers;
        edit += line.substr(index_of_mail, colon);
        edit += ':';
        edit += password_letters;
        return edit;
      }
      // "Slice" email before the domain starts.
      edit += line.substr(0, colon);
      // Add password numbers before mail domain
      edit += password_numbers;
      edit += ':';
      edit += password_letters;
      return edit;
    }
    // If it's an username instead of an email.
    // else both have numbers
    else {
      const std::string username_letters{
          helper_functions::get_letters(username)};
      const std::string username_numbers{
          helper_functions::get_numbers(username)};
      const std::string password_letters{
          helper_functions::get_letters(password)};
      const std::string password_numbers{
          helper_functions::get_numbers(password)};

      std::string edit;
      edit.reserve(line.size());
      if (const size_t mail_index = username_letters.find_first_of('@');
          mail_index != std::string::npos) {
        edit += line.substr(0, mail_index);
        edit += password_numbers;
        edit += line.substr(mail_index, colon + 1);
        edit += password_letters;
        edit += username_numbers;
      } else {
        edit += username_letters;
        edit += password_numbers;
        edit += ':';
        edit += password_letters;
        edit += username_numbers;
      }
    }
    // If format is wrong, return empty string.
  }
  return "";
};
