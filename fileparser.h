//
// Created by Lenovo on 2024/5/31.
//

#ifndef TURINGLANGUAGE_FILEPARSER_H
#define TURINGLANGUAGE_FILEPARSER_H

#define PARSER_LOG_INFO "Parser: "

#include "basic.h"
#include "statement.h"

class FileParser
{
public:
    FileParser(): _inputFile(new std::fstream), _statements(new std::unordered_map<std::string, Statement>()){};

    /**
     * parse a specific file and save the data into this parser
     * @param filePath
     * @return parse result
     */
    std::unordered_map<std::string, Statement>* parseFile(std::string filePath);

    /**
     * get the machine memory of a file.
     */
    void getMachineMemory();

    ~FileParser();

private:
    void init();

    /**
     * get statements in the file(first scan)
     * @return if valid statements(includes halt & start)
     */
    bool getStatements();

    bool isNumber(std::string &s){
        return s.find_first_not_of("0123456789") == std::string::npos;
    }

    bool isValidOperation(char c){
        return c == '0' || c == '1' || c == 'l' || c == 'r';
    }

    std::fstream* _inputFile;
    std::unordered_map<std::string, Statement>* _statements;
};

#endif //TURINGLANGUAGE_FILEPARSER_H
