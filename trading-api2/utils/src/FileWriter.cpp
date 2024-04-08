#include "FileWriter.hpp"

namespace utils {

FileWriter::FileWriter()
{
}

FileWriter::FileWriter(std::string filepath, bool startNewFile, FileExt ext)
    : filepath(filepath)
{
    (void)ext;
    try
    {
        if (startNewFile)
        {
            file.open(filepath, std::ios::out | std::ios::trunc | std::ios::binary);
        }
        else
        {
            file.open(filepath, std::ios::out | std::ios::app | std::ios::binary);
            if (!file)
                throw std::runtime_error("file could not be opened");
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

FileWriter::FileWriter(std::string filepath, bool startNewFile, FileExt ext, std::string csvHeader)
    : filepath(filepath)
{
    try
    {
        if (startNewFile)
        {
            file.open(filepath, std::ios::out | std::ios::trunc | std::ios::binary);
        }
        else
        {
            file.open(filepath, std::ios::out | std::ios::app | std::ios::binary);
        }
        if (!file.is_open())
        {
            throw std::runtime_error("file could not be opened");
        }
        if (ext == FileExt::CSV)
        {
            file << csvHeader.c_str();
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

FileWriter::~FileWriter()
{
    file.flush();
    file.close();
}

void FileWriter::write(std::string writeline)
{
    file << writeline.c_str();
    file.flush();
}

} // namespace utils
