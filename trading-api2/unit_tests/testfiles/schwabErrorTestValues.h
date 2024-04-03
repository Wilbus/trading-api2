#pragma once

#include <string>

std::string genericError400 =
    R"({
  "errors": [
    {
      "id": "6808262e-52bb-4421-9d31-6c0e762e7dd5",
      "status": "400",
      "title": "Bad Request",
      "detail": "Missing header",
      "source": {
        "header": "Authorization"
      }
    },
    {
      "id": "0be22ae7-efdf-44d9-99f4-f138049d76ca",
      "status": "400",
      "title": "Bad Request",
      "detail": "Search combination should have min of 1.",
      "source": {
        "pointer": [
          "/data/attributes/symbols",
          "/data/attributes/cusips",
          "/data/attributes/ssids"
        ]
      }
    },
    {
      "id": "28485414-290f-42e2-992b-58ea3e3203b1",
      "status": "400",
      "title": "Bad Request",
      "detail": "valid fields should be any of all,fundamental,reference,extended,quote,regular or empty value",
      "source": {
        "parameter": "fields"
      }
    }
  ]
})";

std::string genericError401 =
    R"({
  "errors": [
    {
      "status": "401",
      "title": "Unauthorized",
      "id": "0be22ae7-efdf-44d9-99f4-f138049d76ca"
    }
  ]
})";

std::string genericError404 =
    R"({
  "errors": [
    {
      "status": "404",
      "title": "Not Found",
      "id": "0be22ae7-efdf-44d9-99f4-f138049d76ca"
    }
  ]
})";

std::string genericError500 =
    R"({
  "errors": [
    {
      "id": "0be22ae7-efdf-44d9-99f4-f138049d76ca",
      "status": "500",
      "title": "Internal Server Error"
    }
  ]
})";

std::string postErrorInvalidClient =
    R"({
    "error": "invalid_client",
    "error_description": "Unauthorized"
})";