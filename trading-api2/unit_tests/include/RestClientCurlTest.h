#include "CurlWrapperFuncsMock.h"
#include "RestClientCurl.h"

#include <gtest/gtest.h>

using namespace restclient;
using namespace restclient::mocks;
using testing::_;
using testing::Return;

class RestClientCurlTest : public ::testing::Test
{
public:
    RestClientCurlTest()
    {
    }

    ~RestClientCurlTest()
    {
        EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_cleanup(curl));
        EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_global_cleanup());
    }

    void expectValidCurlOnInit()
    {
        EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_global_init(CURL_GLOBAL_ALL));
        curl = (CURL*)0xDEADBEEF;
        EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_init()).WillOnce(Return(curl));
        client = std::make_shared<RestClientCurl>();
    }

    void expectInvalidCurlOnInit()
    {
        EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_global_init(CURL_GLOBAL_ALL));
        curl = nullptr;
        EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_init()).WillOnce(Return(curl));
        client = std::make_shared<RestClientCurl>();
    }

    void expectSListHeaders()
    {
        list = nullptr;
        listptr1 = curl_slist_append(list, "header1");
        listptr2 = curl_slist_append(listptr1, "header2");
        EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_slist_append(list, "header1")).WillOnce(Return(listptr1));
        EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_slist_append(listptr1, "header2")).WillOnce(Return(listptr2));
    }

    void freeSList()
    {
        curl_slist_free_all(list);
        curl_slist_free_all(listptr1);
    }

protected:
    std::shared_ptr<RestClientCurl> client;
    CURL* curl;
    std::set<std::string> headers{"header1", "header2"};
    std::string path{"/somepath"};
    std::string finalUrl{"https://test.com/somepath"};
    std::string readbuffer{"{\"testdata\":123}"};
    curl_slist* list;
    curl_slist* listptr1;
    curl_slist* listptr2;
};

TEST_F(RestClientCurlTest, getResponseNullptrCurlTest)
{
    expectInvalidCurlOnInit();
    EXPECT_THROW(client->getResponse(path, headers), std::runtime_error);
}

TEST_F(RestClientCurlTest, getResponseSetOpt_Url_Failed)
{
    expectValidCurlOnInit();
    expectSListHeaders();
    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_url(curl, finalUrl))
        .WillOnce(Return(CURLcode::CURLE_URL_MALFORMAT));

    client->setBaseEndpoint("https://test.com");
    EXPECT_THROW(client->getResponse(path, headers), std::runtime_error);
    freeSList();
}

TEST_F(RestClientCurlTest, getResponseSetOpt_HttpVersion_Failed)
{
    expectValidCurlOnInit();
    expectSListHeaders();
    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_url(curl, finalUrl))
        .WillOnce(Return(CURLcode::CURLE_OK));
    EXPECT_CALL(
        CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_http_version(curl, CurlHttpVersions::MYCURL_HTTP_VERSION_1_0))
        .WillOnce(Return(CURLcode::CURLE_UNSUPPORTED_PROTOCOL));

    client->setBaseEndpoint("https://test.com");
    EXPECT_THROW(client->getResponse(path, headers), std::runtime_error);
    freeSList();
}

TEST_F(RestClientCurlTest, getResponseSetOpt_HttpGet_Failed)
{
    expectValidCurlOnInit();
    expectSListHeaders();
    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_url(curl, finalUrl))
        .WillOnce(Return(CURLcode::CURLE_OK));
    EXPECT_CALL(
        CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_http_version(curl, CurlHttpVersions::MYCURL_HTTP_VERSION_1_0))
        .WillOnce(Return(CURLcode::CURLE_OK));
    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_httpget(curl, true))
        .WillOnce(Return(CURLcode::CURLE_UNSUPPORTED_PROTOCOL));

    client->setBaseEndpoint("https://test.com");
    EXPECT_THROW(client->getResponse(path, headers), std::runtime_error);
    freeSList();
}

TEST_F(RestClientCurlTest, getResponseSetOpt_HttpHeader_Failed)
{
    expectValidCurlOnInit();
    expectSListHeaders();
    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_url(curl, finalUrl))
        .WillOnce(Return(CURLcode::CURLE_OK));
    EXPECT_CALL(
        CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_http_version(curl, CurlHttpVersions::MYCURL_HTTP_VERSION_1_0))
        .WillOnce(Return(CURLcode::CURLE_OK));
    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_httpget(curl, true))
        .WillOnce(Return(CURLcode::CURLE_OK));
    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_httpheader(curl, listptr2))
        .WillOnce(Return(CURLcode::CURLE_UNSUPPORTED_PROTOCOL));

    client->setBaseEndpoint("https://test.com");
    EXPECT_THROW(client->getResponse(path, headers), std::runtime_error);
    freeSList();
}

