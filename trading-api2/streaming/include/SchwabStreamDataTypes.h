#pragma once

#include <map>
#include <string>

enum ServiceType : unsigned
{
    ADMIN,
    ACCT_ACTIVITY,
    LEVELONE_EQUITIES,
    NOSERVICE
};

enum CommandType : unsigned
{
    LOGIN,
    QOS,
    SUBS,
    NOCOMMAND
};

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

/*only one request per requestId*/
typedef int RequestId;
typedef std::string RequestJson;
typedef std::map<RequestId, Request> SchwabRequestsIdMap;