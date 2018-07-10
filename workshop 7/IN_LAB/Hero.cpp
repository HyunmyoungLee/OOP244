#include <iostream>
#include <cstring>
#include "Hero.h"
using namespace std;

namespace sict{
	Hero::Hero(){
		Name[0] = '\0';
		Health = 0;
		Attack = 0;
	}

	Hero::Hero(const char* name, int health, int attack){
		if(name[0] == '\0' || health == 0 || attack == 0){
			Name[0] = '\0';
			Health = 0;
			Attack = 0;
		}else{
			strcpy(Name, name);
			Health = health;
			Attack = attack;
		}
	}

	void Hero::operator-=(int attack){
		if(attack > 0){
			if(Health > 0){
				Health -= attack;
				if(!isAlive()){
					Health = 0;
				}
			}else{
				Health = 0;
			}
		}
	}

	bool Hero::isAlive() const{
		if(Health > 0)
			return true;
		else
			return false;
	}

	int Hero::attackStrength() const{
		if(Attack > 0)
			return Attack;
		else
			return 0;
	}

	ostream& operator<<(ostream& os, const Hero& hero){
		if(hero.Name[0]== '\0'){
			os << "No hero";
		}else{
			os << hero.Name;
		}
		return os;
	}

	const Hero& operator*(const Hero& first, const Hero& second){
		const Hero* Winner = nullptr;
		Hero First = first;
		Hero Second = second;
		int count  = 0;
		cout << "Ancient Battle! " << First << " vs " << Second << " : ";
		for(int i = 0 ; i < max_rounds; i++){
			count++;

			First -= Second.attackStrength();
			Second -= First.attackStrength();
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


