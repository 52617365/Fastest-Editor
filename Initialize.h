//
// Created by forac on 05/12/2021.
//

#ifndef EDITOR_C___INITIALIZE_H
#define EDITOR_C___INITIALIZE_H

#include <string>


class initialize
{
    initialize() = default;
public:
    static void ask_file_path(std::string& file_path);

    static int read_and_write_file(int mode, int length, const char* append);

    static void init_mode_name(int mode, std::string& mode_name);

    static void init_mode_func(int mode, std::string& line, int length, const char* append);

    ~initialize();
};


#endif //EDITOR_C___INITIALIZE_H
