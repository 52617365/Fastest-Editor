#include <iostream>
#include "Initialize.h"
#include "ModeEnum.h"
#include "HelperFunctions.h"
#include <limits>

void ascii_art();

void program_name();

void display_modes();

void choose_mode(int &mode, int &length, std::string &append);

int main()
{
    ascii_art();
    program_name();

    int mode;
    int length;
    std::string append;

    display_modes();
    choose_mode(mode, length, append);
    initialize::read_and_write_file(mode, length, append.c_str());
    return 0;
}

void ascii_art()
{
    std::cout << "#####################################################################" << std::endl;
    std::cout << "   __ _                         _              __ ____ ____ ______ " << std::endl;
    std::cout << "  / _| |                       | |            /_ |___ \\___ \\____  |" << std::endl;
    std::cout << " | |_| | ___  _ __  _ __   __ _| |__  _ __ ___ | | __) |__) |  / / " << std::endl;
    std::cout << " |  _| |/ _ \\| '_ \\| '_ \\ / _` | '_ \\| '__/ _ \\| ||__ <|__ <  / /  " << std::endl;
    std::cout << " | | | | (_) | |_) | |_) | (_| | |_) | | | (_) | |___) |__) |/ /   " << std::endl;
    std::cout << " |_| |_|\\___/| .__/| .__/ \\__,_|_.__/|_|  \\___/|_|____/____//_/    " << std::endl;
    std::cout << "             | |   | |                                             " << std::endl;
    std::cout << "             |_|   |_|                 							 " << std::endl;
}

void program_name()
{
    std::cout << std::endl;
    std::cout << "  _____ ___ _     _____   _____ ____ ___ _____ ___  ____  " << std::endl;
    std::cout << " |  ___|_ _| |   | ____| | ____|  _ \\_ _|_   _/ _ \\|  _ \\ " << std::endl;
    std::cout << " | |_   | || |   |  _|   |  _| | | | | |  | || | | | |_) |" << std::endl;
    std::cout << " |  _|  | || |___| |___  | |___| |_| | |  | || |_| |  _ < " << std::endl;
    std::cout << " |_|   |___|_____|_____| |_____|____/___| |_| \\___/|_| \\_\\" << std::endl;
    std::cout << std::endl;
    std::cout << "#####################################################################" << std::endl;

    std::cout << "Press something to continue." << std::endl;
    std::cin.get();
}

void display_modes()
{
    system("CLS");
    ascii_art();
    std::cout << "#####################################################################" << std::endl;
    std::cout << "1. remove_special_characters" << std::endl;
    std::cout << "2. emails_to_username" << std::endl;
    std::cout << "3. usernames_to_email" << std::endl;
    std::cout << "4. append_to_end" << std::endl;
    std::cout << "5. append_to_username" << std::endl;
    std::cout << "6. to_lower_case" << std::endl;
    std::cout << "7. to_upper_case" << std::endl;
    std::cout << "8. swap_pass_case_first_letter" << std::endl;
    std::cout << "9. swap_pass_numbers_to_user" << std::endl;
    std::cout << "10. swap_user_numbers_to_pass" << std::endl;
    std::cout << "11. extract_x_from_pass" << std::endl;
    std::cout << "12. swap_numbers" << std::endl;
    std::cout << "13. delete_duplicates" << std::endl;
    std::cout << "#####################################################################" << std::endl;
}

void choose_mode(int &mode, int &length, std::string &append)
{
    while ((std::cout << "Enter mode:\n") && (!(std::cin >> mode) || mode < 1 || mode > 13))
    {
        std::cout << "That's not a valid mode.";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    if (mode == APPEND_TO_END || mode == APPEND_TO_USERNAME)
    {
        std::cout << "What to append:\n";
        std::cin >> append;
    }
    else if (mode == EXTRACT_X_FROM_PASS)
    {

        std::cout << "Enter length\n";
        std::cin >> length;
        while (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter length\n";
            std::cin >> length;

        }
    }

    else if (mode == USERNAMES_TO_EMAIL)
    {
        while (!append.contains('@') && !append.contains('.'))
        {
            std::cout << "Enter domain e.g @example.com:\n";
            std::cin >> append;
        }
    }
}
