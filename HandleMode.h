//
// Created by xdlol on 12/16/2021.
//

#ifndef EDITOR_HANDLEMODE_H
#define EDITOR_HANDLEMODE_H
#include <functional>
#include "Logic.h"
#include "Modes.h"

class HandleMode : Modes {
public:
  void init_mode() override;
  static void handle_writing(auto& func, std::fstream &read, std::fstream &write);
  /*
  static void handle_writing(const std::function <void(std::string_view, std::string&)>& mode_func, std::fstream &read, std::fstream &write);
  static void handle_writing(const std::function <void(std::string_view, std::string_view, std::string&)>& mode_func, std::fstream &read, std::fstream &write, std::string_view append);
  static void handle_writing(const std::function <void(std::string_view, int, std::string&)>& mode_func, std::fstream &read, std::fstream &write, int length);
  */
  std::string init_mode_name(int mode) override;
  static int get_length();
  static std::string get_append();
};

#endif // EDITOR_HANDLEMODE_H
