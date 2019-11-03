#include <iostream>
#include <cstring>

using namespace std;

//Funtcion Prototype
void reverseString(char[]);

int main()
{
	//Declare Variables
	char test1[] = "Even";
	char test2[] = "Odd";
	char test3[] = "With space";
	char test4[] = "A longer test statement.";

	//First test
	cout << "First Test" << endl;
	cout << test1 << endl;
	reverseString(test1);
	cout << test1 << endl;
	reverseString(test1);
	cout << test1 << endl;

	//Second test
	cout << "\nSecond Test" << endl;
	cout << test2 << endl;
	reverseString(test2);
	cout << test2 << endl;
	reverseString(test2);
	cout << test2 << endl;

	//Third test
	cout << "\nThird Test" << endl;
	cout << test3 << endl;
	reverseString(test3);
	cout << test3 << endl;
	reverseString(test3);
	cout << test3 << endl;

	//Fourth test
	cout << "\nFourth Test" << endl;
	cout << test4 << endl;
	reverseString(test4);
	cout << test4 << endl;
	reverseString(test4);
	cout << test4 << endl;

	system("pause");
	return 0;
}

void reverseString(char stringToReverse[])
{
	char *front, *rear, temp;
	int frontPos = 0, rearPos;
	rearPos = strlen(stringToReverse) - 1;
	front = stringToReverse;
	rear = stringToReverse;
	while ((frontPos < rearPos) && (frontPos != rearPos))
	{
		temp = front[frontPos];
		front[frontPos] = rear[rearPos];
		rear[rearPos] = temp;
		frontPos++;
		rearPos--;
	}
}