#pragma once
#include "Character.h"
#include "PlayerCharacter.h"
class EnemyCharacter :
	public Character
{
protected:
	int attack, defence;
public:
	//Getters and Stetters
	int getAttack() { return attack; }
	int getDefence() { return defence; }

	void setAttack(int a) { attack = a; }
	void setDefence(int d) { defence = d; }

	void defend();
	template <class T>
	void attackCharacter(T target);

	~EnemyCharacter();
};