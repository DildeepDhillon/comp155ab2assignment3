#pragma once

#include <iostream>
#include <string>
#include "BankInterfaceNewAccount.h"


#ifndef BANKINTERFACEACCOUNTM_H
#define BANKINTERFACEACCOUNTM_H

class BankInterfaceAccountM : public BankInterfaceNewAccount {
public:
	explicit BankInterfaceAccountM();
	~BankInterfaceAccountM();

	int virtual getSwitch() override;

	void virtual setSwitch() override;



private:
	int accountOption;
};

#endif // !BANKINTERFACEACCOUNTM_H