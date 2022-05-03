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

void Manager::AddClassroom()
{
	Classroom temp;

	temp.buildingName = SelectBuilding(temp);

	CollectRoomProperties(temp);

	classrooms.push_back(temp);
}

void Manager::AddClassMeeting()
{
	ClassMeeting temp;

	temp.course = FindCourseBySubjectCodeNumber();

	CollectClassMeetingSectionIDMaxSeats(temp);

	CollectClassMeetingStartingEndingInfo(temp);

	AssignClassroom(temp);

	AssignInstructor(temp);

	classMeetings.push_back(temp);
}

void Manager::DisplayClassrooms()
{
	OutputClassrooms(cout, " ");
}

void Manager::DisplayClassMeetings()
{
	OutputClassMeeting(cout, " ");
}

void Manager::OutputClassrooms(ostream& oStream, string dlimit)
{
	for (int i = 0; i < classrooms.size(); i++)
	{
		oStream << classrooms[i].BuildingNameToString(classrooms[i].buildingName) << dlimit;
		oStream << classrooms[i].roomNumber << dlimit;
		oStream << classrooms[i].RoomTypeToString(classrooms[i].roomType) << dlimit;
		oStream << classrooms[i].maxRoomCapacity << "\n";
	}
}

void Manager::OutputClassMeeting(ostream& oStream, string dlimit)
{
	for (int i = 0; i < classMeetings.size(); i++)
	{
		oStream << classMeetings[i].course.courseSubjectCode << dlimit;
		oStream << classMeetings[i].course.courseNumID << dlimit;
		oStream << classMeetings[i].sectionID << dlimit;
		oStream << classMeetings[i].maxCourseSeats << dlimit;
		
		for (int j = 0; j < classMeetings[i].weekdayMeet.size(); j++)
		{
			oStream << classMeetings[i].startDate.DayToString(classMeetings[i].weekdayMeet[j]).substr(0,2) << "-";
		}
		oStream << dlimit;

		oStream << classMeetings[i].startTime.hour << dlimit;
		oStream << classMeetings[i].startTime.min << dlimit;
		oStream << classMeetings[i].endTime.hour << dlimit;
		oStream << classMeetings[i].endTime.min << dlimit;
		oStream << classMeetings[i].startDate.day << dlimit;
		oStream << classMeetings[i].startDate.MonthToString(classMeetings[i].startDate.month) << dlimit;
		oStream << classMeetings[i].startDate.year << dlimit;
		oStream << classMeetings[i].endDate.day << dlimit;
		oStream << classMeetings[i].endDate.MonthToString(classMeetings[i].endDate.month) << dlimit;
		oStream << classMeetings[i].endDate.year << dlimit;
		oStream << classMeetings[i].assignedRoom.BuildingNameToString(classMeetings[i].assignedRoom.buildingName) << dlimit;
		oStream << classMeetings[i].assignedRoom.roomNumber << dlimit;
		oStream << classMeetings[i].assignedInstructor.firstName << dlimit;
		oStream << classMeetings[i].assignedInstructor.LastName << endl;
	}
}

void Manager::Save()
{
	ofstream outfile;
	string dlimit = ",";
	string ending = "end\n";
	outfile.open(ProfessorSaveFileName);
	for (int i = 0; i < departments.size(); i++)
		departments[i].OutputProfessors(outfile, dlimit, ending);
	outfile.close();

	outfile.open(CoursesSaveFileName);
	for (int i = 0; i < departments.size(); i++)
		departments[i].OutputCourses(outfile, dlimit);
	outfile.close();

	outfile.open(ClassroomSaveFileName);
	OutputClassrooms(outfile, dlimit);
	outfile.close();

	outfile.open(ClassMeetingSaveFileName);
	OutputClassMeeting(outfile, dlimit);
	outfile.close();
}

void Manager::Load()
{
	ifstream infile;

	infile.open(CoursesSaveFileName);
	LoadCourses(infile);
	infile.close();

	infile.open(ProfessorSaveFileName);
	LoadProfessors(infile);
	infile.close();

	infile.open(ClassroomSaveFileName);
	LoadClassrooms(infile);
	infile.close();

	infile.open(ClassMeetingSaveFileName);
	LoadClassMeetings(infile);
	infile.close();
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
	string deptName;

	cout << "What is the subject code of the course?: ";
	cin >> subjectCode;

	cout << "\nWhat is the course number ID?: ";
	cin >> courseNumID;

	cout << "\nWhat deptartment?: ";
	cin >> deptName;

	return FindDepartment(deptName).FindCourseBySubjectCodeNumber(subjectCode, courseNumID);
}

Classroom Manager::FindClassroom(BuildingName bName, string roomNumber)
{
	for (int i = 0; i < classrooms.size(); i++)
	{
		if (classrooms[i].buildingName == bName && classrooms[i].roomNumber == roomNumber)
			return classrooms[i];
	}

	return Classroom();
}

Professor Manager::FindProfessor()
{
	string lName;
	string fName;
	string deptName;

	cout << "\nWhat is the first name?: ";
	cin >> fName;

	cout << "\nWhat is the last name?: ";
	cin >> lName;

	cout << "\nWhat is the department name?: ";
	cin >> deptName;

	return FindDepartment(deptName).FindProfessor(fName, lName);
}

