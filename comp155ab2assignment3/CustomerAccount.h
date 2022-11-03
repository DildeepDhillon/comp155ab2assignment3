#pragma once

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "BankCustomer.h"
#include "Subaccount.h"

class BankCustomer;

#ifndef CUSTOMERACCOUNT_H
#define CUSTOMERACCOUNT_H


class CustomerAccount {
public:
	//Account constructor that initializes account values
	explicit CustomerAccount(int, BankCustomer);

	 //function to set account status, data validation code make sure status can only be updated if acceptable
	bool setStatus(std::string);

	 //Returns the account status
	std::string getAccountStatus() const;

	void AddSubAccount(Subaccount*);

	bool RemoveSubAccount();

	 

	 //Returns the account number, account number does not need a set function, since it gets set by the
	 //constructor and will not change
	int getAccountNumber() const;

	 //Returns the date for when the account opened, does not need a set function, since it will not change once initialized
	std::string getDateOpened() const;

	 //get and set function not needed for branch number as that will not change ever, and it would be the same
	 //for every account for that bank.

private:
	const int accountNumber;
	std::string accountStatus;
	std::string dateOpen;
	const std::string branchNumber;
	std::vector<Subaccount*> vectorSub;
};

#endif // !CUSTOMERACCOUNT_H
