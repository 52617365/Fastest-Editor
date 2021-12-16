//
// Created by forac on 05/12/2021.
//

#ifndef EDITOR_C___INITIALIZE_H
#define EDITOR_C___INITIALIZE_H
#include <string>

class initialize {
  initialize() = default;

public:
  static int read_and_write_file(int mode, int length, std::string_view append);

  static void init_mode_func(int mode, std::string_view line, int length, std::string_view append, std::string &shell);

  ~initialize() = default;
};

#endif //EDITOR_C___INITIALIZE_H
