#include "SchwabClientMock.h"
#include "SchwabConfigsMock.h"
#include "SchwabConnectionManager.h"
#include "StreamHandlerMock.h"

#include <gtest/gtest.h>

class SchwabConnectionManagerTest : public ::testing::Test
{
public:
    SchwabConnectionManagerTest()
    {
        configsMock = std::make_shared<SchwabConfigsMock>();
        clientMock = std::make_shared<SchwabClientMock>();
    }

protected:
    std::shared_ptr<SchwabConnectionManager> manager;
    std::shared_ptr<SchwabConfigsMock> configsMock;
    std::shared_ptr<SchwabClientMock> clientMock;
};

TEST_F(SchwabConnectionManagerTest, test0)
{
    manager = std::make_shared<SchwabConnectionManager>(configsMock, clientMock);
}