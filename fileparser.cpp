//
// Created by Lenovo on 2024/5/31.
//

#include "fileparser.h"

// todo: 注释
std::unordered_map<std::string, Statement> *FileParser::parseFile(std::string filePath) {
    // reset fileParser
    init();

    _inputFile->open(filePath);
    if(!_inputFile->is_open()){
        LOG << PARSER_LOG_INFO << "invalid input file: " + filePath << std::endl;
        return nullptr;
    }

    if(!getStatements()){ // invalid
        return nullptr;
    }

    std::string buffer;
    while(!_inputFile->eof()){
        // todo: parse file to _statements
        (*_inputFile) >> buffer;
        if(isNumber(buffer)){ // statement
            LOG << PARSER_LOG_INFO << "invalid syntax: statement shouldn't be a number.\n";
            return nullptr;
        }

        Statement* currentOperatingStatement = &(*_statements)[buffer];

        (*_inputFile) >> buffer;
        if(!isNumber(buffer)){
            LOG << PARSER_LOG_INFO << "invalid syntax: arg0 should be 0 or 1, must be a number.\n";
            return nullptr;
        }
        int code = std::stoi(buffer);
        if((code | 1) != 1){
            LOG << PARSER_LOG_INFO << "invalid syntax: arg0 should be 0 or 1.\n";
            return nullptr;
        }

        (*_inputFile) >> buffer;
        if(buffer.length() != 1 || !isValidOperation(buffer[0])){
            LOG << PARSER_LOG_INFO << "invalid syntax: arg1 should be an operation (0/1/l/r)\n";
            return nullptr;
        }
        currentOperatingStatement->operations[code] = buffer[0]; // set op[code] to target

        (*_inputFile) >> buffer;
        if(isNumber(buffer)){
            LOG << PARSER_LOG_INFO << "invalid syntax: arg2 should be sa state, not a number.\n";
            return nullptr;
        }
        currentOperatingStatement->states[code] = buffer;
    }
    return _statements;
}

bool FileParser::getStatements() {
    std::string buffer;
    while(!_inputFile->eof()){
        (*_inputFile) >> buffer;
        // check if string is a number or already be included
        if(!isNumber(buffer) && _statements->find(buffer) == _statements->end()){
            (*_statements)[buffer] = Statement();
        }
    }

    if(_statements->find(MACHINE_HALT_STATEMENT) != _statements->end() && _statements->find(MACHINE_START_STATEMENT) != _statements->end()){
        return true;
    }
    LOG << PARSER_LOG_INFO << "invalid statements: statements must have 'start' and 'halt'\n";
    return false;
}

void FileParser::init() {
    _inputFile->close();
    _statements->clear();
}

FileParser::~FileParser() {
    _inputFile->close();
    delete _inputFile;
    delete _statements;
}
