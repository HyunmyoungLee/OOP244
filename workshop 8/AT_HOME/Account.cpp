#include "Account.h"

namespace sict{
	double Account::balance() const{
		return Balance;
	}
	
	Account::Account(double balance){
		if(balance > 0)
			Balance = balance;
		else
			Balance = 0;
	}

	bool Account::credit(double amount){
		if(amount > 0){
			Balance += amount;
			return true;
		}else{
			return false;
		}
	}

	bool Account::debit(double amount){
		if(amount > 0 && Balance >= amount){
			Balance -= amount;
			return true;
		}else{
			return false;
		}
	}
}
