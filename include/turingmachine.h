//
// Created by Lenovo on 2024/5/31.
//

#ifndef TURINGLANGUAGE_TURINGMACHINE_H
#define TURINGLANGUAGE_TURINGMACHINE_H

#define MACHINE_MEMORY_LIMIT 100000

#include "basic.h"

class TuringMachine
{
public:
    TuringMachine(int statementNum);

    // 运行到停机状态 (Halt)
    void run();

private:
    std::vector<int>* _machineMemory;
    // 当前指针位置
    int _pointer;
    int _statementNum;
    // _currentStatement = -1 时停机
    // = 0 时为启动状态
    int _currentStatement;
};


#endif //TURINGLANGUAGE_TURINGMACHINE_H
