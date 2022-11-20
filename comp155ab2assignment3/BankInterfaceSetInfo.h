#pragma once

#include <iostream>
#include <string>
#include "BankInterfaceNewAccount.h"


#ifndef BANKINTERFACESETINFO_H
#define BANKINTERFACESETINFO_H

class BankInterfaceSetInfo : public BankInterfaceNewAccount {
public:
	explicit BankInterfaceSetInfo();
	~BankInterfaceSetInfo();

	int virtual getSwitch() override;

	void virtual setSwitch() override;



private:
	int setInfoOption;
};

#endif // !BANKINTERFACESETINFO_H
