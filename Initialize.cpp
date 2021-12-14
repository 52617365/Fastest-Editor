//
// Created by forac on 05/12/2021.
//

#include <iostream>
#include <functional>
#include "Initialize.h"
#include <optional>
#include "HelperFunctions.h"
#include "Logic.h"
#include <chrono> // Stopwatch
#include "ModeEnum.h"
#include <memory>

void initialize::ask_file_path(std::string &file_path)
{
    std::cout << "Drag file into terminal: \n";
    std::cin.ignore();
    std::getline(std::cin, file_path);
}

int initialize::read_and_write_file(int mode, int length, std::string_view append)
{
    if (mode != DELETE_DUPLICATES)
    {
        std::string file_path;
        ask_file_path(file_path);

        std::string mode_name;
        init_mode_name(mode, mode_name);
        std::erase(file_path, '"');

        std::fstream file_read;
        file_read.open(file_path, std::ios::in);

        std::fstream file_write;
        file_write.open(mode_name + ".txt", std::ios::app);
        std::fstream is(file_path, std::ios::in | std::ios::binary);

        if (file_read.is_open() && file_write.is_open())
        {
            std::cout << "Editing has been started.\n";
            const auto start_timer = std::chrono::high_resolution_clock::now();

            is.seekg(0, std::ios::end);
            std::streamsize data_size = is.tellg();
            is.seekg(0, std::ios::beg);

            std::unique_ptr<char[]> data(new char[data_size]);
            is.read(data.get(), data_size);

            std::vector<std::string> load_file;
            load_file.reserve(data_size / 40);

            for (size_t i = 0, start = 0; i < data_size; ++i)
            {
                if (data[i] == '\n') // End of line, got string
                {
                    load_file.emplace_back(data.get() + start, i - start);
                    start = i + 1;
                }
            }

            for (auto &e: load_file)
            {
                std::string shell;
                shell.reserve(e.length() + append.length());
                init_mode_func(mode, e, length, append, shell);
                file_write << shell << '\n';
            }
            const auto finish_timer = std::chrono::high_resolution_clock::now();
            const std::chrono::duration<double> elapsed = finish_timer - start_timer;

            std::cout << "File edited, " << "execution took: " << elapsed.count() << " seconds" << ", exiting." << "\n";
            system("pause");
            return 0;
        }
        else
        {
            std::cout << "Error opening files for reading or writing, there is a problem with your file paths."
                      << std::endl;
            return 1;
        }
    }
    else
    {
        std::string file_path;
        ask_file_path(file_path);
        std::erase(file_path, '"');
        logic::delete_duplicates(file_path);
    }
    return 1;
}


void initialize::init_mode_name(const int mode, std::string &mode_name)
{
    switch (mode)
    {
        case REMOVE_SPECIAL_CHARACTERS:
            mode_name = "remove_special_characters";
            break;
        case EMAILS_TO_USERNAME:
            mode_name = "emails_to_username";
            break;
        case USERNAMES_TO_EMAIL:
            mode_name = "usernames_to_email";
            break;
        case APPEND_TO_END:
            mode_name = "append_to_end";
            break;
        case APPEND_TO_USERNAME:
            mode_name = "append_to_username";
            break;
        case TO_LOWER_CASE:
            mode_name = "to_lower_case";
            break;
        case TO_UPPER_CASE:
            mode_name = "to_upper_case";
            break;
        case SWAP_PASS_CASE_FIRST_LETTER:
            mode_name = "swap_pass_case_first_letter";
            break;
        case SWAP_PASS_NUMBERS_TO_USER:
            mode_name = "swap_pass_numbers_to_user";
            break;
        case SWAP_USER_NUMBER_TO_PASS:
            mode_name = "swap_user_numbers_to_pass";
            break;
        case EXTRACT_X_FROM_PASS:
            mode_name = "extract_x_from_pass";
            break;
        case SWAP_NUMBERS:
            mode_name = "swap_numbers";
            break;
        default:
            break;
    }
}

void initialize::init_mode_func(const int mode, std::string_view line, const int length, std::string_view append,
                           std::string &shell)
{
    switch (mode)
    {
        case REMOVE_SPECIAL_CHARACTERS:
            logic::remove_special_characters(line, shell);
            break;
        case EMAILS_TO_USERNAME:
            logic::emails_to_username(line, shell);
            break;
        case TO_LOWER_CASE:
            logic::to_lower_case(line, shell);
            break;
        case TO_UPPER_CASE:
            logic::to_upper_case(line, shell);
            break;
        case SWAP_PASS_CASE_FIRST_LETTER:
            logic::swap_pass_case_first_letter(line, shell);
            break;
        case SWAP_PASS_NUMBERS_TO_USER:
            logic::swap_pass_numbers_to_user(line, shell);
            break;
        case SWAP_USER_NUMBER_TO_PASS:
            logic::swap_user_numbers_to_pass(line, shell);
            break;
        case SWAP_NUMBERS:
            logic::swap_numbers(line, shell);
            break;
        case USERNAMES_TO_EMAIL:
            logic::usernames_to_email(line, append, shell);
            break;
        case APPEND_TO_END:
            logic::append_to_end(line, append, shell);
            break;
        case APPEND_TO_USERNAME:
            logic::append_to_username(line, append, shell);
            break;
        case EXTRACT_X_FROM_PASS:
            logic::extract_x_from_pass(line, length, shell);
            break;
        default:
            break;
    }
}


initialize::~initialize() = default;
