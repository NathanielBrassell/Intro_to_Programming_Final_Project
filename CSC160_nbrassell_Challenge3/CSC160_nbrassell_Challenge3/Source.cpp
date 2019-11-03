#include <iostream>
#include <string>

using namespace std;

//Declaring constants
const int SIZE = 10;

//Function Prototypes
void testScoreValidation(int&);
void sortTestScores(string[SIZE], int[SIZE]);
void calcAverageScore(int[SIZE], int&);

int main()
{

	//Declaring varirables
	int testScores[SIZE];
	string studentNames[SIZE];
	int averageScore = 0;

	//Get user input
	for (int i = 0; i < SIZE; i++)
	{
		//Declare temporary vairiables
		int tempTestScore;
		string firstName, lastName, fullName;

		cout << "Please enter the students first name: ";
		cin >> firstName;
		cout << "Please enter the students last name: ";
		cin >> lastName;
		fullName = firstName + " " + lastName;
		studentNames[i] = fullName;
		cout << "Please enter the students test score: ";
		cin >> tempTestScore;
		
		//Validate test score
		testScoreValidation(tempTestScore);

		testScores[i] = tempTestScore;
	}

	sortTestScores(studentNames, testScores);

	calcAverageScore(testScores, averageScore);

	//Display output
	cout << "Stundent Name   Score\n";
	for (int i = 0; i < SIZE; i++)
	{
		cout << studentNames[i] << " " << testScores[i] << endl;
	}
	cout << "The average for the test is " << averageScore << endl;

	system("pause");
	return 0;
}

void testScoreValidation(int &testScore)
{
	while (testScore < 0)
	{
		cout << "Test score cannot be negative. Please re-enter the students test score: ";
		cin >> testScore;
	}
}


//Copied from https://mathbits.com/MathBits/CompSci/Arrays/Bubble.htm
void sortTestScores(string names[SIZE], int scores[SIZE])
{
	int i, j, flag = 1;
	int tempScore;
	string tempName;
	for (i = 1; (i <= SIZE) && flag; i++)
	{
		flag = 0;
		for (j = 0; j < (SIZE - 1); j++)
		{
			if (scores[j + 1] < scores[j])
			{
				tempScore = scores[j];
				scores[j] = scores[j + 1];
				scores[j + 1] = tempScore;
				tempName = names[j];
				names[j] = names[j + 1];
				names[j + 1] = tempName;
				flag = 1;
			}
		}
	}
}

void calcAverageScore(int scores[SIZE], int &average)
{
	for (int i = 1; i < SIZE; i++)
	{
		average += scores[i];
	}
	
	average /= (SIZE - 1);
}
