#pragma once
#include "EnemyCharacter.h"
class Goblin :
	public EnemyCharacter
{
public:
	template <class T>
	void specialAbility(T target);
	Goblin();
	~Goblin();
};