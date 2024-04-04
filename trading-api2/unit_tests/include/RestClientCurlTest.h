#include "CurlWrapperFuncsMock.h"
#include "RestClientCurl.h"

#include <gtest/gtest.h>

using namespace restclient;
using namespace restclient::mocks;
using testing::_;
using testing::Return;

class RestClientCurlTest : public ::testing::Test
{
    class RestClientCurlTestable : public RestClientCurl
    {
    public:
        RestClientCurlTestable()
        {
        }

        std::string* getReadBufferPtr()
        {
            return &readbuffer;
        }
    };

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
        client = std::make_shared<RestClientCurlTestable>();
        client->setBaseEndpoint("https://test.com");
    }

    void expectInvalidCurlOnInit()
    {
        EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_global_init(CURL_GLOBAL_ALL));
        curl = nullptr;
        EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_init()).WillOnce(Return(curl));
        client = std::make_shared<RestClientCurlTestable>();
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
    std::shared_ptr<RestClientCurlTestable> client;
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
    //EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_debugfunction(curl, _)).WillOnce(Return(CURLcode::CURLE_OK));
    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_stderr(curl, _)).WillOnce(Return(CURLcode::CURLE_OK));
    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_verbose(curl, true)).WillOnce(Return(CURLcode::CURLE_OK));
    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_writedata(curl, _))
        .WillOnce(Return(CURLcode::CURLE_WRITE_ERROR));

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
    //EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_debugfunction(curl, _)).WillOnce(Return(CURLcode::CURLE_OK));
    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_stderr(curl, _)).WillOnce(Return(CURLcode::CURLE_OK));
    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_verbose(curl, true)).WillOnce(Return(CURLcode::CURLE_OK));
    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_writedata(curl, client->getReadBufferPtr()))
        .WillOnce(Return(CURLcode::CURLE_OK));
    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_perform(curl))
        .WillOnce(Return(CURLcode::CURLE_COULDNT_CONNECT));

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
        .WillOnce(Return(CURLcode::CURLE_OK)); // TODO: maybe check if correct function is called somehow?
    //EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_debugfunction(curl, _)).WillOnce(Return(CURLcode::CURLE_OK));
    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_stderr(curl, _)).WillOnce(Return(CURLcode::CURLE_OK));
    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_verbose(curl, true)).WillOnce(Return(CURLcode::CURLE_OK));
    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_writedata(curl, client->getReadBufferPtr()))
        .WillOnce(Return(CURLcode::CURLE_OK));
    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_perform(curl)).WillOnce(Return(CURLcode::CURLE_OK));

    std::string responsedata = client->getResponse(path, headers);
    EXPECT_EQ(responsedata, "somejsondata");
    freeSList();
}

TEST_F(RestClientCurlTest, postResponseNullptrCurlTest)
{
    expectInvalidCurlOnInit();
    EXPECT_THROW(client->postResponse(path, headers, "bodydata"), std::runtime_error);
}

TEST_F(RestClientCurlTest, postResponseTest)
{
    expectValidCurlOnInit();
    expectSListHeaders();
    std::string body{"grant_type=refresh_token&refresh_token=token1234"};

    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_url(curl, finalUrl))
        .WillOnce(Return(CURLcode::CURLE_OK));
    EXPECT_CALL(
        CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_http_version(curl, CurlHttpVersions::MYCURL_HTTP_VERSION_1_0))
        .WillOnce(Return(CURLcode::CURLE_OK));
    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_httppost(curl, true))
        .WillOnce(Return(CURLcode::CURLE_OK));
    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_copypostfields(curl, body))
        .WillOnce(Return(CURLcode::CURLE_OK));
    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_httpheader(curl, listptr2))
        .WillOnce(Return(CURLcode::CURLE_OK));
    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_writefunction(curl, _))
        .WillOnce(Return(CURLcode::CURLE_OK)); // TODO: maybe check if correct function is called somehow?
    //EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_debugfunction(curl, _)).WillOnce(Return(CURLcode::CURLE_OK));
    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_stderr(curl, _)).WillOnce(Return(CURLcode::CURLE_OK));
    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_verbose(curl, true)).WillOnce(Return(CURLcode::CURLE_OK));
    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_setopt_writedata(curl, client->getReadBufferPtr()))
        .WillOnce(Return(CURLcode::CURLE_OK));
    EXPECT_CALL(CurlWrapperFuncsMock::inst(), mycurl_easy_perform(curl)).WillOnce(Return(CURLcode::CURLE_OK));

    std::string responsedata = client->postResponse(path, headers, body);
    EXPECT_EQ(responsedata, "somejsondata");
    freeSList();
}