#ifndef EDITOR_HANDLEWRITING_H
#define EDITOR_HANDLEWRITING_H
#include "Logic.h"
#include "UserInputs.h"
#include <fstream>
#include <utility>
class HandleWriting {
private:
  const int mode;
  const std::string mode_name;
  const std::string file_path;
  std::fstream read;
  std::fstream write;

  template <class T> void handle_writing(T &func, int mode);
  template <class T> void handle_writing_append(T &func, int mode);
  template <class T> void handle_writing_extract(T &func, int mode);
  template <class T> void handle_writing_domain(T &func, int mode);

public:
  HandleWriting(const int mode, const std::string &mode_name)
      : mode{mode}, mode_name{mode_name},
        file_path{UserInputs::input_file_path()}, read{file_path, std::ios::in},
        write{mode_name + ".txt", std::ios::app} {
    read.exceptions(std::fstream::badbit);
    write.exceptions(std::fstream::badbit);
    if (!read || !write) {
      throw std::runtime_error("Error opening file streams.\n");
    }
  }
  void operator()(int mode);
};

#endif // EDITOR_HANDLEWRITING_H
