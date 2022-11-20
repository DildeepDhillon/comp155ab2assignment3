#pragma once

#include <iostream>
#include <string>
#include "CustomerAccount.h"
#include "BankCustomer.h"
#include "Subaccount.h"


#ifndef BANKINTERFACENEWACCOUNT_H
#define BANKINTERFACENEWACCOUNT_H

//Base class object for the Bank machine interface
class BankInterfaceNewAccount {
public:
	explicit BankInterfaceNewAccount(int);
	~BankInterfaceNewAccount();

	void setPin(int);

	int getPin() const;

	bool setLogin(int);

	//Return the value of the menu selection made by the user, since the menu will change in every class, its virtual and will be overriden by derived classes
	int virtual getSwitch();

	//Presents the user with the main menu for the bank machine interface. It will be overriden in every derived class, as each derived class represents a sub menu
	void virtual setSwitch();
		


private:
	int pin;
	int option;
};

#endif // !BANKINTERFACENEWACCOUNT_H
