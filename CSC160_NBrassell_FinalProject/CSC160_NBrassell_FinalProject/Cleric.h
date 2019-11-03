#pragma once
#include "PlayerCharacter.h"
class Cleric :
	public PlayerCharacter
{
public:
	void specialAbility();
	Cleric(string);
	~Cleric();
};