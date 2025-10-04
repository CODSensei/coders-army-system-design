#include<iostream>
#include<vector>
using namespace std;

// class Account {
// public:
// 	virtual void deposit(double amount) = 0;
// 	virtual void withdraw(double amount) = 0;
// };

// better approach
class DepositOnlyAccount {
public:
	virtual void deposit(double amount) = 0;
};

class WithdrawableAccount: public DepositOnlyAccount{
public:
	virtual void withdraw(double amount) = 0;
};

// class SavingAccount: public Account {
// private:
// 	double balance;
// public:
// 	SavingAccount() {
// 		balance = 0;
// 	}
//
// 	void deposit(double amount) {
// 		balance += amount;
// 		cout << "Deposited: " << amount << " in Savings Account. New Balance: " << balance << endl;
// 	}
// 	void withdraw(double amount) {
// 		if (balance >= amount) {
// 			balance -= amount;
// 			cout << "Withdraw: " << amount << " from Savings Account. New Balance: " << balance << endl;
// 		} else {
// 			cout << "Insufficient Balance in Savings Account!\n";
// 		}
// 	}
// };
class SavingAccount: public WithdrawableAccount{
private:
	double balance;
public:
	SavingAccount() {
		balance = 0;
	}

	void deposit(double amount) {
		balance += amount;
		cout << "Deposited: " << amount << " in Savings Account. New Balance: " << balance << endl;
	}
	void withdraw(double amount) {
		if (balance >= amount) {
			balance -= amount;
			cout << "Withdraw: " << amount << " from Savings Account. New Balance: " << balance << endl;
		} else {
			cout << "Insufficient Balance in Savings Account!\n";
		}
	}
};

// class CurrentAccount: public Account {
// private:
// 	double balance;
// public:
// 	CurrentAccount() {
// 		balance = 0;
// 	}
//
// 	void deposit(double amount) {
// 		balance += amount;
// 		cout << "Deposited: " << amount << " in Current Account. New Balance: " << balance << endl;
// 	}
// 	void withdraw(double amount) {
// 		if (balance >= amount) {
// 			balance -= amount;
// 			cout << "Withdraw: " << amount << " from Current Account. New Balance: " << balance << endl;
// 		} else {
// 			cout << "Insufficient Balance in Current Account!\n";
// 		}
// 	}
// }

class CurrentAccount: public WithdrawableAccount{
private:
	double balance;
public:
	CurrentAccount() {
		balance = 0;
	}

	void deposit(double amount) {
		balance += amount;
		cout << "Deposited: " << amount << " in Current Account. New Balance: " << balance << endl;
	}
	void withdraw(double amount) {
		if (balance >= amount) {
			balance -= amount;
			cout << "Withdraw: " << amount << " from Current Account. New Balance: " << balance << endl;
		} else {
			cout << "Insufficient Balance in Current Account!\n";
		}
	}
};


// class FDAccount: public Account {
// private:
// 	double balance;
// public:
// 	FDAccount() {
// 		balance = 0;
// 	}
//
// 	void deposit(double amount) {
// 		balance += amount;
// 		cout << "Deposited: " << amount << " in FD Account. New Balance: " << balance << endl;
// 	}
// 	void withdraw(double amount) {
// 		throw logic_error("Withdrawl not allowed in FD Account");
// 	}
// };

class FDAccount: public DepositOnlyAccount {
private:
	double balance;
public:
	FDAccount() {
		balance = 0;
	}

	void deposit(double amount) {
		balance += amount;
		cout << "Deposited: " << amount << " in FD Account. New Balance: " << balance << endl;
	}
};

// class BankClient {
// private:
// 	vector<Account*> accounts;
// public:
// 	BankClient(vector<Account*> accounts) {
// 		this->accounts = accounts;
// 	}
//
// 	void processTransactions() {
// 		for(Account* acc: accounts){
// 			acc->deposit(1000);
//
// 			// try {
// 			// 	acc->withdraw(500);
// 			// } catch (const logic_error& e) {
// 			// 	cout << "Exception: " << e.what() << endl;
// 			// }
//
// 			// bad way to fix
// 			if (typeid(*acc) == typeid(FDAccount)){
// 				cout << "Skipping Withdrawl for FD Account.\n";
// 			} else {
// 				try {
// 					acc->withdraw(500);
// 				} catch (const logic_error& e) {
// 					cout << "Exception: " << e.what() << endl;
// 				}
// 			}
// 		}
// 	}
// };

class BankClient {
private:
	vector<WithdrawableAccount*> withdrawableAccounts;
	vector<DepositOnlyAccount*> depositOnlyAccounts;
public:
	BankClient(vector<WithdrawableAccount*> withdrawableAccounts, vector<DepositOnlyAccount*> depositOnlyAccounts) {
		this->withdrawableAccounts = withdrawableAccounts;
		this->depositOnlyAccounts = depositOnlyAccounts;
	}

	void processTransactions() {
		for(WithdrawableAccount* acc: withdrawableAccounts) {
			acc->deposit(1000);
			acc->withdraw(500);
		}
		for(DepositOnlyAccount* acc: depositOnlyAccounts) {
			acc->deposit(5000);
		}
	}
};

int main() {
	vector<WithdrawableAccount*> withdrawableAccounts;
	withdrawableAccounts.push_back(new SavingAccount());
	withdrawableAccounts.push_back(new CurrentAccount());

	vector<DepositOnlyAccount*> depositOnlyAccounts;
	depositOnlyAccounts.push_back(new FDAccount());

	BankClient* client = new BankClient(withdrawableAccounts, depositOnlyAccounts);
	client -> processTransactions();

	return 0;
}
