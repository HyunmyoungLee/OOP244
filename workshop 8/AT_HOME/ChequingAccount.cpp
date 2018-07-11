// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file implements the ChequingAccount class
///////////////////////////////////////////////////

#include "ChequingAccount.h"

using namespace std;

namespace sict {
	// constructor initializes balance and transaction fee
	//
	ChequingAccount::ChequingAccount(double balance, double TF, double MF) : Account(balance){
		if(TF > 0 && MF > 0){
			TransactionFee = TF;
			MonthFee = MF;
		}else{
			TransactionFee = 0;
			MonthFee = 0;
		}
	}


	// credit (add) an amount to the account balance and charge fee
	bool ChequingAccount::credit(double amount){
		if(amount > 0){
			Account::credit(amount);
			Account::debit(TransactionFee);
			return true;
		}else{
			return false;
		}
	}

	// debit (subtract) an amount from the account balance and charge fee
	// returns bool indicating whether money was debited
	//
	bool ChequingAccount::debit(double amount){
		if(amount > 0 && Account::balance() >= amount){
			Account::debit(amount);
			Account::debit(TransactionFee);
			return true;
		}else{
			return false;
		}
	}


	// monthEnd debits month end fee
	//
	
	void ChequingAccount::monthEnd(){
		debit(MonthFee);
	}


	// display inserts account information into ostream os
	//
	
	void ChequingAccount::display(std::ostream& os) const{
		os.setf(ios::fixed);
		os.precision(2);

		os << "Account type: Chequing" << endl;
		os << "Balance: $" << Account::balance() << endl;
		os << "Per Transaction Fee: " << TransactionFee << endl;
		os << "Monthly Fee: " << MonthFee << endl;
	}
}
