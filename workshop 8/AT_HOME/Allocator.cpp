#include "SavingsAccount.h" 
#include "ChequingAccount.h"
namespace sict {

	// define interest rate
	//
	double Rate = 0.05;
	double TF = 0.50;
	double MF = 2.00;

	// TODO: Allocator function
	//
	iAccount* CreateAccount(const char* account, double balance){
		iAccount* create = nullptr;

		if(account[0] == 'S'){
			create = new SavingsAccount(balance, Rate);
			return create;
		}else if(account[0] == 'C'){
			create = new ChequingAccount(balance, TF, MF);
			return create;
		}else{
			return nullptr;
		}
	}
}
