//
// Created by forac on 05/12/2021.
//

#include <iostream>
#include <functional>
#include "Initialize.h"
#include "Logic.h"
#include <chrono> // Stopwatch
#include <fstream>
#include "ModeEnum.h"

namespace fs = std::filesystem;


int initialize::read_and_write_file(int mode, int length, std::string_view append)
{
    if (mode != DELETE_DUPLICATES)
    {
        std::string file_path;
        //ask_file_path(file_path);

        std::string mode_name;
        //init_mode_name(mode, mode_name);
        std::erase(file_path, '"');

        std::fstream file_read(file_path, std::ios::in);
        std::fstream file_write(mode_name + ".txt", std::ios::app);

        if (file_read.is_open() && file_write.is_open())
        {
            std::cout << "Editing has been started.\n";
            const auto start_timer = std::chrono::high_resolution_clock::now();

            std::string shell;

            while (file_read >> shell)
            {
                std::string edit;
                init_mode_func(mode, shell, length, append, edit);
                if (!edit.empty())
                {
                    file_write << edit << "\n";
                }
            }
            file_read.close();
            file_write.close();

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
        //ask_file_path(file_path);
        std::erase(file_path, '"');
        logic::delete_duplicates(file_path);
    }
    return 0;
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



