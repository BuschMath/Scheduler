#include <iostream>
#include <fstream>
#include "ClassMeeting.h"
#include "Classroom.h"
#include "Date.h"
#include "Professor.h"

using namespace std;

int main()
{
	bool exit = false;
	char input = '0';

	while (!exit)
	{
		cout << "Select what you would like to do: \n";
		cout << "Enter 0 to exit: \n";
		cout << "Enter 1 to add professor: \n";

		cout << endl;

		cin >> input;

		switch (input)
		{
			case '0': exit = true;
				cout << "Exiting...";
				break;

			case '1': AddProfessor();

			default: cout << "Input error, try again.\n\n";
				break;
		}
	}

	return 0;
}