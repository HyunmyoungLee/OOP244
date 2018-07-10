#include "SuperHero.h"
using namespace std;

namespace sict{
	SuperHero::SuperHero(){
		S_AttackBonus = 0;
		S_Defend = 0;
	}

	SuperHero::SuperHero(const char* name, int health, int attack, int bonus, int defend) : Hero(name, health, attack){
		S_AttackBonus = bonus;
		S_Defend = defend;
	}

	int SuperHero::attackStrength() const{
		return Hero::attackStrength() + S_AttackBonus;
	}

	int SuperHero::defend() const{
		return S_Defend;
	}

	const SuperHero& operator*(const SuperHero& first, const SuperHero& second){
		const SuperHero* Winner = nullptr;
		SuperHero First = first;
		SuperHero Second = second;

		cout << "Super Fight! " << First << " vs " << Second << " : ";
		
		int count = 0;

		for(int i = 0 ; i < max_rounds; i++){
			count++;

			First -= (Second.attackStrength() - First.defend());
			Second -= (First.attackStrength() - Second.defend());

			if(!First.isAlive()){
				Winner = &second;
				break;
			}else if(!Second.isAlive()){
				Winner = &first;
				break;
			}else if(!First.isAlive() && !Second.isAlive()){
				Winner = &first;
				break;
			}
		}

		cout << "Winner is " << *Winner << " in " << count << " rounds." << endl;
		return *Winner;
	}
}

		


