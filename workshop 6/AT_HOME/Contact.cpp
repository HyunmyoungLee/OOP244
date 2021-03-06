#include <iostream>
#include <cstring>
#include "Contact.h"
using namespace std;

namespace sict{
	Contact::Contact(){
		Name[0] = '\0';
		PhoneNumber = nullptr;
		Count = 0;
	}

	Contact::Contact(const char* name, const long long* num, int size){
		int count = 0;

		if(name == nullptr && strcmp(name, "") == 0 && Name[0] == '\0'){
			Contact();
		//	Name[0] = '\0';
		//	PhoneNumber = nullptr;
		//	Count = 0;
		}else{
			strncpy(Name, name, SIZE-1);
			PhoneNumber = new long long[size];

			for(int i = 0 ; i < size ; i++){
				int countryCode = num[i] / 10000000000;
				int areaCode = num[i]/10000000%1000;
				int number = num[i] % 10000000;

				if( (countryCode >= 1 &&  countryCode <= 99) && (areaCode >= 100 && areaCode <= 999) && ( number >= 1000000 && number <= 9999999) ){
					PhoneNumber[count] = num[i];
					count++;
				}
			}
			Count = count;
		}
				
	}

	Contact::~Contact(){
		delete[] PhoneNumber;
	}

	bool Contact::isEmpty() const{
		if(Name[0] == '\0' || strcmp(Name, "") == 0 || Name == nullptr && PhoneNumber == nullptr && Count == 0)
			return true;
		else
			return false;
	}

	void Contact::display() const{
		if(isEmpty()){
			cout << "Empty contact!" << endl;
		}else{
			cout << Name << endl;
			for(int i = 0 ; i < Count ; i++){
				int countryCode = PhoneNumber[i] / 10000000000;
				int areaCode = PhoneNumber[i] / 10000000 % 1000;
				int number = PhoneNumber[i] % 10000000;
				int three = number / 10000;
				int four = number % 10000;

				if( (countryCode >= 1 &&  countryCode <= 99) && (areaCode >= 100 && areaCode <= 999) && (number >= 1000000 && number <= 9999999) ){
					
					cout << "(+" << countryCode << ") " << areaCode << ' ' << three << '-';
					cout.setf(ios::fixed);
					cout.width(4);
					cout.fill('0');
				       	cout << four << endl;
				}
			}
		}
	}
	
	Contact::Contact(const Contact& ref){
			*this = ref;
	}

	Contact& Contact::operator=(const Contact& ref){
		if( this != &ref){
			strcpy(Name, ref.Name);
			Count = ref.Count;
			PhoneNumber = new long long[Count];
			for(int i = 0 ; i < Count ; i++){
				PhoneNumber[i] = ref.PhoneNumber[i];
			}
		}
		return *this;
	}

	Contact& Contact::operator+=(long long newNumber){
		
		long long* COPY = nullptr;

		int countryCode = newNumber / 10000000000;
		int areaCode = newNumber / 10000000 % 1000;
		int number = newNumber % 10000000;

		if( (countryCode >= 1 && countryCode <= 99) && (areaCode >= 100 && areaCode <= 999) && (number >= 1000000 && number <= 9999999) ){
			COPY = new long long[Count];
			for(int i = 0 ; i < Count ; i++){
				COPY[i] = PhoneNumber[i];
			}

			delete[] PhoneNumber;
			PhoneNumber = new long long[Count + 1];

			for(int i = 0 ; i < Count ; i++){
				PhoneNumber[i] = COPY[i];
			}
			
			PhoneNumber[Count] = newNumber;

			Count++;
			delete[] COPY;
		}
		return *this;
		
	}
			
}
