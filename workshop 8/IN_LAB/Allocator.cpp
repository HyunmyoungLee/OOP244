#include "SavingsAccount.h" 

namespace sict {

	// define interest rate
	//
	double Rate = 0.05;


	// TODO: Allocator function
	//
	iAccount* CreateAccount(const char* account, double balance){
		iAccount* create = nullptr;

		if(account[0] == 'S'){
			create = new SavingsAccount(balance, Rate);
			return create;
		}else{
			return nullptr;
		}
	}
}
