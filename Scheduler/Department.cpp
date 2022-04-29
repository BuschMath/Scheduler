#include "Department.h"

void Department::AddProfessor()
{
	Professor temp;

	CollectProfessorID(temp);

	while (!CollectProfessorQual(temp))

	instructors.push_back(temp);
}

void Department::AddCourse()
{
	Course temp;
	
	CollectCourseID(temp);

	temp.classroomTypeReq = CollectReqClassroomType();
	courses.push_back(temp);
}

void Department::DisplayProfessors()
{
	OutputProfessors(cout, " ", "\n");
}

void Department::DisplayCourses()
{
	OutputCourses(cout, " ");
}

void Department::OutputProfessors(ostream& oStream, string dlimit, string ending)
{
	for (int i = 0; i < instructors.size(); i++)
	{
		oStream << instructors[i].firstName << dlimit;
		oStream << instructors[i].LastName << dlimit;
		oStream << instructors[i].employeeID << dlimit;

		for (int j = 0; j < instructors[i].qualifiedToTeachCourses.size(); j++)
		{
			oStream << instructors[i].qualifiedToTeachCourses[j].courseSubjectCode << dlimit;
			oStream << instructors[i].qualifiedToTeachCourses[j].courseNumID << dlimit;
		}
		oStream << ending;
	}
}

void Department::OutputCourses(ostream& oStream, string dlimit)
{
	Classroom room;
	for (int i = 0; i < courses.size(); i++)
	{
		oStream << courses[i].courseName << dlimit;
		oStream << courses[i].courseSubjectCode << dlimit;
		oStream << courses[i].courseNumID << dlimit;
		oStream << courses[i].credits << dlimit;
		oStream << room.RoomTypeToString(courses[i].classroomTypeReq) << "\n";
	}
}

void Department::CollectProfessorID(Professor& temp)
{
	cout << "What is the professor's first name: ";
	cin >> temp.firstName;

	cout << "What is the professor's last name: ";
	cin >> temp.LastName;

	cout << "What is the professor's ID number: ";
	cin >> temp.employeeID;
}

bool Department::CollectProfessorQual(Professor& temp)
{
	char input = '0';
	cout << "Select how you would like to add qualifications: \n";
	cout << "To exit, choose 0: \n";
	cout << "Select by subject code, choose 1: \n";
	cout << "Select by course, choose 2: \n";
	cin >> input;
	switch (input)
	{
	case '0': return true;
		break;
	case '1': QualBySubject(temp);
		break;
	case '2': QualByCourse(temp);
		break;
	default: cout << "Input error. Try again. \n";
		break;
	}

	return false;
}

void Department::CollectCourseID(Course& temp)
{
	cin.get();
	cout << "Enter course name: ";
	getline(cin, temp.courseName);

	cout << "Enter course subject code: ";
	cin >> temp.courseSubjectCode;

	cout << "Enter course number: ";
	cin >> temp.courseNumID;

	cout << "Enter number of credit hours: ";
	cin >> temp.credits;
}

RoomType Department::CollectReqClassroomType()
{
	Classroom room;
	int input;

	cout << "Select the type of classroom required: \n";
	for (int i = 0; i < room.roomTypeList.size(); i++)
	{
		cout << "Choose " << i << " for " << room.RoomTypeToString(room.roomTypeList[i]) << endl;
	}
	cin >> input;

	return room.roomTypeList[input];
}

void Department::QualBySubject(Professor& temp)
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

	if (!found)
		cout << "No qualified courses found. Qualification not added.\n";
}

void Department::QualByCourse(Professor& temp)
{
	string subject;
	string courseNo;
	bool found = false;

	cout << "Enter course subject code: ";
	cin >> subject;

	cout << "\nEnter course number: ";
	cin >> courseNo;

	for (int i = 0; i < courses.size(); i++)
	{
		if (courses[i].courseSubjectCode == subject && courses[i].courseNumID == courseNo)
		{
			cout << "Found qualified courses. Qualification added.\n";
			temp.qualifiedToTeachCourses.push_back(courses[i]);
			found = true;
			break;
		}
	}

	if (!found)
		cout << "No qualified courses found. Qualification not added.\n";
}
