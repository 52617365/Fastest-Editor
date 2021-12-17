#ifndef EDITOR_C___LOGIC_H
#define EDITOR_C___LOGIC_H

#include <string>

class logic
{

public:
    logic() = default;

    ~logic() = default;

    void remove_special_characters(std::string_view line, std::string &shell);

    void emails_to_username(std::string_view line, std::string &shell);

    void usernames_to_email(std::string_view line, std::string_view domain,
                            std::string &shell);

    void append_to_end(std::string_view line, std::string_view append,
                       std::string &shell);

    void append_to_username(std::string_view line, std::string_view append,
                            std::string &shell);

    void to_lower_case(std::string_view line, std::string &shell);

    void to_upper_case(std::string_view line, std::string &shell);

    void swap_pass_case_first_letter(std::string_view line,
                                     std::string &shell);

    void swap_pass_numbers_to_user(std::string_view line,
                                   std::string &shell);

    void swap_user_numbers_to_pass(std::string_view line,
                                   std::string &shell);

    void extract_x_from_pass(std::string_view line, int length,
                             std::string &shell);

    void swap_numbers(std::string_view line, std::string &shell);

    static void delete_duplicates(const std::string &file_path);

};

#endif // EDITOR_C___LOGIC_H
