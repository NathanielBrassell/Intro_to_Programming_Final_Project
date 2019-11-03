#include "Goblin.h"

template <class T>
void Goblin::specialAbility(T target)
{
	int dmg;
	dmg = this->attack * 2;
	target.setHealth(target.getHealth() - dmg);
}

Goblin::Goblin()
{
	health = 20;
	attack = 8;
	defence = 2;
}


Goblin::~Goblin()
{
}
