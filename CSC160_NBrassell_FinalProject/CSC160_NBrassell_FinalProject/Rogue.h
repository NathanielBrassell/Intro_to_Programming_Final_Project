#pragma once
#include "PlayerCharacter.h"
class Rogue :
	public PlayerCharacter
{
public:
	void specialAbility();
	Rogue(string);
	~Rogue();
};