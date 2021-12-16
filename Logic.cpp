//
// Created by forac on 03/12/2021.
//


#include <algorithm>
#include <chrono>
#include "HelperFunctions.h"
#include <memory>
#include <fstream>
#include <iostream>
#include "Logic.h"


void logic::remove_special_characters(std::string_view line, std::string &shell)
{
    auto edit = [&]
    {
        // Removes all characters from string that are not a number or a digit.
        for (char const &c: line)
        {
            if (isalnum(c) || c == '@' || c == ':' || c == '.')
            {
                shell += c;
            }
        }
    };

    helper_functions::check_correct_format(line) ? edit() : void();
}

void logic::emails_to_username(std::string_view line, std::string &shell)
{
    if (!helper_functions::is_email(line))
    {
        shell += line;
        return;
    }

    auto edit = [&]
    {
        const size_t colon = line.find_first_of(':');
        if (const size_t mail = line.find_first_of('@'); mail < colon)
        {
            shell += line.substr(0, mail);
            shell += line.substr(colon);
        }
    };

    helper_functions::check_correct_format(line) ? edit() : void();
}


void logic::usernames_to_email(std::string_view line, std::string_view domain, std::string &shell)
{
    if (helper_functions::is_email(line))
    {
        shell += line;
        return;
    }
    auto edit = [&]
    {
        const size_t colon = line.find_first_of(':');

        shell += line.substr(0, colon);
        shell += domain;
        shell += line.substr(colon);
    };

    helper_functions::check_correct_format(line) ? edit() : void();

}

inline void logic::append_to_end(std::string_view line, std::string_view append, std::string &shell)
{
    shell += line;
    shell += append;
}


void logic::append_to_username(std::string_view line, std::string_view append, std::string &shell)
{

    auto email = [&]
    {
        const size_t mail_index = line.find_first_of('@');

        shell += line.substr(0, mail_index);
        shell += append;
        shell += line.substr(mail_index);
    };

    auto username = [&]
    {
        const size_t colon_index = line.find_first_of(':');

        shell += line.substr(0, colon_index);
        shell += append;
        shell += line.substr(colon_index);
    };

    helper_functions::is_email(line) ? email() : username();
}

void logic::to_lower_case(std::string_view line, std::string &shell)
{
    for (const char &c: line)
    {
        if (std::islower(c))
        {
            shell += c;
        }
        else
        {
            shell += std::tolower((c));
        }
    }
}

void logic::to_upper_case(std::string_view line, std::string &shell)
{
    for (const char &c: line)
    {
        if (std::islower(c))
        {
            shell += std::toupper((c));
        }
        else
        {
            shell += c;
        }
    }
}

void logic::swap_pass_case_first_letter(std::string_view line, std::string &shell)
{
    auto edit = [&]
    {
        auto colon_index = line.find_first_of(':');

        if (islower(line[colon_index + 1]))
        {
            shell += line.substr(0, colon_index + 1);
            shell += std::toupper(line[colon_index + 1]);
            shell += line.substr(colon_index + 2);
        }
        else
        {
            shell += line.substr(0, colon_index + 1);
            shell += std::tolower((line[colon_index + 1]));
            shell += line.substr(colon_index + 2);
        }
    };

    helper_functions::check_correct_format(line) ? edit() : void();
}

void logic::swap_pass_numbers_to_user(std::string_view line, std::string &shell)
{
    auto edit = [&]
    {
        if (!helper_functions::has_numbers(line))
        {
            shell = line;
            return;
        }

        const size_t colon = line.find_first_of(':');

        const auto password = line.substr(0, colon + 1);

        std::string password_numbers;
        helper_functions::get_numbers(password, password_numbers);
        std::string password_letters;
        helper_functions::get_letters(password, password_letters);

        if (helper_functions::is_email(line))
        {
            const size_t mail_index = line.find_first_of('@');
            shell += line.substr(0, mail_index);
            shell += password_numbers;
            shell += ':';
            shell += password_letters;
        }
        else
        {
            shell += line.substr(0, colon);
            shell += password_numbers;
            shell += ':';
            shell += password_letters;
        }
    };

    helper_functions::check_correct_format(line) ? edit() : void();
}

