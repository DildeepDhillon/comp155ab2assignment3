#pragma once

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "CustomerAccount.h"



	//Account constructor that initializes account values
	CustomerAccount::CustomerAccount(int accountNum, BankCustomer customer)
		: accountNumber{ accountNum }, accountStatus{ "OPEN" }, dateOpen{ "09/22/2022" }, branchNumber{ "001" } {

	}

	//function to set account status, data validation code make sure status can only be updated if acceptable
	bool CustomerAccount::setStatus(std::string status) {
		std::transform(status.begin(), status.end(), status.begin(), ::toupper);
		if (status == "OPEN" || status == "CLOSED" || status == "FROZEN") {
			if (accountStatus == "OPEN" && status == "CLOSED" || status == "FROZEN") {
				accountStatus = status;
				std::cout << "\nAccount status has been set!" << std::endl;
				return true;
			}
			else if (accountStatus == "FROZEN" && status == "OPEN" || status == "CLOSED") {
				accountStatus = status;
				std::cout << "\nAccount status has been set!" << std::endl;
				return true;
			}
			else if (accountStatus == "CLOSED") {
				std::cout << "\nAccount is already closed. Cannot change account status!" << std::endl;
				return false;
			}
		}
		else {
			std::cout << "\nInvalid input, account status options are only open, frozen or closed!" << std::endl;
			return false;
		}
		return false;
	}

	//functions allows custmer to deposit money. Data validation confirms that the deposit needs to be
	 // a postive number and confirms that the balance doesnt exceed a 32-bit signed integer
	bool CustomerAccount::setDeposit(int deposit) {
		if (deposit > 0) {
			int tempbalance{ 0 };
			tempbalance = accountBalance;
			accountBalance = accountBalance + deposit;
			if (tempbalance > 0 && accountBalance < 0 || tempbalance < 0 && deposit >= 2147483647 && accountBalance < 0) {
				std::cout << "Invalid, balance exceeded limit of 32 bit signed integer!" << std::endl;
				accountBalance = tempbalance;
				return false;
			}
			std::cout << "Money has been deposited;" << std::endl;
			return true;
		}
		else {
			std::cout << "Invalid, Deposits need to be postive numbers!" << std::endl;
			return false;
		}
	}

	//functions allows custmer to withdraw money. Data validation confirms that the withdrawal needs to be
	// a postive number and confirms that the balance doesnt exceed a 32-bit signed integer
	bool CustomerAccount::setWithdrawal(int withdraw) {
		if (withdraw > 0) {
			int tempbalance{ 0 };
			tempbalance = accountBalance;
			accountBalance = accountBalance - withdraw;
			if (tempbalance < 0 && accountBalance > 0) {
				std::cout << "Invalid, balance exceeded limit of 32 bit signed integer!" << std::endl;
				accountBalance = tempbalance;
				return false;
			}
			std::cout << "Money has been withdrawed;" << std::endl;
			return true;
		}
		else {
			std::cout << "Invalid, Deposits need to be postive numbers!" << std::endl;
			return false;
		}
	}

	//Returns the account balance
	int CustomerAccount::getBalance() const {
		return accountBalance;
	}

	//Returns the account status
	std::string CustomerAccount::getAccountStatus() const {
		return accountStatus;
	}

	void CustomerAccount::AddSubAccount(Subaccount* name) {
		vectorSub.push_back(name);
	}

	bool CustomerAccount::RemoveSubAccount() {
		Subaccount* s = vectorSub.back();
		if (s->getTransactions() == 0) {
			std::cout << "Subaccount " << vectorSub.size() << " has been removed." << std::endl;
			vectorSub.pop_back();
			s->~Subaccount();
			return true;
		}
		else {
			std::cout << "Subaccount " << vectorSub.size() << " cannot be removed, as transactions have occured!" << std::endl;
			return false;
		}
	}



	//Returns the account number, account number does not need a set function, since it gets set by the
	//constructor and will not change
	int CustomerAccount::getAccountNumber() const {
		return accountNumber;
	}

	//Returns the date for when the account opened, does not need a set function, since it will not change once initialized
	std::string CustomerAccount::getDateOpened() const {
		return dateOpen;
	}

	void CustomerAccount::getVectorSub() const {
		int size = vectorSub.size();
		std::cout << "\nSelect which subaccount you want to manage." << std::endl;
		for (int i = 1; i <= size; i++) {
			std::cout << i << ") " << "Subaccount " << i << std::endl;
		}
	}