TEST_F(RestClientCurlTest, getResponseSetOpt_WriteFunction_Failed)
{
    expectValidCurlOnInit();
    expectSListHeaders();
    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_url(curl, finalUrl))
        .WillOnce(Return(CURLcode::CURLE_OK));
    EXPECT_CALL(
        CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_http_version(curl, CurlHttpVersions::MYCURL_HTTP_VERSION_1_0))
        .WillOnce(Return(CURLcode::CURLE_OK));
    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_httpget(curl, true))
        .WillOnce(Return(CURLcode::CURLE_OK));
    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_httpheader(curl, listptr2))
        .WillOnce(Return(CURLcode::CURLE_OK));
    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_writefunction(curl, _))
        .WillOnce(Return(CURLcode::CURLE_WRITE_ERROR)); // TODO: maybe check if correct function is called?

    client->setBaseEndpoint("https://test.com");
    EXPECT_THROW(client->getResponse(path, headers), std::runtime_error);
    freeSList();
}

TEST_F(RestClientCurlTest, getResponseSetOpt_WriteData_Failed)
{
    expectValidCurlOnInit();
    expectSListHeaders();
    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_url(curl, finalUrl))
        .WillOnce(Return(CURLcode::CURLE_OK));
    EXPECT_CALL(
        CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_http_version(curl, CurlHttpVersions::MYCURL_HTTP_VERSION_1_0))
        .WillOnce(Return(CURLcode::CURLE_OK));
    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_httpget(curl, true))
        .WillOnce(Return(CURLcode::CURLE_OK));
    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_httpheader(curl, listptr2))
        .WillOnce(Return(CURLcode::CURLE_OK));
    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_writefunction(curl, _))
        .WillOnce(Return(CURLcode::CURLE_OK)); // TODO: maybe check if correct function is called?
    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_writedata(curl, _))
        .WillOnce(Return(CURLcode::CURLE_WRITE_ERROR));

    client->setBaseEndpoint("https://test.com");
    EXPECT_THROW(client->getResponse(path, headers), std::runtime_error);
    freeSList();
}

TEST_F(RestClientCurlTest, getResponseEasyPerform_Failed)
{
    expectValidCurlOnInit();
    expectSListHeaders();
    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_url(curl, finalUrl))
        .WillOnce(Return(CURLcode::CURLE_OK));
    EXPECT_CALL(
        CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_http_version(curl, CurlHttpVersions::MYCURL_HTTP_VERSION_1_0))
        .WillOnce(Return(CURLcode::CURLE_OK));
    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_httpget(curl, true))
        .WillOnce(Return(CURLcode::CURLE_OK));
    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_httpheader(curl, listptr2))
        .WillOnce(Return(CURLcode::CURLE_OK));
    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_writefunction(curl, _))
        .WillOnce(Return(CURLcode::CURLE_OK)); // TODO: maybe check if correct function is called?
    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_writedata(curl, _))
        .WillOnce(Return(CURLcode::CURLE_OK));
    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_perform(curl))
        .WillOnce(Return(CURLcode::CURLE_COULDNT_CONNECT));

    client->setBaseEndpoint("https://test.com");
    EXPECT_THROW(client->getResponse(path, headers), std::runtime_error);
    freeSList();
}

TEST_F(RestClientCurlTest, getResponseTest)
{
    expectValidCurlOnInit();
    expectSListHeaders();

    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_url(curl, finalUrl))
        .WillOnce(Return(CURLcode::CURLE_OK));
    EXPECT_CALL(
        CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_http_version(curl, CurlHttpVersions::MYCURL_HTTP_VERSION_1_0))
        .WillOnce(Return(CURLcode::CURLE_OK));
    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_httpget(curl, true))
        .WillOnce(Return(CURLcode::CURLE_OK));
    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_httpheader(curl, listptr2))
        .WillOnce(Return(CURLcode::CURLE_OK));
    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_writefunction(curl, _))
        .WillOnce(Return(CURLcode::CURLE_OK)); // TODO: maybe check if correct function is called?
    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_writedata(curl, _))
        .WillOnce(Return(CURLcode::CURLE_OK));
    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_perform(curl)).WillOnce(Return(CURLcode::CURLE_OK));

    client->setBaseEndpoint("https://test.com");
    client->getResponse(path, headers);
    freeSList();
}