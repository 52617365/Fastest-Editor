#include "HandleMode.h"
#include "HandleWriting.h"
#include "StartScreen.h"
#include "UserInputs.h"
#include <iostream>
#include <string>
int main() {
  StartScreen::PrintStartScreen();
  HandleMode handle_mode;
  auto [mode, mode_name]{handle_mode.init_mode()};
  try {
    HandleWriting write(mode, mode_name);
    write(mode);
  } catch (const std::runtime_error &ex) {
    std::cout << ex.what();
    std::cin.get();
    return 1;
  }
  return 0;
}
