#include <iostream>
#include <string>
#include "Cleric.h"
#include "Rogue.h"
#include "Warrior.h"
#include "Wizard.h"
#include "InvalidInput.h"
#include "Goblin.h"

using namespace std;

//Function Prototypes
void validateUserInputInt(int&, int);

int main()
{
	//Declare variables
	int selection1 = 0, selection2 = 0, selection3 = 0;
	string name;

	do
	{
		cout << "Welcome to Ye Old RPG" << endl
			<< "1: Start new game" << endl
			<< "2: Continue saved game" << endl
			<< "3: Exit program" << endl;

		validateUserInputInt(selection1, 3);

		if (selection1 == 1)
		{
			cout << "Name of your character:";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, name);
			cout << "What class would you like to be?" << endl
				<< "1. Warrior" << endl;
			validateUserInputInt(selection2, 1);
			Warrior player(name);
			cout << "As a Warrior, your special ability allows you to do an attack at 2x damage every 5 turns";
			cout << "Starting adventure!" << endl;
			while (player.getHealth() > 0)
			{
				Goblin enemy;
				while (enemy.getHealth() > 0)
				{
					cout << "You encounter a Goblin." << endl
						<< "1. Attack" << endl
						<< "2. Special Ability" << endl;
					validateUserInputInt(selection3, 2);
					if (selection3 == 1)
					{
						player.attack(enemy);
						if (player.getAbilityCooldown() > 0)
							player.setAbilityCooldown(player.getAbilityCooldown() - 1);
					}
					else
						player.specialAbility(enemy);
					if (enemy.getHealth() > 0)
					{
						if (enemy.getAbilityCooldown() == 0)
							enemy.specialAbility(player);
						else
							enemy.attackCharacter(player);
					}
					if (player.getHealth() <= 0)
						break;
				}
				enemy.~Goblin();
			}
			player.~Warrior();
		}

	} while (selection1 != 3);

	system("pause");
	return 0;
}

void validateUserInputInt(int &input, int endRange)
{
	bool done = false; //flag
	do
	{
		try
		{
			cin >> input;
			if (!cin)
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				throw InvalidInput();
			}
			else if (input < 1 || input > endRange)
				throw InvalidInput();
			else
				done = true;
		}
		catch (InvalidInput invalidInputObj)
		{
			cout << invalidInputObj.what() << endl;
		}
	} while (!done);
}
