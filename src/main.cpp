//
// Created by Lenovo on 2024/5/31.
//
#include "main.h"

int main(int argc, char** argv)
{
    FileParser parser;
    TuringMachine machine;
    auto result = parser.parseFile(argv[0]);

    machine.setStates(result);

    machine.run();
}
