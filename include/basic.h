//
// Created by Lenovo on 2024/5/31.
//

#ifndef TURINGLANGUAGE_BASIC_H
#define TURINGLANGUAGE_BASIC_H

#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <unordered_map>
#include <fstream>
#include <algorithm>

#define DEBUG_MODE

#define MACHINE_HALT_STATEMENT "halt"
#define MACHINE_START_STATEMENT "start"

#ifdef DEBUG_MODE
#define LOG std::cout
#else
#define LOG Log::logFile << "[Turing Language] "
#endif

namespace Log{
    std::fstream logFile("./log.txt", std::ios::out);
}

#endif //TURINGLANGUAGE_BASIC_H
