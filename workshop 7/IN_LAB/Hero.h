#ifndef SICT_HERO_H
#define SICT_HERO_H
#include <iostream>

#define max_rounds 100
#define SIZE 40
namespace sict{
	class Hero{
		char Name[SIZE];
		int Health;
		int Attack;
	public:
		Hero();
		Hero(const char*, int, int);
		void operator-=(int attack);
		bool isAlive() const;
		int attackStrength() const;
		friend std::ostream& operator<<(std::ostream& os, const Hero& her);
	};

	const Hero& operator*(const Hero& first, const Hero& second);
}

	
#endif
