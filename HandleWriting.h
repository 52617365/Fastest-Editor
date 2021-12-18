//
// Created by xdlol on 12/16/2021.
//

#ifndef EDITOR_HANDLEWRITING_H
#define EDITOR_HANDLEWRITING_H

#include <utility>

#include "Logic.h"

class HandleWriting
{
private:
    int mode;

    std::string mode_name;

    void handle_writing(auto &func, std::fstream &read, std::fstream &write);

    void handle_writing_append(auto &func, std::fstream &read, std::fstream &write);

    void handle_writing_length(auto &func, std::fstream &read, std::fstream &write);

public:
    HandleWriting(int mode, std::string mode_name) : mode {mode}, mode_name {std::move(mode_name)}
    {}

    void start_writing();





    ~HandleWriting()
    = default;
};

#endif // EDITOR_HANDLEWRITING_H
