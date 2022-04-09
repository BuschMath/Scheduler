#include "Manager.h"

Manager::Manager()
{
}

Manager::~Manager()
{
}

void Manager::AddProfessor()
{
	Professor temp;
	string input;
	bool exit = false;

	cout << "What is the professor's first name: ";
	cin >> temp.firstName;
	
	cout << "\nWhat is the professor's last name: ";
	cin >> temp.LastName;

	cout << "\nWhat is the professor's ID number: ";
	cin >> temp.employeeID;

	while (!exit)
	{
		// qualification coding here
	}
}

void Manager::AddCourse()
{
	Course temp;

	cout << "Enter course name: ";
	cin << temp.courseName;

	cout << "\nEnter course subject code: ";
	cin << temp.courseSubjectCode;

	cout << "\nEnter course number: ";
	cin << temp.courseNumID;

	cout << "\nEnter number of credit hours: ";
	cin << temp.credits;

	cout << "\nSelect the type of classroom required: "
	cin << temp.classroomTypeReq;
}