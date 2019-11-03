#include "EnemyCharacter.h"

void EnemyCharacter::defend()
{
}

template <class T>
void EnemyCharacter::attackCharacter(T target)
{
	int dmg;
	dmg = this->attack;
	target.sethealth(target.getHealth() - dmg);
}

EnemyCharacter::~EnemyCharacter()
{
}