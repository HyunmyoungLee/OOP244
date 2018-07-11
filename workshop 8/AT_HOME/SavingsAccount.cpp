#include "SavingsAccount.h"
#include <iostream>
using namespace std;

namespace sict{
	SavingsAccount::SavingsAccount(double balance, double rate) : Account(balance){
		if(rate > 0)
			InterestRate = rate;
		else
			InterestRate = 0;
	}

	void SavingsAccount::monthEnd(){
		Account::credit(Account::balance() * InterestRate);
	}

	void SavingsAccount::display(std::ostream& os) const{
		os.setf(ios::fixed);
		os.precision(2);

		os << "Account type: Savings" << endl;
		os << "Balance: $" << Account::balance() << endl;
		os << "Interest Rate (%): " << InterestRate * 100 << endl;
	}

}
