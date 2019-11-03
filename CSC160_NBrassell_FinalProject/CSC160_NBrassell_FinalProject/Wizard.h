#pragma once
#include "PlayerCharacter.h"
class Wizard :
	public PlayerCharacter
{
public:
	void specialAbility();
	Wizard(string);
	~Wizard();
};