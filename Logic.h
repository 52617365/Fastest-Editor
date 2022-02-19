#ifndef EDITOR_C___Logic_H
#define EDITOR_C___Logic_H
#include <string>
class Logic {
  // Just to treat everything the same.
};

class remove_special_characters : Logic {
public:
  std::string operator()(std::string_view line);
};
class emails_to_username : Logic {
public:
  std::string operator()(std::string_view line);
};
class usernames_to_email : Logic {
public:
  std::string operator()(std::string_view line, std::string_view domain);
};
class append_to_end : Logic {
public:
  std::string operator()(std::string_view line, std::string_view append);
};
class append_to_username : Logic {
public:
  std::string operator()(std::string_view line, std::string_view append);
};
class to_lower_case : Logic {
public:
  std::string operator()(std::string_view line);
};
class to_upper_case : Logic {
public:
  std::string operator()(std::string_view line);
};
class swap_pass_case_first_letter : Logic {
public:
  std::string operator()(std::string_view line);
};
class swap_pass_numbers_to_user : Logic {
public:
  std::string operator()(std::string_view line);
};
class swap_user_numbers_to_pass : Logic {
public:
  std::string operator()(std::string_view line);
};
class extract_x_from_pass : Logic {
public:
  std::string operator()(std::string_view line, int length);
};
class swap_numbers : Logic {
public:
  std::string operator()(std::string_view line);
};

class delete_duplicates : Logic {
public:
  std::string operator()(std::string_view line);
};

#endif // EDITOR_C___Logic_H
