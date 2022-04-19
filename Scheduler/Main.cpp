#include <iostream>
#include <fstream>
#include "ClassMeeting.h"
#include "Classroom.h"
#include "Date.h"
#include "Professor.h"
#include "Manager.h"

using namespace std;

void OutputMenuOptions();
bool InputMenuChoice();

int main()
{
	bool exit = false;

	Manager manager;

	while (!exit)
	{
		OutputMenuOptions();

		exit = InputMenuChoice();
	}

	return 0;
}

void OutputMenuOptions()
{
	cout << "\nSelect what you would like to do: \n";
	cout << "Enter 0 to exit: \n";
	cout << "Enter 1 to add professor: \n";
	cout << "Enter 2 to display professors: \n";
	cout << "Enter 3 to add course: \n";
	cout << "Enter 4 to display courses: \n";
	cout << "Enter 5 to add classroom: \n";
	cout << "Enter 6 to display classrooms: \n";
	cout << "Enter 7 to add class meeting: \n";
	cout << "Enter s to save: \n";
	cout << "Enter l to load: \n";

	cout << endl;
}

bool InputMenuChoice()
{
	char input = '0';
	cin >> input;

	switch (input)
	{
	case '0': cout << "Exiting...";
		return true;
		break;
	case '1': manager.AddProfessor();
		break;
	case '2': manager.DisplayProfessors();
		break;
	case '3': manager.AddCourse();
		break;
	case '4': manager.DisplayCourses();
		break;
	case '5': manager.AddClassroom();
		break;
	case '6': manager.DisplayClassrooms();
		break;
	case '7': manager.AddClassMeeting();
		break;
	case 's': manager.Save();
		break;
	case 'l': manager.Load();
		break;
	default: cout << "Input error, try again.\n\n";
		break;
	}

	return false;
}