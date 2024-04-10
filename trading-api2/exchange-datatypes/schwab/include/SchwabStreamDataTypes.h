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

enum LevelOneEquityField : unsigned
{
    SYMBOL = 0,
    BIDPRICE = 1,
    ASKPRICE = 2,
    LASTPRICE = 3,
    BIDSIZE = 4,
    ASKSIZE = 5,
    ASKID = 6,
    BIDID = 7,
    TOTALVOLUME = 8,
    LASTSIZE = 9,
    TRADETIME = 10,
    QUOTETIME = 11,
    // there are more to add
};

static std::string toString(LevelOneEquityField field)
{
    return std::to_string(field);
}

// TODO: SUBJECT TO CHANGE WHEN OFFICIAL SCHWAB STREAMING API DOCS AVAILABLE
struct LevelOneEquity
{
    // use -1 as uninitialized value
    // only values that change are received so we don't always receive all fields for each data
    std::string symbol;
    double bidprice{-1};
    double askprice{-1};
    double lastprice{-1};
    double lastsize{-1};
    int bidsize{-1};
    int asksize{-1};
    std::string askid;
    std::string bidid;
    long totalvolume{-1};
    time_t tradetime{-1};
    time_t quotetime{-1};
};

// TODO: SUBJECT TO CHANGE WHEN OFFICIAL SCHWAB STREAMING API DOCS AVAILABLE
struct ChartEquity
{
    // minute timeframe
    std::string symbol;
    double open{-1};
    double high{-1};
    double low{-1};
    double close{-1};
    double volume{-1};
    long sequence{-1};
    time_t time; // in ms since epoch

    std::string toString() const
    {
        return "symbol: " + symbol + " open: " + std::to_string(open) + " high: " + std::to_string(high) +
               " low: " + std::to_string(low) + " close: " + std::to_string(close) +
               " volume: " + std::to_string(volume) + " sequence: " + std::to_string(sequence) +
               " time: " + std::to_string(time);
    }
};

struct SchwabServiceData
{
    std::map<std::string, LevelOneEquity> levelOneEquities;
    std::map<std::string, ChartEquity> chartEquities;
};