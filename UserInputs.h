//
// Created by xdlol on 12/16/2021.
//

#ifndef EDITOR_USERINPUTS_H
#define EDITOR_USERINPUTS_H

#include "Modes.h"

class UserInputs
{
  public:
    static int input_and_validate_mode();
    static std::string input_file_path();
};

#endif // EDITOR_USERINPUTS_H
