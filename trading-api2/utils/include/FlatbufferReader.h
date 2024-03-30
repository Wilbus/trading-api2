#pragma once
#include "RawBuffer.h"
#include "flatbuffers/flatbuffers.h"
#include "flatbuffers/idl.h"
#include "flatbuffers/util.h"
#include "globalvars.h"

#include <fstream>
#include <iostream>
#include <string>

namespace utils {

enum ReadMode
{
    jsonfile,
    jsontext
};

template <class flatroottype>
class FlatBufferReader
{
public:
    FlatBufferReader()
    {
    }

    FlatBufferReader(std::string jsonInfo, std::string fbsName, ReadMode mode)
    {
        // RawBuffer temp;
        // char* temp = new
        fbsPath = schemaIncludePath + fbsName;
        // std::cout << fbsPath << "\n";
        std::string schemaFile = loadSchema(fbsPath);
        // std::cout << schemaFile << "\n";
        parseSchema(schemaFile);

        if (mode == ReadMode::jsonfile)
        {
            // std::cout << jsonInfo << "\n";
            std::ifstream infile;
            infile.open(jsonInfo.c_str(), std::ifstream::binary | std::ifstream::ate);
            if (!infile.is_open())
            {
                std::string msg = "error opening jsonfile: " + jsonInfo;
                throw std::runtime_error(msg.c_str());
            }
            auto length = infile.tellg();
            if (length < 0)
            {
                throw std::runtime_error("error json file is of length 0");
            }
            // char* temp = new char[length];
            std::vector<char> temp(length + 1);
            // temp.resize(length);
            infile.seekg(0);
            // infile.read(static_cast<char*>(static_cast<void*>(temp.data())), temp.size());
            infile.read(&temp[0], length + 1);
            infile.close();

            const char* includePaths[] = {schemaIncludePath.c_str()};
            // bool ok = parser.Parse(static_cast<char*>(static_cast<void*>(temp.data())), includePaths);
            bool ok = parser.Parse(&temp[0], includePaths);
            if (!ok)
            {
                throw std::runtime_error("error parsing file json to flatbuffer");
            }
        }
        else
        {
            const char* includePaths[] = {schemaIncludePath.c_str()};

            bool ok = parser.Parse(jsonInfo.c_str(), includePaths);
            if (!ok)
            {
                throw std::runtime_error("error parsing message json text to flatbuffer");
            }
        }

        auto detachedBuffer = parser.builder_.Release();
        rawBuff = RawBuffer(detachedBuffer.data(), detachedBuffer.size());
    }

    FlatBufferReader(std::string binFilePath)
    {
        std::ifstream infile;
        infile.open(binFilePath.c_str(), std::ifstream::binary | std::ifstream::ate);
        auto length = infile.tellg();
        rawBuff.resize(length);
        infile.seekg(0);
        infile.read(static_cast<char*>(static_cast<void*>(rawBuff.data())), rawBuff.size());
        infile.close();

        flatbuffers::Verifier verifier0(rawBuff.data(), rawBuff.size());
        if (!verifier0.VerifyBuffer<flatroottype>())
        {
            throw std::runtime_error("Invalid cbauth file");
        }
    }

    const RawBuffer& getBuffer()
    {
        return rawBuff;
    }

    const flatroottype* getRoot()
    {
        return ::flatbuffers::GetRoot<flatroottype>(rawBuff.data());
    }

private:
    std::string loadSchema(std::string& fbsPath)
    {
        std::string schemaFile;
        bool ok = flatbuffers::LoadFile(fbsPath.c_str(), false, &schemaFile);
        if (!ok)
        {
            throw std::runtime_error("error loading schema fbs");
        }
        return schemaFile;
    }

    void parseSchema(std::string schemaFile)
    {
        const char* includePathss[] = {schemaIncludePath.c_str()};
        bool ok = parser.Parse(schemaFile.c_str(), includePathss);
        if (!ok)
        {
            std::string msg = "error parsing schemafile " + schemaFile;
            throw std::runtime_error(msg.c_str());
        }
    }
    flatbuffers::Parser parser;
    std::string textBuffer;
    std::string schemaPath;
    std::string fbsPath;
    RawBuffer rawBuff;
};
} // namespace utils