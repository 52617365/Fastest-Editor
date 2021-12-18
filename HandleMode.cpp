//
// Created by xdlol on 12/18/2021.
//

#include <iostream>
#include "HandleMode.h"
#include "ModeEnum.h"
#include "HandleWriting.h"
#include "UserInputs.h"

void HandleMode::init_mode()
{
    const int mode = UserInputs::input_and_validate_mode();
    std::string mode_name;
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
            mode_name = {};
    }
    HandleWriting write(mode, mode_name);
    write.start_writing();
}
