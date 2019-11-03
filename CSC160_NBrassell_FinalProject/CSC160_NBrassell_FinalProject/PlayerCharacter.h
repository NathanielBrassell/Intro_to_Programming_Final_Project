#pragma once
#include "Character.h"
#include "Structs.h"
#include "EnemyCharacter.h"
class PlayerCharacter :
	public Character
{
protected:
	int strength, intelligence, wisdom, dexterity;
	weapon myWeapon;
	armor myArmor;
public:
	//Getters and Setters
	int getStrength() { return strength; }
	int getIntelligence() { return intelligence; }
	int getWisdom() { return wisdom; }
	int getDexterity() { return dexterity; }
	weapon getWeapon() { return myWeapon; }
	armor getArmor() { return myArmor; }

	void setStrength(int s) { strength = s; }
	void setIntelligence(int i) { intelligence = i; }
	void setWisdom(int w) { wisdom = w; }
	void setDexterity(int d) { dexterity = d; }
	void setWeapon(weapon w) { myWeapon = w; }
	void setArmor(armor a) { myArmor = a; }

	void defend();
	template <class T>
	void attack(T target);

	~PlayerCharacter();
};