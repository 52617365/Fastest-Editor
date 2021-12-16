//
// Created by xdlol on 12/16/2021.
//

#include "HandleMode.h"
#include "Logic.h"
#include "ModeEnum.h"
#include "UserInputs.h"
#include <chrono>
#include <fstream>
#include <functional>
#include <iostream>
#include <limits>

// Extract x length from password.
void HandleMode::init_mode()
{
    int mode = UserInputs::input_and_validate_mode();
    std::fstream read(UserInputs::input_file_path(), std::ios::in);
    std::fstream write(init_mode_name(mode) + ".txt", std::ios::app);

    if (read.is_open() && write.is_open())
    {
        std::cout << "Editing has been started.\n";
        const auto start_timer = std::chrono::high_resolution_clock::now();
        std::string shell;
        std::string edit;
        switch (mode)
        {
            case REMOVE_SPECIAL_CHARACTERS:
            {
                auto func = std::mem_fn(&logic::remove_special_characters);
                handle_writing(func, read, write);
                break;
            }
            case EMAILS_TO_USERNAME:
            {
                auto func = std::mem_fn(&logic::emails_to_username);
                handle_writing(func, read, write);
                break;
            }
            case USERNAMES_TO_EMAIL:
            {
                auto func = std::mem_fn(&logic::usernames_to_email);
                handle_writing(func, read, write);
                break;
            }
            case APPEND_TO_END:
            {
                auto func = std::mem_fn(&logic::append_to_end);
                handle_writing(func, read, write);
                break;
            }
            case APPEND_TO_USERNAME:
            {
                auto func = std::mem_fn(&logic::append_to_username);
                handle_writing(func, read, write);
                break;
            }
            case TO_LOWER_CASE:
            {
                auto func = std::mem_fn(&logic::to_lower_case);
                handle_writing(func, read, write);
                break;
            }
            case TO_UPPER_CASE:
            {
                auto func = std::mem_fn(&logic::to_upper_case);
                handle_writing(func, read, write);
                break;
            }
            case SWAP_PASS_CASE_FIRST_LETTER:
            {
                auto func = std::mem_fn(&logic::swap_pass_case_first_letter);
                handle_writing(func, read, write);
                break;
            }
            case SWAP_PASS_NUMBERS_TO_USER:
            {
                auto func = std::mem_fn(&logic::swap_pass_numbers_to_user);
                handle_writing(func, read, write);
                break;
            }
            case SWAP_USER_NUMBER_TO_PASS:
            {
                auto func = std::mem_fn(&logic::swap_user_numbers_to_pass);
                handle_writing(func, read, write);
                break;
            }
            case EXTRACT_X_FROM_PASS:
            {
                auto func = std::mem_fn(&logic::extract_x_from_pass);
                handle_writing(func, read, write);
                break;
            }
            case SWAP_NUMBERS:
            {
                auto func = std::mem_fn(&logic::swap_numbers);
                handle_writing(func, read, write);
                break;
            }
            case DELETE_DUPLICATES:
            {
                auto func = std::mem_fn(&logic::delete_duplicates);
                handle_writing(func, read, write);
                break;
            }
            default: break;
        }
    }
}

int HandleMode::get_length()
{
    int length = 0;
    std::cout << "Enter length\n";
    std::cin >> length;

    while (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Enter length:\n";
        std::cin >> length;
    }
    return length;
}

std::string HandleMode::get_append()
{
    std::string append;
    while ((std::cout << "Enter append or domain:\n") && std::cin >> append &&
           std::empty(append))
    {
    }
    return append;
}

/*
// pass in the function here, make like 3 overloads ngl
void HandleMode::handle_writing(
        const std::function<void(std::string_view, std::string &)> &mode_func,
        std::fstream &read, std::fstream &write)
{
    std::string shell;
    while (read >> shell)
    {
        std::string edit;
        mode_func(shell, edit);
        write << edit << '\n';
    }
}

void HandleMode::handle_writing(
        const std::function<void(std::string_view, std::string_view, std::string &)>
        &mode_func,
        std::fstream &read, std::fstream &write, std::string_view append)
{

    std::string shell;
    while (read >> shell)
    {
        std::string edit;
        mode_func(shell, append, edit);
        write << edit << '\n';
    }
}

void HandleMode::handle_writing(
        const std::function<void(std::string_view, int, std::string &)> &mode_func,
        std::fstream &read, std::fstream &write, int length)
{
    std::string shell;
    while (read >> shell)
    {
        std::string edit;
        mode_func(shell, length, edit);
        write << edit << '\n';
    }
}
*/
std::string HandleMode::init_mode_name(const int mode)
{
    switch (mode)
    {
        case REMOVE_SPECIAL_CHARACTERS:
            return "remove_special_characters";
        case EMAILS_TO_USERNAME:
            return "emails_to_username";
        case USERNAMES_TO_EMAIL:
            return "usernames_to_email";
        case APPEND_TO_END:
            return "append_to_end";
        case APPEND_TO_USERNAME:
            return "append_to_username";
        case TO_LOWER_CASE:
            return "to_lower_case";
        case TO_UPPER_CASE:
            return "to_upper_case";
        case SWAP_PASS_CASE_FIRST_LETTER:
            return "swap_pass_case_first_letter";
        case SWAP_PASS_NUMBERS_TO_USER:
            return "swap_pass_numbers_to_user";
        case SWAP_USER_NUMBER_TO_PASS:
            return "swap_user_numbers_to_pass";
        case EXTRACT_X_FROM_PASS:
            return "extract_x_from_pass";
        case SWAP_NUMBERS:
            return "swap_numbers";
        default:
            return {};
    }
}

void HandleMode::handle_writing(auto &func, std::fstream &read,
                                std::fstream &write)
{

    std::string shell;
    logic l;

    while (read >> shell)
    {
        std::string edit;
        func(shell, edit);
        write << edit << '\n';
    }

    func(l);
}
