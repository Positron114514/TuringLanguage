//
// Created by Lenovo on 2024/5/31.
//
#include "main.h"

int main(int argc, char** argv)
{
    FileParser parser;
    TuringMachine machine;
    std::string path;

#ifdef DEBUG_MODE
    path = TEST_FILE_PATH;
#else
    path = argv[0];
#endif
    auto result = parser.parseFile(path);
    if(result == nullptr){
        LOG << "Parse failed.\n";
        return 1;
    }
    machine.setStates(result);
    MachineMemory* memory = new MachineMemory;
    memory->push_back(true);
    machine.setMemory(memory);
    machine.run('a');
    machine.printMemory();
    return 0;
}
