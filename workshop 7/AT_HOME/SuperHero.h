#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H
#include "Hero.h"

namespace sict{
	class SuperHero : public Hero {
		int S_AttackBonus;
		int S_Defend;
	public:
		SuperHero();
		SuperHero(const char* , int, int, int, int);
		int attackStrength() const;
		int defend() const;
	};

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second);
		
}

#endif
