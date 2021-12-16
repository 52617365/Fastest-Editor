#include "UserInputs.h"
#include <iostream>
#include <limits>

int UserInputs::input_and_validate_mode()
{
  int mode = 0;
  while ((std::cout << "Enter mode:\n") &&
         (!(std::cin >> mode) || mode < 1 || mode > 13))
  {
    std::cout << "That's not a valid mode.";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  }
  return mode;
}
std::string UserInputs::input_file_path()
{
  std::string file_path;

  std::cin.ignore();

  while(((std::cout << "Drag file into terminal: \n") && std::getline(std::cin, file_path)) && std::empty(file_path))
  {
    std::cout << "Empty.";
  }
  std::erase(file_path, '"');
  return file_path;
}
