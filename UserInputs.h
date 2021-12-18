//
// Created by xdlol on 12/16/2021.
//

#ifndef EDITOR_USERINPUTS_H
#define EDITOR_USERINPUTS_H

#include <string>

class UserInputs
{
  public:
    static int input_and_validate_mode();
    static std::string input_file_path();
    static std::string get_append();
    static int get_length();
};

#endif // EDITOR_USERINPUTS_H
