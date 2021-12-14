//
// Created by forac on 05/12/2021.
//


#include <string>


class initialize
{
    initialize() = default;
public:
    static void ask_file_path(std::string& file_path);

    static int read_and_write_file(int mode, int length, std::string_view append);

    static void init_mode_name(int mode, std::string& mode_name);

    static void init_mode_func(int mode, std::string_view line, int length, std::string_view append, std::string &shell);

    ~initialize();
};

