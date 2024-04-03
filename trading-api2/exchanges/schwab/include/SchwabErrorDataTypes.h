#pragma once

#include <string>
#include <vector>

namespace schwabErrors
{
    
struct ErrorSource
{
    std::vector<std::string> pointer;
    std::string parameter;
    std::string header;
};

struct Error
{
    std::string id;
    std::string status; //http status code
    std::string title;
    std::string detail;
    std::string error_description;
    ErrorSource source;
};

struct ErrorResponse
{
    std::vector<Error> errors;

    //TODO: fix this so it displays the entire error
    std::string toString()
    {
        char buffer[1024];
        for(const auto& error : errors)
        {
            std::sprintf(buffer, "id: %s\n", error.id.c_str());
            std::sprintf(buffer, "status: %s\n", error.status.c_str());
            std::sprintf(buffer, "title: %s\n", error.title.c_str());
            if(error.detail.length() > 0)
                std::sprintf(buffer, "detail: %s\n", error.detail.c_str());
            if(error.error_description.length() > 0)
                std::sprintf(buffer, "error_description: %s\n", error.error_description.c_str());
            if(error.source.pointer.size() > 0)
            {
                std::sprintf(buffer, "sources:");
                for(const auto& s : error.source.pointer)
                {
                    std::sprintf(buffer, "%s,", s.c_str());
                }
                std::sprintf(buffer, "\n");
            }
            if(error.source.parameter.length() > 0)
            {
                std::sprintf(buffer, "parameter: %s\n", error.source.parameter.c_str());
            }
            if(error.source.header.length() > 0)
            {
                std::sprintf(buffer, "header: %s\n", error.source.header.c_str());
            }
        }
        return buffer;
    }
};
}