#include <iostream>
#include <cstring>
#include "Passenger.h"
using namespace std;

namespace sict{

	Passenger::Passenger(){
		Name[0] = '\0';
		Destination[0] = '\0';
		YearOfDeparture = 0;
		MonthOfDeparture = 0;
		DayOfDeparture = 0;
	}

	Passenger::Passenger(const char* name, const char* destination){
		if(name != nullptr && destination != nullptr){
			strcpy(Name, name);
			strcpy(Destination, destination);
			YearOfDeparture = 2017;
			MonthOfDeparture = 7;
			DayOfDeparture = 1;
		}else{
			Name[0] = '\0';
			Destination[0] = '\0';
			YearOfDeparture = 0;
			MonthOfDeparture = 0;
			DayOfDeparture = 0;
		}
	}
	Passenger::Passenger(const char* name, const char* destination, int year, int month, int day){
		if(name != nullptr && destination != nullptr && ( year >= 2017 && year <= 2020) && (month >= 1 && month <= 12) && (day >= 1 && day <= 31)){
			strcpy(Name, name);
			strcpy(Destination, destination);
			YearOfDeparture = year;
			MonthOfDeparture = month;
			DayOfDeparture = day;
		}else{
			Name[0] = '\0';
			Destination[0] = '\0';
			YearOfDeparture = 0;
			MonthOfDeparture = 0;
			DayOfDeparture = 0;
		}
	}
	const char* Passenger::name() const{
		if(Name[0] != '\0')
			return Name;
	}
	bool Passenger::canTravelWith(const Passenger& ref) const{
		if(YearOfDeparture == ref.YearOfDeparture && MonthOfDeparture == ref.MonthOfDeparture && DayOfDeparture == ref.DayOfDeparture)
			return true;
		else
			return false;
	}

	bool Passenger::isEmpty() const{
	       if(Name[0] == '\0' || Destination[0] == '\0')
		       return true;
	       else
		       return false;
	}

	void Passenger::display() const{
		if(!isEmpty()){
			cout << Name <<" - " << Destination << " on " << YearOfDeparture << "/";
			if(MonthOfDeparture < 10){
				cout.setf(ios::fixed);
				cout.width(2);
				cout.fill('0');
			}
			cout << MonthOfDeparture << "/";
			
			
			if(DayOfDeparture < 10){
				cout.setf(ios::fixed);
				cout.width(2);
				cout.fill('0');
			}
			cout <<DayOfDeparture <<  endl;
		}else{
			cout << "No passenger!" << endl;
		}
	}
}