void logic::swap_user_numbers_to_pass(std::string_view line, std::string &shell)
{
    auto edit = [&]
    {
        if (!helper_functions::has_numbers(line))
        {
            shell = line;
            return;
        }
        const size_t colon = line.find_first_of(':');

        const auto username = line.substr(0, colon);

        std::string user_numbers;
        std::string user_letters;

        helper_functions::get_numbers(username, user_numbers);
        helper_functions::get_letters(username, user_letters);

        shell += user_letters;
        shell += ':';
        shell += line.substr(colon + 1);
        shell += user_numbers;
    };

    helper_functions::check_correct_format(line) ? edit() : void();
}

void logic::extract_x_from_pass(std::string_view line, int length, std::string &shell)
{
    auto edit = [&]
    {
        const size_t colon_index = line.find_first_of(':');
        shell += line.substr(0, colon_index + 1);
        shell += line.substr(colon_index + 1, colon_index + 1 + length);
    };
    helper_functions::check_correct_format(line) ? edit() : void();
}

void logic::swap_numbers(std::string_view line, std::string &shell)
{
    auto edit = [&]
    {
        const size_t colon_index = line.find_first_of(':');

        const auto username = line.substr(0, colon_index);
        const auto password = line.substr(colon_index + 1);

        std::string username_letters;
        std::string username_numbers;
        std::string password_letters;
        std::string password_numbers;
        helper_functions::get_letters(username, username_letters);
        helper_functions::get_numbers(username, username_numbers);
        helper_functions::get_letters(password, password_letters);
        helper_functions::get_numbers(password, password_numbers);

        if (helper_functions::is_email(username))
        {
            const size_t mail_index = username_letters.find_first_of('@');

            shell += line.substr(0, mail_index);
            shell += password_numbers;
            shell += line.substr(mail_index, colon_index + 1);
            shell += password_letters;
            shell += username_numbers;
        }
        else
        {
            shell += username_letters;
            shell += password_numbers;
            shell += ':';
            shell += password_letters;
            shell += username_numbers;
        }
    };

    helper_functions::check_correct_format(line) ? edit() : void();
}

void logic::delete_duplicates(const std::string &file_path)
{
    std::fstream file_read;
    std::fstream file_write;

    file_write.open("delete_duplicates.txt", std::ios::app);
    file_read.open(file_path, std::ios::in);

    if (file_read.is_open() && file_write.is_open())
    {
        const auto start_timer = std::chrono::high_resolution_clock::now();

        std::fstream is(file_path, std::ios::in | std::ios::binary);

        is.seekg(0, std::ios::end);
        std::streamsize data_size = is.tellg();
        is.seekg(0, std::ios::beg);

        std::unique_ptr<char[]> data(new char[data_size]);
        is.read(data.get(), data_size);

        std::vector<std::string_view> load_file;
        load_file.reserve(data_size / 40);

        std::cout << "Deleting duplicates.\n";

        for (size_t i = 0, start = 0; i < data_size; ++i)
        {
            if (data[i] == '\n') // End of line, got string
            {
                load_file.emplace_back(data.get() + start, i - start);
                start = i + 1;
            }
        }

        // File is in the vector by now, now we sort it.
        std::ranges::sort(load_file);

        // Lines are sorted now, time to delete duplicates.
        load_file.erase(std::unique(load_file.begin(), load_file.end()), load_file.end());

        // Duplicates deleted, now write them all to a file.
        for (const auto &e: load_file)
        { file_write << e; }

        const auto finish_timer = std::chrono::high_resolution_clock::now();
        const std::chrono::duration<double> elapsed = finish_timer - start_timer;

        std::cout << "Duplicates deleted, " << "execution took: " << elapsed.count() << " seconds" << ", exiting."
                  << "\n";
        system("pause");
        return;
    }
    std::cout << "Error opening files for reading or writing, there is a problem with your file paths." << '\n';
    file_write.close();
    file_read.close();
}
