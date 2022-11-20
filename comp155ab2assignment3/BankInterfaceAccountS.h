#pragma once

#include <iostream>
#include <string>
#include "BankInterfaceNewAccount.h"


#ifndef BANKINTERFACEACCOUNTS_H
#define BANKINTERFACEACCOUNTS_H

class BankInterfaceAccountS : public BankInterfaceNewAccount {
public:
	explicit BankInterfaceAccountS();
	~BankInterfaceAccountS();

	int virtual getSwitch() override;

	void virtual setSwitch() override;

	void setBalance();

	int setDeposit();

	int setWidthdraw();

private:
	int accountOption;
};

#endif // !BANKINTERFACEACCOUNTS_H
