#include "Manager.h"
#include <fstream>

using namespace std;

Manager::Manager()
{
}

Manager::~Manager()
{
}

void Manager::AddProfessor()
{
	Professor temp;
	char input = '0';
	bool exit = false;

	cout << "What is the professor's first name: ";
	cin >> temp.firstName;
	
	cout << "What is the professor's last name: ";
	cin >> temp.LastName;

	cout << "What is the professor's ID number: ";
	cin >> temp.employeeID;

	while (!exit)
	{
		cout << "Select how you would like to add qualifications: \n";
		cout << "To exit, choose 0: \n";
		cout << "Select by subject code, choose 1: \n";
		cin >> input;
		switch (input)
		{
			case '0': exit = true;
				break;
			case '1': QualBySubject(temp);
				break;
			default: cout << "Input error. Try again. \n";
				break;
		}
	}
	instructors.push_back(temp);
}

void Manager::AddCourse()
{
	Course temp;
	Classroom room;
	int input;

	cin.get();
	cout << "Enter course name: ";
	getline(cin, temp.courseName);

	cout << "Enter course subject code: ";
	cin >> temp.courseSubjectCode;

	cout << "Enter course number: ";
	cin >> temp.courseNumID;

	cout << "Enter number of credit hours: ";
	cin >> temp.credits;

	cout << "Select the type of classroom required: \n";
	for (int i = 0; i < room.roomTypeList.size(); i++)
	{
		cout << "Choose " << i << " for " << room.RoomTypeToString(room.roomTypeList[i]) << endl;
	}
	cin >> input; 
	
	temp.classroomTypeReq = room.roomTypeList[input];
	courses.push_back(temp);
}

void Manager::DisplayCourses()
{
	Classroom room;
	for (int i = 0; i < courses.size(); i++)
	{
		cout << courses[i].courseName << " ";
		cout << courses[i].courseSubjectCode << "-";
		cout << courses[i].courseNumID << " ";
		cout << courses[i].credits << " ";
		cout << room.RoomTypeToString(courses[i].classroomTypeReq) << endl;
	}
}

void Manager::Save()
{
	ofstream outfile;
	outfile.open("instructors.dat");

	for (int i = 0; i < instructors.size(); i++)
	{
		outfile << instructors[i].firstName << ",";
		outfile << instructors[i].LastName << ",";
		outfile << instructors[i].employeeID << ",";

		for (int j = 0; j < instructors[i].qualifiedToTeachCourses.size(); j++)
		{
			outfile << instructors[i].qualifiedToTeachCourses[j].courseSubjectCode << ",";
			outfile << instructors[i].qualifiedToTeachCourses[j].courseNumID << ",";
		}
		outfile << "\b\n";
	}

	outfile.close();

	Classroom room;
	outfile.open("courses.dat");
	for (int i = 0; i < courses.size(); i++)
	{
		outfile << courses[i].courseName << ",";
		outfile << courses[i].courseSubjectCode << ",";
		outfile << courses[i].courseNumID << ",";
		outfile << courses[i].credits << ",";
		outfile << room.RoomTypeToString(courses[i].classroomTypeReq) << "\n";
	}

	outfile.close();
}

void Manager::Load()
{
	ifstream infile;

	infile.open("instructors.dat");

/*	while (int i = 0; i < instructors.size(); i++)
	{
		outfile << instructors[i].firstName << ",";
		outfile << instructors[i].LastName << ",";
		outfile << instructors[i].employeeID << ",";

		for (int j = 0; j < instructors[i].qualifiedToTeachCourses.size(); j++)
		{
			outfile << instructors[i].qualifiedToTeachCourses[j].courseSubjectCode << ",";
			outfile << instructors[i].qualifiedToTeachCourses[j].courseNumID << ",";
		}
		outfile << "\b\n";
	}*/

	infile.close();

	infile.open("courses.dat");
	string input;
	Classroom room;
	Course temp;

	getline(infile, temp.courseName, ',');
	while (infile)
	{
		getline(infile, temp.courseSubjectCode, ',');

		getline(infile, temp.courseNumID, ',');

		getline(infile, input, ',');
		temp.credits = stoi(input);

		getline(infile, input, '\n');
		temp.classroomTypeReq = room.StringToRoomType(input);

		courses.push_back(temp);
		temp = *new Course;

		getline(infile, temp.courseName, ',');
	}
}

void Manager::QualBySubject(Professor& temp)
{
	string input;
	bool found = false;

	cout << "Enter course subject code: ";
	cin >> input;

	for (int i = 0; i < courses.size(); i++)
	{
		if (courses[i].courseSubjectCode == input)
		{
			cout << "Found qualified courses. Qualification added.\n";
			temp.qualifiedToTeachCourses.push_back(courses[i]);
			found = true;
		}
	}

	if(!found)
		cout << "No qualified courses found. Qualification not added.\n";
}
