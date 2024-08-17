//
// Created by Lenovo on 2024/8/17.
//

#ifndef TURINGLANGUAGE_STATEMENT_H
#define TURINGLANGUAGE_STATEMENT_H

#define STATEMENTS_ERROR_LOG "Statement Error: "

#include "basic.h"

class Statement {
public:
    Statement(char operation0, char operation1, std::string state0, std::string state1);
    Statement();

    std::string states[2] = {};
    char operations[2] = {};
};


#endif //TURINGLANGUAGE_STATEMENT_H
