//
// Created by forac on 03/12/2021.
//

#ifndef EDITOR_C___LOGIC_H
#define EDITOR_C___LOGIC_H
#include <string>

class logic
{
    logic() = default;
public:

    ~logic() = default
    ;

    static void remove_special_characters(std::string
                                          & line
    );

    static void emails_to_username(std::string &line);

    static void usernames_to_email(std::string& line, const char* domain);

    static void append_to_end(std::string& line, const char* append);

    static void append_to_username(std::string& line, const char* append);

    static void to_lower_case(std::string &line);

    static void to_upper_case(std::string &line);

    static void swap_pass_case_first_letter(std::string &line);

    static void swap_pass_numbers_to_user(std::string &line);

    static void swap_user_numbers_to_pass(std::string& line);

    static void extract_x_from_pass(std::string &line, const int length);

    static void swap_numbers(std::string &line);

    static void delete_duplicates(const std::string& file_path);
};


#endif //EDITOR_C___LOGIC_H
