#ifndef MANAGER_H
#define MANAGER_H

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "Department.h"
#include "ClassMeeting.h"

const string ProfessorSaveFileName = "instructors.dat";
const string CoursesSaveFileName = "courses.dat";
const string ClassroomSaveFileName = "classrooms.dat";
const string ClassMeetingSaveFileName = "classmeeting.dat";

using namespace std;

class Manager
{
public:
	Manager();
	~Manager();

	void AddClassroom();
	void AddClassMeeting();
	
	void DisplayClassrooms();
	void DisplayClassMeetings();
	
	void Save();
	void Load();

private:
	BuildingName SelectBuilding(Classroom temp);
	void CollectRoomProperties(Classroom& temp);
	Course FindCourseBySubjectCodeNumber();
	Classroom FindClassroom(BuildingName bName, string roomNumber);
	Professor FindProfessor();
	Department FindDepartment(string deptName);
	void CollectClassMeetingSectionIDMaxSeats(ClassMeeting& temp);
	void CollectClassMeetingStartingEndingInfo(ClassMeeting& temp);
	Date CollectClassMeetingStartDayMonthYear();
	Date CollectClassMeetingEndDayMonthYear();
	void CollectClassMeetingStartEndTime(ClassMeeting& temp);
	void SelectClassMeetingDaysOfWeek(ClassMeeting& temp);
	void AssignInstructor(ClassMeeting& temp);
	void AssignClassroom(ClassMeeting& temp);
	void LoadCourses(istream& iStream);
	void LoadProfessors(istream& iStream);
	void LoadClassrooms(istream& iStream);
	void LoadClassMeetings(istream& iStream);

	void OutputClassrooms(ostream& oStream, string dlimit);
	void OutputClassMeeting(ostream& oStream, string dlimit);

	vector<Classroom> classrooms;
	vector<ClassMeeting> classMeetings;
	vector<Department> departments;
};

#endif // !MANAGER_H
