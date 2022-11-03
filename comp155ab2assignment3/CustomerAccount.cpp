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
				return true;
			}
			else if (accountStatus == "FROZEN" && status == "OPEN" || status == "CLOSED") {
				accountStatus = status;
				return true;
			}
			else if (accountStatus == "CLOSED") {
				std::cout << "Account is already closed. Cannot change account status!" << std::endl;
				return false;
			}
		}
		else {
			std::cout << "Invalid input, account status options are only open, frozen or closed!" << std::endl;
			return false;
		}
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