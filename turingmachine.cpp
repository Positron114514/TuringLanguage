//
// Created by Lenovo on 2024/5/31.
//

#include "turingmachine.h"

TuringMachine::TuringMachine(std::unordered_map<std::string, Statement>* states):
    _machineMemory(new std::vector<bool>), _pointer(0), _states(states) {

}

void TuringMachine::setStates(std::unordered_map<std::string, Statement>* states) {
    this->_states = states;
}

void TuringMachine::run(char mode) {
    reset();
    if(_states == nullptr){
        LOG << MACHINE_ERROR_LOG << "please set the states before running this machine.\n";
    }
    switch(mode){
        case 'a': runToHalt();  break;
        case 'g': runInGUI();   break;
        case 's': runStepByStepInConsole(); break;
        default: runToHalt(); break;
    }
}

TuringMachine::~TuringMachine() {

}

void TuringMachine::runStepByStepInConsole() {

}

void TuringMachine::runToHalt() {
    std::string currentState = MACHINE_START_STATEMENT;
    while(currentState != MACHINE_HALT_STATEMENT){
        bool currentMemory = (*_machineMemory)[_pointer];
        Statement statement = (*_states)[currentState];

        LOG << MACHINE_RUNNING_LOG << "current state: " << currentState <<
            ", statement: " << statement.toString() << std::endl;
        // operate
        switch(statement.operations[currentMemory]){
            case '0': (*_machineMemory)[_pointer] = 0; break;
            case '1': (*_machineMemory)[_pointer] = 1; break;
            case 'l': _pointer--;   break;
            case 'r': _pointer++;   break;
            default: break;
        }
        currentState = statement.states[currentMemory];
    }
}

void TuringMachine::runInGUI() {

}

void TuringMachine::reset() {

}

void TuringMachine::setMemory(MachineMemory* memory) {
    this->_machineMemory = memory;
}

void TuringMachine::printMemory() {
    std::for_each(_machineMemory->begin(), _machineMemory->end(), [](bool x){
        std::cout << (int)x;
    });
    std::cout << std::endl;
}