Department Manager::FindDepartment(string deptName)
{
	for (int i = 0; i < departments.size(); i++)
	{
		if (departments[i].deptName == deptName)
			return departments[i];
	}

	return Department();
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

	cout << "\nWhat is the ending month of the course?: \n";
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

		cin >> input;

		if (stoi(input) != dayTemp.ListOfDays.size())
			temp.weekdayMeet.push_back(dayTemp.ListOfDays[stoi(input)]);
	}
}

void Manager::AssignInstructor(ClassMeeting& temp)
{
	Professor tempProf = FindProfessor();

	for (int j = 0; j < tempProf.qualifiedToTeachCourses.size(); j++)
	{
		if (tempProf.qualifiedToTeachCourses[j].courseName == temp.course.courseName)
		{
			cout << "\nQualification found, adding instructor.";

			temp.assignedInstructor = tempProf;
			return;
		}
	}
	cout << "\nQualification not found, assign instructor failed.";
}

void Manager::AssignClassroom(ClassMeeting& temp)
{
	Classroom room;
	SelectBuilding(room);

	cout << "\nWhat is the room number?: ";
	cin >> room.roomNumber;

	cout << "\nSearching for room...";
	temp.assignedRoom = FindClassroom(room.buildingName, room.roomNumber);

	if (room.maxRoomCapacity != 0)
		cout << "\nRoom found. Adding room.";
	else
		cout << "\nRoom not found, failed to add classroom.";
}

void Manager::LoadCourses(istream& iStream)
{
	Course temp;
	string input;
	Classroom room;

	getline(iStream, temp.courseName, ',');
	while (iStream)
	{
		getline(iStream, temp.courseSubjectCode, ',');

		getline(iStream, temp.courseNumID, ',');

		getline(iStream, input, ',');
		temp.credits = stoi(input);

		getline(iStream, input, '\n');
		temp.classroomTypeReq = room.StringToRoomType(input);

		courses.push_back(temp);
		temp = *new Course;

		getline(iStream, temp.courseName, ',');
	}
}

void Manager::LoadProfessors(istream& iStream)
{
	Professor pTemp;
	Course cTemp;
	bool found = false;
	string input;

	getline(iStream, pTemp.firstName, ',');

	while (iStream)
	{
		getline(iStream, pTemp.LastName, ',');
		getline(iStream, pTemp.employeeID, ',');

		getline(iStream, input, ',');
		while (input.substr(0, 4) != "end\n")
		{
			cTemp.courseSubjectCode = input;
			getline(iStream, cTemp.courseNumID, ',');

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
			getline(iStream, input, ',');
		}

		instructors.push_back(pTemp);

		pTemp = *new Professor;

		if (input.substr(4, input.size() - 4) == "")
			break;

		pTemp.firstName = input.substr(4, input.size() - 4);
	}
}

void Manager::LoadClassrooms(istream& iStream)
{
	Classroom rTemp;
	string input;

	getline(iStream, input, ',');
	rTemp.buildingName = rTemp.StringToBuildingName(input);

	while (iStream)
	{
		getline(iStream, rTemp.roomNumber, ',');

		getline(iStream, input, ',');
		rTemp.StringToRoomType(input);

		getline(iStream, input, '\n');
		rTemp.maxRoomCapacity = stoi(input);

		classrooms.push_back(rTemp);

		getline(iStream, input, ',');
		rTemp.buildingName = rTemp.StringToBuildingName(input);
	}
}

void Manager::LoadClassMeetings(istream& iStream)
{
	ClassMeeting temp;
	string subjectCode;
	string courseIDNum;
	string input;

	getline(iStream, subjectCode, ',');

	while (iStream)
	{	
		getline(iStream, courseIDNum, ',');
		temp.course = FindCourseBySubjectCodeNumber(subjectCode, courseIDNum);

		getline(iStream, temp.sectionID, ',');

		getline(iStream, input, ',');
		temp.maxCourseSeats = stoi(input);

		getline(iStream, input, '-');
		while (iStream.peek() != ',')
		{
			temp.weekdayMeet.push_back(temp.startDate.StringSubToDay(input));
			getline(iStream, input, '-');
		}
		temp.weekdayMeet.push_back(temp.startDate.StringSubToDay(input));

		iStream.ignore(1);
		getline(iStream, input, ',');
		temp.startTime.hour = stoi(input);
		getline(iStream, input, ',');
		temp.startTime.min = stoi(input);

		getline(iStream, input, ',');
		temp.endTime.hour = stoi(input);
		getline(iStream, input, ',');
		temp.endTime.min = stoi(input);

		getline(iStream, input, ',');
		temp.startDate.day = stoi(input);
		getline(iStream, input, ',');
		temp.startDate.month = temp.startDate.StringToMonth(input);
		getline(iStream, input, ',');
		temp.startDate.year = stoi(input);

		getline(iStream, input, ',');
		temp.endDate.day = stoi(input);
		getline(iStream, input, ',');
		temp.endDate.month = temp.startDate.StringToMonth(input);
		getline(iStream, input, ',');
		temp.endDate.year = stoi(input);

		string roomNumber;
		getline(iStream, input, ',');
		getline(iStream, roomNumber, ',');
		temp.assignedRoom = FindClassroom(temp.assignedRoom.StringToBuildingName(input), roomNumber);

		string fName;
		string lName;
		getline(iStream, fName, ',');
		getline(iStream, lName);
		temp.assignedInstructor = FindProfessor(fName, lName);
		
		classMeetings.push_back(temp);
		getline(iStream, subjectCode, ',');
	}
}
