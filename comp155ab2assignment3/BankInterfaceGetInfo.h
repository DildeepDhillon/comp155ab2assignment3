#pragma once

#include <iostream>
#include <string>
#include "BankInterfaceNewAccount.h"


#ifndef BANKINTERFACEGETINFO_H
#define BANKINTERFACEGETINFO_H

class BankInterfaceGetInfo : public BankInterfaceNewAccount {
public:
	explicit BankInterfaceGetInfo();
	~BankInterfaceGetInfo();

	int virtual getSwitch() override;

	void virtual setSwitch() override;

	void printName();

	void printAddress();

	void printPhone();


private:
	int getInfoOption;
};

#endif // !BANKINTERFACEGETINFO_H
