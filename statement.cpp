//
// Created by Lenovo on 2024/8/17.
//

#include "statement.h"

Statement::Statement(char operation0, char operation1, std::string state0, std::string state1){
    states[0] = state0;
    states[1] = state1;
    operations[0] = operation0;
    operations[1] = operation1;
}

Statement::Statement() {

}

std::string Statement::toString() {
    std::string retStr;
    retStr.append("0: ").append(std::string(1, operations[0])).append(states[0]).
        append("; 1: ").append(std::string(1, operations[1])).append(states[1]);
    return retStr;
}

