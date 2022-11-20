#pragma once

#include <iostream>
#include <string>
#include "BankInterfaceNewAccount.h"


#ifndef BANKINTERFACEACCOUNTSTATUS_H
#define BANKINTERFACEACCOUNTSTATUS_H

class BankInterfaceAccountStatus : public BankInterfaceNewAccount {
public:
	explicit BankInterfaceAccountStatus();
	~BankInterfaceAccountStatus();

	int virtual getSwitch() override;

	void virtual setSwitch() override;



private:
	int accountOption;
};

#endif // !BANKINTERFACEACCOUNTSTATUS_H
