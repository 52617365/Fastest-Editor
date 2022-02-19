#ifndef EDITOR_HANDLEMODE_H
#define EDITOR_HANDLEMODE_H
#include "UserInputs.h"
#include <string>
class HandleMode {
public:
  HandleMode() : mode{UserInputs::input_and_validate_mode()} {}
  std::pair<int, std::string> init_mode();

private:
  int mode;
};

#endif // EDITOR_HANDLEMODE_H
