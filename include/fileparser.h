//
// Created by Lenovo on 2024/5/31.
//

#ifndef TURINGLANGUAGE_FILEPARSER_H
#define TURINGLANGUAGE_FILEPARSER_H

#include "basic.h"

class FileParser
{
public:
    FileParser(std::string filePath);

    // 获取文件中的状态
    void getStatements();

    // 获取状态数


    // 解释一行
    void parseLine();

    ~FileParser();

private:
    std::fstream* inputFile;
    std::vector<std::string>* _statements;
};

#endif //TURINGLANGUAGE_FILEPARSER_H
