#pragma once
#include "PlayerCharacter.h"
class Warrior :
	public PlayerCharacter
{
private:
	string name;
public:
	template <class T>
	void specialAbility(T target);
	Warrior(string);
	~Warrior();
};