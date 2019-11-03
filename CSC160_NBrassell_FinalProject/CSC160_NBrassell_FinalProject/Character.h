#pragma once
#include <string>
using namespace std;
class Character
{
protected:
	string name;
	int health, abilityCooldown;
public:
	//Getters and Setters
	string getName() { return name; }
	int getHealth() { return health; }
	int getAbilityCooldown() { return abilityCooldown; }

	void setName(string n) { name = n; }
	void setHealth(int h) { health = h; }
	void setAbilityCooldown(int a) { abilityCooldown = a; }

	virtual void defend() = 0;

	~Character();
};