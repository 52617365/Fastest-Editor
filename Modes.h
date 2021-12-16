//
// Created by xdlol on 12/16/2021.
//

#ifndef EDITOR_MODES_H
#define EDITOR_MODES_H

#include <string>
#include "Logic.h"

class Modes {
public:
  virtual void init_mode() = 0;
  virtual std::string init_mode_name(int mode) = 0;
};

#endif // EDITOR_MODES_H
