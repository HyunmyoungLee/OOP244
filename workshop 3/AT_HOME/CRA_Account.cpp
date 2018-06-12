#include <iostream>
#include <cstring>
#include "CRA_Account.h"
using namespace std;

namespace sict{
	void CRA_Account::set(int year, double balance){
		if(!isEmpty()){
				TaxReturnYear[NumOfYear] = year;
				BalanceOrRefund[NumOfYear] = balance;
				NumOfYear++;
			
		}
	}

	void CRA_Account::set(const char* familyName, const char* givenName, int sin){
		if(isEmpty()){
			strncpy(FamilyName, familyName, max_name_length);
			strncpy(GivenName, givenName, max_name_length);
			SIN = sin;
			NumOfYear = 0;
		}else{
			FamilyName[0] = '\0';
			GivenName[0] = '\0';
			SIN = 0;
		}
	}

	bool CRA_Account::isEmpty() const{
		int CheckDigit = SIN%10;
		int Alt1[4] = {(SIN/10%10), (SIN/1000%10), (SIN/100000%10), (SIN/10000000%10)};
		int Alt2[4] = {(SIN/100%10), (SIN/10000%10), (SIN/1000000%10), (SIN/100000000%10)};
		int Alt1_Total = 0 , Alt2_Total = 0;
		for(int i = 0 ; i < 4 ; i++){
			Alt1_Total += ((Alt1[i]/10%10) + (Alt1[i]/1%10));
			Alt2_Total += Alt2[i];
		}

		int Total = Alt1_Total + Alt2_Total;
		int Next_Highest_integer = 10 * ((Total/10)+1);
		int Gap = Next_Highest_integer - Total;
			

		if(CheckDigit != Gap || SIN < min_sin || SIN > max_sin || FamilyName[0] == '\0' || GivenName[0] == '\0'){
			return true;
		}else{
			return false;
		}
	}

	void CRA_Account::display() const{
		if(!isEmpty()){
			cout << "Family Name: " << FamilyName << endl;
			cout << "Given Name: " << GivenName << endl;
			cout << "CRA Account: " << SIN << endl;
			for(int i = 0 ; i < max_yrs; i++){
				if(BalanceOrRefund[i] > 2){
					cout.setf(ios::fixed);
					cout.precision(2);

					cout << "Year (" << TaxReturnYear[i] << ") balance owing: " << BalanceOrRefund[i] << endl;
				}else if(BalanceOrRefund[i] < -2){
					cout.precision(2);

					cout << "Year (" << TaxReturnYear[i] << ") refund due: " << BalanceOrRefund[i] * (-1) << endl;
				}else{
					cout << "Year (" << TaxReturnYear[i] << ") No balance owing or refund due!" << endl;
				}
			}

		}else{
			cout << "Account object is empty!" << endl;
		    }
	
		}	
}	
