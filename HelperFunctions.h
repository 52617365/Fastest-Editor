//
// Created by forac on 04/12/2021.
//

#ifndef EDITOR_C___HELPERFUNCTIONS_H
#define EDITOR_C___HELPERFUNCTIONS_H

#include <string>
#include <algorithm>

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
        std::ranges::any_of(line.begin(), line.end(), [](const char &c)
        {
            return isdigit(c);
        });
        return false;
    }

    static void get_numbers(const std::string_view combo, std::string &line)
    {
        for (const char &i: combo)
        {
            if (isdigit(i))
            {
                line += i;
            }
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
        }
    }
};


#endif //EDITOR_C___HELPERFUNCTIONS_H
