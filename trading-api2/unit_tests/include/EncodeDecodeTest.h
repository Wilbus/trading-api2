#pragma once

#include "UriEncodeDecode.h"
#include "base64.hpp"

#include <gtest/gtest.h>

using namespace utils;

class EncodeDecodeTest : public ::testing::Test
{
public:
    EncodeDecodeTest()
    {
    }
};

TEST_F(EncodeDecodeTest, uriDecode)
{
    std::string encoded = "C0.abcd123ff%40";
    std::string decoded = url_decode(encoded);
    EXPECT_EQ(decoded, "C0.abcd123ff@");
}

TEST_F(EncodeDecodeTest, base64Encode)
{
    std::string decoded = "app_key123:app_secret123";
    std::string encoded = base64::to_base64(decoded);
    EXPECT_EQ(encoded, "YXBwX2tleTEyMzphcHBfc2VjcmV0MTIz");
}