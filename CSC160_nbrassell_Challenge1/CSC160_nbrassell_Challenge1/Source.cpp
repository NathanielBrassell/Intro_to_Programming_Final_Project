#include <iostream>
#include <iomanip>

using namespace std;

int main()
{

	//Declare and initialize constants
	const double FICA_RATE = 0.06;
	const double FEDERAL_INCOME_TAX_RATE = 0.14;
	const double STATE_INCOME_TAX_RATE = 0.05;
	const double PAY_RATE = 16.78;
	const double OVERTIME_RATE = 1.5;
	const double CCA_FOUNDATION_CONTRIBUTION = 10.00;
	const int HOURS_WORKED_UNTIL_OVERTIME = 40;
	const int NUMBER_OF_DEPENDANTS_UNTIL_EXTRA_HEALTHCARE_COST = 3;
	const int EXTRA_HEALTHCARE_COST = 35;

	//Declare variables
	double grossPay, ficaTax, fedIncomeTax, stateIncomeTax, netPay;
	int employeeNumber, hoursWorked, numberOfDependents, amountOfOvertime;


	//Getting user input
	cout << "CCA Payroll Application\n"
		<< "-----------------------\n";
	cout << "Enter employee SSN (digits only, no spaces or dashes): ";
	cin >> employeeNumber;
	cout << "Please enter the hours worked this week: ";
	cin >> hoursWorked;
	cout << "Enter number of dependents: ";
	cin >> numberOfDependents;

	//Calculating gross pay
	if (hoursWorked > HOURS_WORKED_UNTIL_OVERTIME)
	{
		amountOfOvertime = hoursWorked - HOURS_WORKED_UNTIL_OVERTIME;
		grossPay = (HOURS_WORKED_UNTIL_OVERTIME * PAY_RATE) + (amountOfOvertime * PAY_RATE * OVERTIME_RATE);
	}
	else
	{
		grossPay = hoursWorked * PAY_RATE;
	}

	//Calculating taxes
	ficaTax = grossPay * FICA_RATE;
	fedIncomeTax = grossPay * FEDERAL_INCOME_TAX_RATE;
	stateIncomeTax = grossPay * STATE_INCOME_TAX_RATE;

	//Calculating net pay so far
	netPay = grossPay - ficaTax - fedIncomeTax - stateIncomeTax - CCA_FOUNDATION_CONTRIBUTION;

	//Determining if extra healthcare cost applies and factoring it into net pay if so
	if (numberOfDependents >= NUMBER_OF_DEPENDANTS_UNTIL_EXTRA_HEALTHCARE_COST)
	{
		netPay = netPay - EXTRA_HEALTHCARE_COST;
	}

	//Outpoutting results
	cout << fixed << showpoint << setprecision(2);
	cout << "\nEmployee number: " << employeeNumber << endl
		<< "Hours worked: " << hoursWorked << endl
		<< "Dependents: " << numberOfDependents << endl
		<< "Regular pay rate: $" << PAY_RATE << endl
		<< "Gross pay: $" << grossPay << endl
		<< "FICA tax withheld: $" << ficaTax << endl
		<< "Federal Income Tax withheld: $" << fedIncomeTax << endl
		<< "State Tax withheld: $" << stateIncomeTax << endl
		<< "CCA Foundation Donation withheld: $" << CCA_FOUNDATION_CONTRIBUTION << endl
		<< "Net Pay: $" << netPay << endl;


	system("pause");
	return 0;
}