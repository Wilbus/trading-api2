#pragma once

#include <map>
#include <string>

enum ServiceType : unsigned
{
    ADMIN,
    ACCT_ACTIVITY,
    LEVELONE_EQUITIES,
    CHART_EQUITY,
    OPTION,
    NOSERVICE
};

// clang-format off
static const std::map<ServiceType, std::string> serviceTypeToStringMap =
{
    {ServiceType::ADMIN, "ADMIN"},
    {ServiceType::ACCT_ACTIVITY, "ACCT_ACTIVITY"},
    {ServiceType::LEVELONE_EQUITIES, "LEVELONE_EQUITIES"},
    {ServiceType::CHART_EQUITY, "CHART_EQUITY"},
    {ServiceType::OPTION, "OPTION"},
    {ServiceType::NOSERVICE, "NOSERVICE"}
};

static const std::map<std::string, ServiceType> stringToServiceTypeMap = 
{
    {"ADMIN", ServiceType::ADMIN},
    {"ACCT_ACTIVITY", ServiceType::ACCT_ACTIVITY},
    {"LEVELONE_EQUITIES", ServiceType::LEVELONE_EQUITIES},
    {"CHART_EQUITY", ServiceType::CHART_EQUITY},
    {"OPTION", ServiceType::OPTION},
    {"NOSERVICE", ServiceType::NOSERVICE}
};
// clang-format on

enum CommandType : unsigned
{
    LOGIN,
    QOS,
    SUBS,
    NOCOMMAND
};

// clang-format off
static const std::map<CommandType, std::string> commandTypeToStringMap =
{
    {CommandType::LOGIN, "LOGIN"},
    {CommandType::QOS, "QOS"},
    {CommandType::SUBS, "SUBS"},
    {CommandType::NOCOMMAND, "NOCOMMAND"}
};

static const std::map<std::string, CommandType> stringToCommandTypeMap =
{
    {"LOGIN", CommandType::LOGIN},
    {"QOS", CommandType::QOS},
    {"SUBS", CommandType::SUBS},
    {"NOCMOMAND", CommandType::NOCOMMAND}
};
// clang-format on

struct ResponseContent
{
    int code{-1};
    std::string msg;
};

struct RequestParameters
{
    std::string authorization;
    std::string schwabClientChannel;
    std::string schwabClientFunctionId;
    std::string keys;
    std::string fields;
    std::string qoslevel;
};

struct Request
{
    ServiceType serviceType;
    int requestid;
    CommandType commandType;
    std::string schwabClientCustomerId;
    std::string schwabClientCorrelId;
    RequestParameters parameters;
};

struct Response
{
    ServiceType service{ServiceType::NOSERVICE};
    CommandType command{CommandType::NOCOMMAND};
    int requestid{-1}; // assuming we dont get a negative responseId ever
    std::string SchwabClientCorrelId;
    time_t timestamp{-1};
    ResponseContent content;
};

struct Heartbeat
{
    time_t timestamp{-1};
};

/*only one request per requestId*/
typedef int RequestId;
typedef std::string RequestJson;
typedef std::map<RequestId, Request> SchwabRequestsIdMap;