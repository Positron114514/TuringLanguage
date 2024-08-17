//
// Created by Lenovo on 2024/5/31.
//

#ifndef TURINGLANGUAGE_TURINGMACHINE_H
#define TURINGLANGUAGE_TURINGMACHINE_H

#define MACHINE_MEMORY_LIMIT 100000

#include "basic.h"
#include "statement.h"

class TuringMachine
{
public:
    TuringMachine(std::unordered_map<std::string, Statement>* states);

    TuringMachine();

    void setStates(std::unordered_map<std::string, Statement>* states);

    void reset();

    // 运行到停机状态 (Halt)
    void run(char mode);

    ~TuringMachine();

private:
    void runStepByStepInConsole();

    void runToHalt(); // todo: run

    void runInGUI(); // todo: GUI

    std::vector<int>* _machineMemory;
    // 当前指针位置
    int _pointer;
};


#endif //TURINGLANGUAGE_TURINGMACHINE_H
