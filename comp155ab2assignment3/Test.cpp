#include <iostream>
#include "CustomerAccount.h"
//#include "SubAccount.h"

using namespace std;


int main() {
	BankCustomer customer1{ "Jane Doe" };

	CustomerAccount account1{ 10000, customer1 };

	cout << customer1.getName() << " account status is " << account1.getAccountStatus() << endl;

	customer1.setPhone("7788889252", "", "");

	account1.setStatus("closed");

	customer1.setAddress("8455 115A ST", "");

	customer1.setCity("Surrey");

	customer1.setPostal("v3v1t2");

	cout << customer1.getName() << " account address is " << customer1.getAddress1() << " " << customer1.getCity() << " " << customer1.getProvince() << " and phone number is " << customer1.getwPhone() << endl;

	BankCustomer customer2{ "LOL" };

	customer2.setName("Dildeep Dhillon");

	CustomerAccount account2{ 20000, customer2 };

	cout << customer2.getName() << " account status is " << account2.getAccountStatus() << endl;

	customer2.setPhone("", "", "");

	account2.setStatus("closed");

	account2.setStatus("open");

	customer2.setAddress("", "");

	customer2.setCity("Surrey");

	customer2.setPostal("v3v1t2");

	cout << customer2.getName() << " account address is " << customer2.getAddress1() << " " << customer2.getCity() << " " << customer2.getProvince() << " and phone number is " << customer2.getwPhone() << endl;

	customer2.setPhone("7789182222", "", "");

	customer2.setAddress("9898 120st", "");

	cout << customer2.getName() << " account address is " << customer2.getAddress1() << " " << customer2.getCity() << " " << customer2.getProvince() << " and phone number is " << customer2.getwPhone() << endl;

	Subaccount s1;

	s1.setDeposit(20000);

	account2.AddSubAccount(&s1);

	s1.setDeposit(20000);

	cout << s1.getBalance() << " for subaccount 1" << endl;

	account2.RemoveSubAccount();

	Subaccount s2;

	account2.AddSubAccount(&s2);

	s2.setDeposit(20000);

	s2.setWithdrawal(10000);

	s2.setWithdrawal(100000);

	cout << s2.getBalance() << " for subaccount 2" << endl;

	account2.RemoveSubAccount();

	Subaccount s3;

	account2.AddSubAccount(&s3);

	account2.RemoveSubAccount();

	return 0;
}