//
// Created by forac on 04/12/2021.
//

#ifndef EDITOR_C___HELPERFUNCTIONS_H
#define EDITOR_C___HELPERFUNCTIONS_H

#include <string>

class helper_functions
{
public:
    static bool check_correct_format(std::string_view line);

    static bool is_email(std::string_view line);

    static bool has_numbers(std::string_view line);

    static void get_numbers(std::string_view combo, std::string &line);

    static void get_letters(std::string_view combo, std::string &line);
};


#endif //EDITOR_C___HELPERFUNCTIONS_H
