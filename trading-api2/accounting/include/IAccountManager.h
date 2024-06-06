#pragma once

#include "AccountDetails.h"

namespace accounting
{

class IAccountManager
{
public:
    virtual void handleAccountUpdatess() = 0;
    virtual AccountDetails getAccountDetails(const std::string& accountNumber) const = 0;
    virtual Position getPosition(const std::string& accountNumber, const std::string& symbol) const = 0;
}
};