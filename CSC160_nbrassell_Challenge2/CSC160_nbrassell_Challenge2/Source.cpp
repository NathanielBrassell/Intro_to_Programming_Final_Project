#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;



void displayResults(int, double, string);
int selectionValidation(int);

int main()
{
	//Declare variables
	double level000Cost, level100Cost, level200Cost;
	int numberOfCreditHours, selection;

	//Read class costs from file and initailize cost variables
	ifstream infile;
	infile.open("tuitionAmounts.txt");
	infile >> level000Cost >> level100Cost >> level200Cost;
	infile.close();

	//Program header
	cout << "CCA Tuition Program" << endl
		<< "-------------------------" << endl;

	//Loop menu
	do
	{
		//Get class level
			cout << "\n1. 000 Level Courses" << endl
			<< "2. 100 Level Courses" << endl
			<< "3. 200 Level Courses" << endl
			<< "4. Exit Program" << endl
			<< "Select the course level or Exit: ";
		cin >> selection;

		//Validate selection
		selection = selectionValidation(selection);

		//Menu system
		switch (selection)
		{
		case 1:
			cout << "\nEnter the number of credit hours for this semester: ";
			cin >> numberOfCreditHours;
			displayResults(numberOfCreditHours, level000Cost, "000");
			break;
		case 2:
			cout << "\nEnter the number of credit hours for this semester: ";
			cin >> numberOfCreditHours;
			displayResults(numberOfCreditHours, level100Cost, "100");
			break;
		case 3:
			cout << "\nEnter the number of credit hours for this semester: ";
			cin >> numberOfCreditHours;
			displayResults(numberOfCreditHours, level200Cost, "200");
			break;
		default:
			break;
		}

	} while (selection != 4);

	system("pause");
	return 0;
}

int selectionValidation(int input)
{

	while (input < 1 || input > 4)
	{
		cout << "\nPlease enter" << endl
			<< "1 for 000 level courses" << endl
			<< "2 for 100 level courses" << endl
			<< "3 for 200 level courses" << endl
			<< "4 to exit program: ";
		cin >> input;
	}


	return input;
}

void displayResults(int creditHours, double classCost, string selected)
{
	ofstream outFile;
	outFile.open("TuitionReportResults.txt");
	double yearCost;
	yearCost = creditHours * classCost * 2;
	cout << fixed << showpoint << setprecision(2) << left;
	cout << "\nCommunity College of Aurora Tuition Report" << endl
		<< "             " << selected << "            " << endl
		<< "---------------------------------------------" << endl
		<< "Year                      Tuition" << endl
		<< "----                      -------" << endl
		<< "Year 1                    $" << yearCost << endl;

	outFile << "\nCommunity College of Aurora Tuition Report" << endl
		<< "            " << selected << "            " << endl
		<< "---------------------------------------------" << endl
		<< "Year                      Tuition" << endl
		<< "----                      -------" << endl
		<< "Year 1                    $" << yearCost << endl;
	
	for (int i = 0; i < 5; i++)
	{
		yearCost = yearCost + (yearCost * 0.02);
		cout << "Year " << i + 2 << "                    $" << yearCost << endl;
		outFile << "Year " << i + 2 << "                    $" << yearCost << endl;
	}
}