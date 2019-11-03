#include "PlayerCharacter.h"


void PlayerCharacter::defend()
{
}

template <class T>
void PlayerCharacter::attack(T target)
{
	int dmg;
	dmg = this->strength - target.getDefence();
	target.setHealth(target.getHealth() - dmg);
}

PlayerCharacter::~PlayerCharacter()
{
}