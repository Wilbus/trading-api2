#pragma once

#include <fstream>
#include <iostream>
#include <string>

namespace utils {

enum FileExt
{
    TXT = 0,
    CSV
};

class FileWriter
{
public:
    FileWriter();
    FileWriter(std::string filepath, bool startNewFile = true, FileExt ext = FileExt::TXT);
    FileWriter(std::string filepath, bool startNewFile = false, FileExt ext = FileExt::CSV, std::string csvHeader = "");
    ~FileWriter();

    void write(std::string writeline);

private:
    std::ofstream file;
    std::string filepath;
};
} // namespace utils