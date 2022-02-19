#include "HandleMode.h"
#include "HandleWriting.h"
#include "StartScreen.h"
#include "UserInputs.h"
#include <iostream>
#include <string>
int main(int argc, char *argv[]) {
  StartScreen::PrintStartScreen();

  HandleMode handle_mode;
  auto [mode, mode_name]{handle_mode.init_mode()};
  HandleWriting write(mode, mode_name);
  try {
    write.start_writing();
  } catch (const std::runtime_error &ex) {
    std::cout << ex.what();
    return 1;
  }
  return 0;
}
