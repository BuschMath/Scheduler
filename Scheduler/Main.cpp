#include <iostream>
#include <fstream>
#include "ClassMeeting.h"
#include "Classroom.h"
#include "Date.h"
#include "Professor.h"
#include "Manager.h"

using namespace std;

int main()
{
	bool exit = false;
	char input = '0';

	Manager manager;

	while (!exit)
	{
		cout << "Select what you would like to do: \n";
		cout << "Enter 0 to exit: \n";
		cout << "Enter 1 to add professor: \n";
		cout << "Enter 2 to add course: \n";
		cout << "Enter 9 to save: \n";

		cout << endl;

		cin >> input;

		switch (input)
		{
			case '0': exit = true;
				cout << "Exiting...";
				break;
				
			case '1': manager.AddProfessor();
				break;

			case '2': manager.AddCourse();
				break;

			case '9': manager.Save();
				break;

			default: cout << "Input error, try again.\n\n";
				break;
		}
	}

	return 0;
}

