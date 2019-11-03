#pragma once
#include <string>

using namespace std;

class InvalidInput
{
private:
	string message;
public:
	InvalidInput()
	{
		message = "Invalid input.";
	}

	InvalidInput(string msg)
	{
		message = msg;
	}

	string what()
	{
		return message;
	}
};