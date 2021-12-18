#include <iostream>
#include "HandleWriting.h"
#include "StartScreen.h"
#include <string>
#include "HandleMode.h"



int main(int argc, char *argv[])
{
    /*
    if (argc == 1)
    {
        std::cerr << "[ERROR] " << "No license key argument specified" << std::endl;
        exit(1);
    }
     */
    StartScreen::PrintStartScreen();
    HandleMode::init_mode();
    return 0;
}




