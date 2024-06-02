#pragma once

class IAgent
{
public:
    virtual void startAgent() = 0;
    virtual void waitForAgent() = 0;
    virtual bool InPostion() = 0;
};