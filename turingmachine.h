//
// Created by Lenovo on 2024/5/31.
//

#ifndef TURINGLANGUAGE_TURINGMACHINE_H
#define TURINGLANGUAGE_TURINGMACHINE_H

#define MACHINE_MEMORY_LIMIT 100000
#define MACHINE_ERROR_LOG "Machine error: "
#define MACHINE_RUNNING_LOG "Machine running: "

#include "basic.h"
#include "statement.h"

typedef std::vector<bool> MachineMemory;

class TuringMachine
{
public:
    TuringMachine(std::unordered_map<std::string, Statement>* states);

    TuringMachine(): _machineMemory(new std::vector<bool>), _pointer(0){};

    void setStates(std::unordered_map<std::string, Statement>* states);

    void reset();

    // 运行到停机状态 (Halt)
    void run(char mode);

    void setMemory(std::vector<bool>* memory);

    ~TuringMachine();

    void printMemory();

private:
    void runStepByStepInConsole();

    void runToHalt(); // todo: run

    void runInGUI(); // todo: GUI

    MachineMemory* _machineMemory;
    // 当前指针位置
    int _pointer;

    std::unordered_map<std::string, Statement>* _states = nullptr;
};


#endif //TURINGLANGUAGE_TURINGMACHINE_H
