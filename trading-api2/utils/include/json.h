#include "rapidjson/document.h"

// TODO: do not throw if the member does not exist

#define PARSE_STRING(var, name, obj)                                     \
    if (obj.HasMember(name) && obj[name].IsString())                     \
    {                                                                    \
        var = obj[name].GetString();                                     \
    }                                                                    \

#define PARSE_INT(var, name, obj)                                     \
    if (obj.HasMember(name) && obj[name].IsInt())                     \
    {                                                                 \
        var = d[name].GetInt();                                       \
    }                                                                 \

#define PARSE_STRING_TO_UINT64(var, name, obj)                                  \
    if (obj.HasMember(name) && obj[name].IsString())                            \
    {                                                                           \
        var = std::stoul(d[name].GetString(), nullptr, 10);                     \
    }                                                                           \

#define PARSE_UINT(var, name, obj)                                  \
    if (obj.HasMember(name) && obj[name].IsUint())                  \
    {                                                               \
        var = obj[name].GetUint();                                  \
    }                                                               \

#define PARSE_UINT64(var, name, obj)                                 \
    if (obj.HasMember(name) && obj[name].IsUint64())                 \
    {                                                                \
        var = obj[name].GetUint64();                                 \
    }                                                                \

#define PARSE_BOOL(var, name, obj)                                  \
    if (obj.HasMember(name) && obj[name].IsBool())                  \
    {                                                               \
        var = obj[name].GetBool();                                  \
    }                                                               \

#define PARSE_DOUBLE(var, name, obj)                        \
    if (obj.HasMember(name) && obj[name].IsNumber())        \
    {                                                       \
        var = obj[name].GetDouble();                        \
    }                                                       \

#define PARSE_DOUBLESTRING(var, name, obj)                        \
    if (obj.HasMember(name) && obj[name].IsString())              \
    {                                                             \
        var = std::stod(d[name].GetString());                     \
    }                                                             \

#define PARSE_FLOAT(var, name)                   \
    if (d.HasMember(name) && d[name].IsNumber()) \
    {                                            \
        var = d[name].GetFloat();                \
    }

#define PARSE_VECTOR_DOUBLES(var, name)            \
    if (d.HasMember(name) && d[name].IsArray())    \
    {                                              \
        std::vector<double> items;                 \
        for (auto& item : d[name].GetArray())      \
        {                                          \
            if (item.IsNumber())                   \
            {                                      \
                items.push_back(item.GetDouble()); \
            }                                      \
        }                                          \
        var = items;                               \
    }

#define PARSE_VECTOR_FLOATS(var, name)            \
    if (d.HasMember(name) && d[name].IsArray())   \
    {                                             \
        std::vector<float> items;                 \
        for (auto& item : d[name].GetArray())     \
        {                                         \
            if (item.IsNumber())                  \
            {                                     \
                items.push_back(item.GetFloat()); \
            }                                     \
        }                                         \
        var = items;                              \
    }

#define PARSE_VECTOR_UINT64(var, name)             \
    if (d.HasMember(name) && d[name].IsArray())    \
    {                                              \
        std::vector<uint64_t> items;               \
        for (auto& item : d[name].GetArray())      \
        {                                          \
            if (item.IsNumber())                   \
            {                                      \
                items.push_back(item.GetUint64()); \
            }                                      \
        }                                          \
        var = items;                               \
    }
