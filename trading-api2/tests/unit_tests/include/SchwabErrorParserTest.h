#pragma once

#include "SchwabErrorParser.h"
#include "schwabErrorTestValues.h"
#include "schwabOptionsTestValues.h"

#include <gtest/gtest.h>

using namespace schwabErrors;

class SchwabErrorParserTest : public ::testing::Test
{
public:
    SchwabErrorParserTest()
    {
    }

protected:
};

TEST_F(SchwabErrorParserTest, parseGenericError400)
{
    auto errorResp = checkErrors(genericError400);
    // just check some fields
    Error err0 = errorResp.errors[0];
    Error err1 = errorResp.errors[1];
    Error err2 = errorResp.errors[2];
    EXPECT_EQ(err0.id, "6808262e-52bb-4421-9d31-6c0e762e7dd5");
    EXPECT_EQ(err0.status, "400");
    EXPECT_EQ(err0.title, "Bad Request");
    EXPECT_EQ(err0.detail, "Missing header");
    EXPECT_EQ(err0.source.header, "Authorization");

    EXPECT_EQ(err1.source.pointer[0], "/data/attributes/symbols");
    EXPECT_EQ(err1.source.pointer[1], "/data/attributes/cusips");
    EXPECT_EQ(err1.source.pointer[2], "/data/attributes/ssids");

    EXPECT_EQ(err2.source.parameter, "fields");
}

TEST_F(SchwabErrorParserTest, parseGenericError401)
{
    auto errorResp = checkErrors(genericError401);
    Error err0 = errorResp.errors[0];
    EXPECT_EQ(err0.id, "0be22ae7-efdf-44d9-99f4-f138049d76ca");
    EXPECT_EQ(err0.status, "401");
    EXPECT_EQ(err0.title, "Unauthorized");
}

TEST_F(SchwabErrorParserTest, parseGenericError404)
{
    auto errorResp = checkErrors(genericError404);
    Error err0 = errorResp.errors[0];
    EXPECT_EQ(err0.id, "0be22ae7-efdf-44d9-99f4-f138049d76ca");
    EXPECT_EQ(err0.status, "404");
    EXPECT_EQ(err0.title, "Not Found");
}

TEST_F(SchwabErrorParserTest, parseGenericError505)
{
    auto errorResp = checkErrors(genericError500);
    Error err0 = errorResp.errors[0];
    EXPECT_EQ(err0.id, "0be22ae7-efdf-44d9-99f4-f138049d76ca");
    EXPECT_EQ(err0.status, "500");
    EXPECT_EQ(err0.title, "Internal Server Error");
}

TEST_F(SchwabErrorParserTest, parseErrorInvalidClient)
{
    auto errorResp = checkErrors(postErrorInvalidClient);
    Error err0 = errorResp.errors[0];
    EXPECT_EQ(err0.detail, "invalid_client");
    EXPECT_EQ(err0.error_description, "Unauthorized");
}

TEST_F(SchwabErrorParserTest, parseNoErrors)
{
    auto errorResp = checkErrors(schwabOptionsExample_ALL_5Strikes);
    EXPECT_EQ(errorResp.errors.size(), 0);
}