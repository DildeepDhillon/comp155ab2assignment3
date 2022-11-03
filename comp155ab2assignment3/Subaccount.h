#pragma once
// Creating Subaccount Class

#include <iostream>
#include <algorithm>
#include <string>

#ifndef SUBACCOUNT_H
#define SUBACCOUNT_H

class Subaccount {
public:
	
	explicit Subaccount(int = 0, int = 0);
	~Subaccount();

	//functions allows custmer to deposit money. Data validation confirms that the deposit needs to be
	 // a postive number and confirms that the balance doesnt exceed a 32-bit signed integer
	bool setDeposit(int);

	//functions allows custmer to withdraw money. Data validation confirms that the withdrawal needs to be
	// a postive number and confirms that the balance doesnt exceed a 32-bit signed integer
	bool setWithdrawal(int);

	//Returns the account balance
	int getBalance() const;

	int getTransactions() const;


private:
	int accountBalance;
	int transaction;
};

#endif // !SUBACCOUNT_H