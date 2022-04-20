#include "Manager.h"
#include "Date.h"
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
	bool exit = false;

	CollectProfessorID(temp);

	while (!CollectProfessorQual(temp))

	instructors.push_back(temp);
}

void Manager::AddCourse()
{
	Course temp;
	
	CollectCourseID(temp);

	temp.classroomTypeReq = CollectReqClassroomType();
	courses.push_back(temp);
}

void Manager::AddClassroom()
{
	Classroom temp;
	int input;

	temp.buildingName = SelectBuilding(temp);

	CollectRoomProperties(temp);

	classrooms.push_back(temp);
}

void Manager::AddClassMeeting()
{
	ClassMeeting temp;
	string input;

	temp.course = FindCourseBySubjectCodeNumber();

	CollectClassMeetingSectionIDMaxSeats(temp);

	CollectClassMeetingStartingEndingInfo(temp);
}

void Manager::DisplayProfessors()
{
	for (int i = 0; i < instructors.size(); i++)
	{
		OutputProfessors(cout, i, " ");

		cout << endl;
	}
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

void Manager::DisplayClassrooms()
{
	for (int i = 0; i < classrooms.size(); i++)
	{
		cout << classrooms[i].BuildingNameToString(classrooms[i].buildingName) << " ";
		cout << classrooms[i].roomNumber << " ";
		cout << classrooms[i].RoomTypeToString(classrooms[i].roomType) << " Cap: ";
		cout << classrooms[i].maxRoomCapacity << endl;
	}
}

void Manager::OutputProfessors(ostream& oStream, int ProfNum, string dlimit)
{
	oStream << instructors[ProfNum].firstName << dlimit;
	oStream << instructors[ProfNum].LastName << dlimit;
	oStream << instructors[ProfNum].employeeID << dlimit;

	for (int j = 0; j < instructors[ProfNum].qualifiedToTeachCourses.size(); j++)
	{
		oStream << instructors[ProfNum].qualifiedToTeachCourses[j].courseSubjectCode << dlimit;
		oStream << instructors[ProfNum].qualifiedToTeachCourses[j].courseNumID << dlimit;
	}
}

void Manager::Save()
{
	ofstream outfile;
	outfile.open(ProfessorSaveFileName);

	for (int i = 0; i < instructors.size(); i++)
	{
		OutputProfessors(outfile, i, ",");
		outfile << "end\n";
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

	outfile.open("classrooms.dat");

	for (int i = 0; i < classrooms.size(); i++)
	{
		outfile << classrooms[i].BuildingNameToString(classrooms[i].buildingName) << ",";
		outfile << classrooms[i].roomNumber << ",";
		outfile << classrooms[i].RoomTypeToString(classrooms[i].roomType) << ",";
		outfile << classrooms[i].maxRoomCapacity << "\n";
	}

	outfile.close();
}

void Manager::Load()
{
	ifstream infile;

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

	infile.close();

	Professor pTemp;
	Course cTemp;
	bool found = false;

	infile.open("instructors.dat");

	getline(infile, pTemp.firstName, ',');

	while (infile)
	{

		getline(infile, pTemp.LastName, ',');
		getline(infile, pTemp.employeeID, ',');

		getline(infile, input, ',');
		while (input.substr(0, 4) != "end\n")
		{
			cTemp.courseSubjectCode = input;
			getline(infile, cTemp.courseNumID, ',');

			for (int i = 0; i < courses.size(); i++)
			{
				if (courses[i].courseSubjectCode == cTemp.courseSubjectCode && courses[i].courseNumID == cTemp.courseNumID)
				{
					cTemp.classroomTypeReq = courses[i].classroomTypeReq;
					cTemp.courseName = courses[i].courseName;
					cTemp.credits = courses[i].credits;

					pTemp.qualifiedToTeachCourses.push_back(cTemp);
					found = true;
					break;
				}
			}

			if (!found)
				cout << "Course: " << cTemp.courseSubjectCode << "-" << cTemp.courseNumID << " Not found!\n";
			else
				found = false;
			getline(infile, input, ',');
		}
		
		instructors.push_back(pTemp);

		pTemp = *new Professor;

		if (input.substr(4, input.size() - 4) == "")
			break;

		pTemp.firstName = input.substr(4, input.size()-4);
	}

	infile.close();

	infile.open("classrooms.dat");

	Classroom rTemp;

	getline(infile, input, ',');
	rTemp.buildingName = rTemp.StringToBuildingName(input);

	while (infile)
	{
		getline(infile, rTemp.roomNumber, ',');

		getline(infile, input, ',');
		rTemp.StringToRoomType(input);
		
		getline(infile, input, '\n');
		rTemp.maxRoomCapacity = stoi(input);

		classrooms.push_back(rTemp);

		getline(infile, input, ',');
		rTemp.buildingName = rTemp.StringToBuildingName(input);
	}

	infile.close();
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

void Manager::QualByCourse(Professor& temp)
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

void Manager::CollectProfessorID(Professor& temp)
{
	cout << "What is the professor's first name: ";
	cin >> temp.firstName;

	cout << "What is the professor's last name: ";
	cin >> temp.LastName;

	cout << "What is the professor's ID number: ";
	cin >> temp.employeeID;
}

bool Manager::CollectProfessorQual(Professor& temp)
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

void Manager::CollectCourseID(Course& temp)
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

RoomType Manager::CollectReqClassroomType()
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

BuildingName Manager::SelectBuilding(Classroom temp)
{
	int input;

	cout << "Which building is the classroom in: \n";
	for (int i = 0; i < temp.buildingNameList.size(); i++)
	{
		cout << "Choose " << i << " for " << temp.BuildingNameToString(temp.buildingNameList[i]) << endl;
	}
	cin >> input;

	return temp.buildingNameList[input];
}

void Manager::CollectRoomProperties(Classroom& temp)
{
	int input;

	cout << "What is the room number: ";
	cin >> temp.roomNumber;

	cout << "\nSelect the type of classroom: \n";
	for (int i = 0; i < temp.roomTypeList.size(); i++)
	{
		cout << "Choose " << i << " for " << temp.RoomTypeToString(temp.roomTypeList[i]) << endl;
	}
	cin >> input;

	temp.roomType = temp.roomTypeList[input];

	cout << "\nEnter the maximum room capacity: ";
	cin >> temp.maxRoomCapacity;
}

Course Manager::FindCourseBySubjectCodeNumber()
{
	string subjectCode;
	string courseNumID;

	cout << "What is the subject code of the course?: ";
	cin >> subjectCode;

	cout << "\nWhat is the course number ID?: ";
	cin >> courseNumID;

	for (int i = 0; i < courses.size(); i++)
	{
		if (courses[i].courseSubjectCode == subjectCode && courses[i].courseNumID == courseNumID)
		{
			cout << "\nCourse found and added.\n";
			return courses[i];
		}
	}

	cout << "\nCourse not found.";

	return Course();
}

void Manager::CollectClassMeetingSectionIDMaxSeats(ClassMeeting& temp)
{
	string input;

	cout << "\nWhat is the section ID?: ";
	cin >> temp.sectionID;

	cout << "\nWhat is the maximum number of seats for the class meeting?: ";
	cin >> input;
	temp.maxCourseSeats = stoi(input);
}

void Manager::CollectClassMeetingStartingEndingInfo(ClassMeeting& temp)
{
	temp.startDate = CollectClassMeetingStartDayMonthYear();

	temp.endDate = CollectClassMeetingEndDayMonthYear();

	CollectClassMeetingStartEndTime(temp);

	SelectClassMeetingDaysOfWeek(temp);
}

Date Manager::CollectClassMeetingStartDayMonthYear()
{
	Date dayTemp;
	string input;

	cout << "\nWhat is the starting month of the course?: ";
	for (int i = 0; i < dayTemp.ListOfMonths.size(); i++)
	{
		cout << "Choose " << i << " for " << dayTemp.MonthToString(dayTemp.ListOfMonths[i]) << endl;
	}
	cin >> input;

	dayTemp.month = dayTemp.ListOfMonths[stoi(input)];

	cout << "\nInput the starting day as an integer.: ";
	cin >> dayTemp.day;

	cout << "\nWhat is the starting year?: ";
	cin >> dayTemp.year;
	return dayTemp;
}

Date Manager::CollectClassMeetingEndDayMonthYear()
{
	Date dayTemp;
	string input;

	cout << "\nWhat is the ending month of the course?: ";
	for (int i = 0; i < dayTemp.ListOfMonths.size(); i++)
	{
		cout << "Choose " << i << " for " << dayTemp.MonthToString(dayTemp.ListOfMonths[i]) << endl;
	}
	cin >> input;

	dayTemp.month = dayTemp.ListOfMonths[stoi(input)];

	cout << "\nInput the ending day as an integer.: ";
	cin >> dayTemp.day;

	cout << "\nWhat is the ending year?: ";
	cin >> dayTemp.year;
	return dayTemp;
}

void Manager::CollectClassMeetingStartEndTime(ClassMeeting& temp)
{
	cout << "\nWhat is the starting hour?: ";
	cin >> temp.startTime.hour;
	cout << "\nWhat is the starting minute?: ";
	cin >> temp.startTime.min;

	cout << "\nWhat is the ending hour?: ";
	cin >> temp.endTime.hour;
	cout << "\nWhat is the ending minute?: ";
	cin >> temp.endTime.min;
}

void Manager::SelectClassMeetingDaysOfWeek(ClassMeeting& temp)
{
	Date dayTemp;
	string input = "-1";
	while (stoi(input) != dayTemp.ListOfDays.size())
	{
		cout << "\nSelect the days of the week the course should meet.: ";
		for (int i = 0; i < dayTemp.ListOfDays.size(); i++)
		{
			cout << "\nChoose " << i << " for " << dayTemp.DayToString(dayTemp.ListOfDays[i]);
		}
		cout << "\nChoose " << dayTemp.ListOfDays.size() << " to exit day choice menu.: ";

		if (stoi(input) != dayTemp.ListOfDays.size())
			temp.weekdayMeet.push_back(dayTemp.ListOfDays[stoi(input)]);
	}
}
