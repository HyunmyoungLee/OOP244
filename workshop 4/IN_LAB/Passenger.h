#ifndef SICT_PASSENGER_H
#define SICT_PASSENGER_H
#define SIZE 32

namespace sict{
	class Passenger{
		char Name[SIZE];
		char Destination[SIZE];
	
		public:
			Passenger();
			Passenger(const char*, const char*);
			bool isEmpty() const;
			void display() const;
		};
}

#endif
