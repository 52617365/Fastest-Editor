//
// Created by forac on 04/12/2021.
//

#ifndef EDITOR_C___HELPERFUNCTIONS_H
#define EDITOR_C___HELPERFUNCTIONS_H

#include <string>
#include <fstream>

class helper_functions
{
public:

    static bool check_correct_format(const std::string_view line)
    {
        return line.contains(':') && !line.empty();
    }

    static bool is_email(const std::string_view line)
    {
        return line.contains('@');
    }

    static bool has_numbers(const std::string_view line)
    {
        return line.find_first_not_of("0123456789") != std::string::npos;
    }

    static void get_numbers(const std::string_view combo, std::string &line)
    {
        for (const char &i: combo)
        {
            if (isdigit(i))
            {
                line += i;
            }
            else
            {}
        }
    }

    static void get_letters(const std::string_view combo, std::string &line)
    {
        for (const char &i: combo)
        {
            if (isalpha(i) || ispunct(i))
            {
                line += i;
            }
            else
            {}
        }
    }
};


#endif //EDITOR_C___HELPERFUNCTIONS_H
