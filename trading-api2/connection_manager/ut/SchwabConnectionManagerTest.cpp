#include "SchwabConnectionManager.h"
#include "SchwabConfigsMock.h"
#include "SchwabClientMock.h"
#include "StreamHandlerMock.h"

#include <gtest/gtest.h>

class SchwabConnectionManagerTest : public ::testing::Test
{
public:
    SchwabConnectionManagerTest()
    {

    }
protected:
    std::shared_ptr<SchwabConnectionManager> manager;
    std::shared_ptr<SchwabConfigsMock> configsMock;
    std::shared_ptr<SchwabClientMock> clientMock;
};

TEST_F(SchwabConnectionManagerTest, test0)
{

}