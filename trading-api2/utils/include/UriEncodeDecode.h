// https://stackoverflow.com/questions/154536/encode-decode-urls-in-c
#pragma once

#include <curl/curl.h>

#include <string>

namespace utils {

std::string url_encode(const std::string& decoded)
{
    const auto encoded_value = curl_easy_escape(nullptr, decoded.c_str(), static_cast<int>(decoded.length()));
    std::string result(encoded_value);
    curl_free(encoded_value);
    return result;
}

std::string url_decode(const std::string& encoded)
{
    int output_length;
    const auto decoded_value =
        curl_easy_unescape(nullptr, encoded.c_str(), static_cast<int>(encoded.length()), &output_length);
    std::string result(decoded_value, output_length);
    curl_free(decoded_value);
    return result;
}

} // namespace utils