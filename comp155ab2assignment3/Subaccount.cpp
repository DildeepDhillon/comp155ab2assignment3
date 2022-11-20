
#include <iostream>
#include <algorithm>
#include <string>
#include "Subaccount.h"

	
Subaccount::Subaccount(int trans, int ab)
	: transaction{ trans }, accountBalance{ ab } {}

Subaccount::~Subaccount() {}


	//functions allows custmer to deposit money. Data validation confirms that the deposit needs to be
	 // a postive number and confirms that the balance doesnt exceed a 32-bit signed integer
	bool Subaccount::setDeposit(int deposit) {
		if (deposit > 0) {
			int tempbalance{ 0 };
			tempbalance = accountBalance;
			accountBalance = accountBalance + deposit;
			if (tempbalance > 0 && accountBalance < 0 || tempbalance < 0 && deposit >= 2147483647 && accountBalance < 0) {
				std::cout << "Invalid, balance exceeded limit of 32 bit signed integer!" << std::endl;
				accountBalance = tempbalance;
				return false;
			}
			transaction++;
			std::cout << "\nMoney has been deposited!" << std::endl;
			return true;
		}
		else {
			std::cout << "Invalid, Deposits need to be postive numbers!" << std::endl;
			return false;
		}
	}

	//functions allows custmer to withdraw money. Data validation confirms that the withdrawal needs to be
	// a postive number and confirms that the balance doesnt exceed a 32-bit signed integer
	bool Subaccount::setWithdrawal(int withdraw) {
		if (withdraw > 0) {
			int tempbalance{ 0 };
			tempbalance = accountBalance;
			accountBalance = accountBalance - withdraw;
			if (tempbalance < 0 && accountBalance > 0) {
				std::cout << "Invalid, balance exceeded limit of 32 bit signed integer!" << std::endl;
				accountBalance = tempbalance;
				return false;
			}
			transaction++;
			std::cout << "\nMoney has been withdrawed!" << std::endl;
			return true;
		}
		else {
			std::cout << "Invalid, Deposits need to be postive numbers!" << std::endl;
			return false;
		}
	}

	//Returns the account balance
	int Subaccount::getBalance() const {
		return accountBalance;
	}

	int Subaccount::getTransactions() const {
		return transaction;
	}