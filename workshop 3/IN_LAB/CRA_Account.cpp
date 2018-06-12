#include <iostream>
#include <cstring>
#include "CRA_Account.h"
using namespace std;

namespace sict{
	void CRA_Account::set(const char* familyName, const char* givenName, int sin){
		if(sin >= min_sin && sin <= max_sin){
			strncpy(FamilyName, familyName, max_name_length);
			strncpy(GivenName, givenName, max_name_length);
			SIN = sin;
		}else{
			FamilyName[0] = '\0';
			GivenName[0] = '\0';
			SIN = 0;
		}
	}

	bool CRA_Account::isEmpty() const{
		if(SIN >= min_sin && SIN <= max_sin){
			return false;
		}else{
			return true;
		}
	}

	void CRA_Account::display() const{
		if(!isEmpty()){
			cout << "Family Name: " << FamilyName << endl;
			cout << "Given Name: " << GivenName << endl;
			cout << "CRA Account: " << SIN << endl;
		}else{
			cout << "Account object is empty!" << endl;
		}
	}
}
