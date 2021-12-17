//
// Created by xdlol on 12/16/2021.
//

#ifndef EDITOR_HANDLEMODE_H
#define EDITOR_HANDLEMODE_H

#include "Logic.h"

class HandleMode {
public:
  static void init_mode();
  static void handle_writing(auto& func, std::fstream &read, std::fstream &write);
  static void handle_writing_append(auto& func, std::fstream &read, std::fstream &write);
  static void handle_writing_length(auto& func, std::fstream &read, std::fstream &write);

  static std::string init_mode_name(int mode);
  static int get_length();
  static std::string get_append();
};

#endif // EDITOR_HANDLEMODE_H
