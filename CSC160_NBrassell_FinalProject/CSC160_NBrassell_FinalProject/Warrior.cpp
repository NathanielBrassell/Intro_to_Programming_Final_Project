#include "Warrior.h"

template <class T>
void Warrior::specialAbility(T target)
{
	int dmg;
	dmg = this->strength - target.getDefence();
	dmg *= 2;
	target.setHealth(target.getHealth() - dmg);
}

Warrior::Warrior(string name)
{
	strength = 10;
	health = 100;
	abilityCooldown = 0;
	this->name = name;
}

Warrior::~Warrior()
{
}