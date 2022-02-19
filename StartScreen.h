#ifndef EDITOR_STARTSCREEN_H
#define EDITOR_STARTSCREEN_H
#include <iostream>
class StartScreen {
public:
  static void ascii_art() {
    std::cout << " __        __   ___ " << '\n';
    std::cout << "|__)  /\\  /__` |__  " << '\n';
    std::cout << "|  \\ /~~\\ .__/ |___ " << '\n';
  }

  static void program_name() {
    std::cout << '\n';
    std::cout << "  _____ ___ _     _____   _____ ____ ___ _____ ___  ____  "
              << '\n';
    std::cout << " |  ___|_ _| |   | ____| | ____|  _ \\_ _|_   _/ _ \\|  _ \\ "
              << '\n';
    std::cout << " | |_   | || |   |  _|   |  _| | | | | |  | || | | | |_) |"
              << '\n';
    std::cout << " |  _|  | || |___| |___  | |___| |_| | |  | || |_| |  _ < "
              << '\n';
    std::cout << " |_|   |___|_____|_____| |_____|____/___| |_| \\___/|_| \\_\\"
              << '\n';
    std::cout << '\n';
    std::cout << "#############################################################"
                 "########"
              << '\n';

    std::cout << "Press something to continue." << '\n';
    std::cin.get();
  }

  static void display_modes() {
    system("CLS");
    ascii_art();
    std::cout << "#############################################################"
                 "########"
              << '\n';
    std::cout << "1. remove_special_characters" << '\n';
    std::cout << "2. emails_to_username" << '\n';
    std::cout << "3. usernames_to_email" << '\n';
    std::cout << "4. append_to_end" << '\n';
    std::cout << "5. append_to_username" << '\n';
    std::cout << "6. to_lower_case" << '\n';
    std::cout << "7. to_upper_case" << '\n';
    std::cout << "8. swap_pass_case_first_letter" << '\n';
    std::cout << "9. swap_pass_numbers_to_user" << '\n';
    std::cout << "10. swap_user_numbers_to_pass" << '\n';
    std::cout << "11. extract_x_from_pass" << '\n';
    std::cout << "12. swap_numbers" << '\n';
    std::cout << "13. delete_duplicates" << '\n';
    std::cout << "#############################################################"
                 "########"
              << '\n';
  }

  static void PrintStartScreen() {
    ascii_art();
    program_name();
    display_modes();
  }
};

#endif // EDITOR_STARTSCREEN_H
