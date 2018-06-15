#include <iostream>
#include <cstring>
#include "Passenger.h"
using namespace std;

namespace sict{

	Passenger::Passenger(){
		Name[0] = '\0';
		Destination[0] = '\0';
	}

	Passenger::Passenger(const char* name, const char* destination){
		if(name != nullptr && destination != nullptr){
			strcpy(Name, name);
			strcpy(Destination, destination);
		}else{
			Name[0] = '\0';
			Destination[0] = '\0';
		}
	}

	bool Passenger::isEmpty() const{
	       if(Name[0] == '\0' || Destination[0] == '\0')
		       return true;
	       else
		       return false;
	}

	void Passenger::display() const{
		if(!isEmpty()){
			cout << Name <<" - " << Destination << endl;
		}else{
			cout << "No passenger!" << endl;
		}
	}
}
