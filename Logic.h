#ifndef EDITOR_C___Logic_H
#define EDITOR_C___Logic_H
#include <string>

class remove_special_characters {
public:
  std::string operator()(std::string_view line);
};
class emails_to_username {
public:
  std::string operator()(std::string_view line);
};
class usernames_to_email {
public:
  std::string operator()(std::string_view line, std::string_view domain);
};
class append_to_end {
public:
  std::string operator()(std::string_view line, std::string_view append);
};
class append_to_username {
public:
  std::string operator()(std::string_view line, std::string_view append);
};
class to_lower_case {
public:
  std::string operator()(std::string_view line);
};
class to_upper_case {
public:
  std::string operator()(std::string_view line);
};
class swap_pass_case_first_letter {
public:
  std::string operator()(std::string_view line);
};
class swap_pass_numbers_to_user {
public:
  std::string operator()(std::string_view line);
};
class swap_user_numbers_to_pass {
public:
  std::string operator()(std::string_view line);
};
class extract_x_from_pass {
public:
  std::string operator()(std::string_view line, int length);
};
class swap_numbers {
public:
  std::string operator()(std::string_view line);
};

class delete_duplicates {
public:
  std::string operator()(std::string_view line);
};

#endif // EDITOR_C___Logic_H
