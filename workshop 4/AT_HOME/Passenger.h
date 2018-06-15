#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H
#define SIZE 32

namespace sict{
	class Passenger{
		char Name[SIZE];
		char Destination[SIZE];
		int YearOfDeparture;
		int MonthOfDeparture;
		int DayOfDeparture;
	
		public:
			Passenger();
			Passenger(const char*, const char*);
			Passenger(const char*, const char*, int, int, int);
			const char* name() const;
			bool canTravelWith(const Passenger&) const;
			bool isEmpty() const;
			void display() const;

		};
}

#endif
