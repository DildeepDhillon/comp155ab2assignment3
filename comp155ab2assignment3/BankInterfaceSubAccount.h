#pragma once

#include <iostream>
#include <string>
#include "BankInterfaceNewAccount.h"
#include "Subaccount.h"


#ifndef BANKINTERFACESUBACCOUNT_H
#define BANKINTERFACESUBACCOUNT_H

class BankInterfaceSubAccount : public BankInterfaceNewAccount {
public:
	explicit BankInterfaceSubAccount();
	~BankInterfaceSubAccount();

	int virtual getSwitch() override;

	void virtual setSwitch() override;

	int addSubAccount();

	int removeSubAccount();

	void subAccountList();

	void setSubAccountManageSwitch();

	int getSubAccountManageSwitch();

	void setSubAccountModifySwitch();

	int getSubAccountModifySwitch();

	int subAccountDeposit();

	int subAccountWithdraw();

private:
	int getInfoOption;
	int getsubaccount;
	int getmodify;
	int subaccount;
};

#endif // !BANKINTERFACESUBACCOUNT_H

