//
// Created by xdlol on 12/16/2021.
//

#include "HandleWriting.h"
#include "Logic.h"
#include "ModeEnum.h"
#include "UserInputs.h"
#include <chrono>
#include <fstream>
#include <functional>
#include <iostream>

void HandleWriting::start_writing()
{
    std::string file_path = UserInputs::input_file_path();
    std::fstream read(file_path, std::ios::in);
    std::fstream write(mode_name + ".txt", std::ios::app);

    if (read.is_open() && write.is_open())
    {
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
                handle_writing_append(func, read, write);
                break;
            }
            case APPEND_TO_END:
            {
                auto func = std::mem_fn(&logic::append_to_end);
                handle_writing_append(func, read, write);
                break;
            }
            case APPEND_TO_USERNAME:
            {
                auto func = std::mem_fn(&logic::append_to_username);
                handle_writing_append(func, read, write);
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
                handle_writing_length(func, read, write);
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
                logic::delete_duplicates(file_path);
                break;
            }
            default:
                break;
        }
    }
}

void HandleWriting::handle_writing(auto &func, std::fstream &read,
                                   std::fstream &write)
{
    std::string shell;
    logic l;

    std::cout << "Editing has been started.\n";
    const auto start = std::chrono::high_resolution_clock::now();

    while (read >> shell)
    {
        std::string edit;
        func(l, shell, edit);
        write << edit << '\n';
    }

    auto end = std::chrono::high_resolution_clock::now();
    read.close();
    write.close();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
    system("pause");
}

void HandleWriting::handle_writing_append(auto &func, std::fstream &read, std::fstream &write)
{
    std::string shell;
    std::string append = UserInputs::get_append();

    logic l;

    std::cout << "Editing has been started.\n";
    const auto start = std::chrono::high_resolution_clock::now();

    while (read >> shell)
    {
        std::string edit;
        func(l, shell, append, edit);
        write << edit << '\n';
    }

    auto end = std::chrono::high_resolution_clock::now();

    read.close();
    write.close();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
    system("pause");
}

void HandleWriting::handle_writing_length(auto &func, std::fstream &read, std::fstream &write)
{
    std::string shell;
    int length = UserInputs::get_length();

    logic l;

    std::cout << "Editing has been started.\n";
    const auto start = std::chrono::high_resolution_clock::now();

    while (read >> shell)
    {
        std::string edit;
        func(l, shell, length, edit);
        write << edit << '\n';
    }

    auto end = std::chrono::high_resolution_clock::now();
    read.close();
    write.close();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
    system("pause");
}

