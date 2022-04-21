#ifndef MANAGER_H
#define MANAGER_H

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "Professor.h"
#include "ClassMeeting.h"

const string ProfessorSaveFileName = "instructors.dat";
const string CoursesSaveFileName = "courses.dat";
const string ClassroomSaveFileName = "classrooms.dat";

using namespace std;

class Manager
{
public:
	Manager();
	~Manager();

	void AddProfessor();
	void AddCourse();
	void AddClassroom();
	void AddClassMeeting();
	
	void DisplayProfessors();
	void DisplayCourses();
	void DisplayClassrooms();
	
	void OutputProfessors(ostream& oStream, string dlimit, string ending);
	void OutputCourses(ostream& oStream, string dlimit);
	void OutputClassrooms(ostream& oStream, string dlimit);
	
	void Save();
	void Load();

private:
	void QualBySubject(Professor& temp);
	void QualByCourse(Professor& temp);
	void CollectProfessorID(Professor& temp);
	bool CollectProfessorQual(Professor& temp);
	void CollectCourseID(Course& temp);
	RoomType CollectReqClassroomType();
	BuildingName SelectBuilding(Classroom temp);
	void CollectRoomProperties(Classroom& temp);
	Course FindCourseBySubjectCodeNumber();
	void CollectClassMeetingSectionIDMaxSeats(ClassMeeting& temp);
	void CollectClassMeetingStartingEndingInfo(ClassMeeting& temp);
	Date CollectClassMeetingStartDayMonthYear();
	Date CollectClassMeetingEndDayMonthYear();
	void CollectClassMeetingStartEndTime(ClassMeeting& temp);
	void SelectClassMeetingDaysOfWeek(ClassMeeting& temp);
	void AssignInstructor(ClassMeeting& temp);
	void LoadCourses(istream& iStream);
	void LoadProfessors(istream& iStream);
	void LoadClassrooms(istream& iStream);

	vector<Professor> instructors;
	vector<Course> courses;
	vector<Classroom> classrooms;
	vector<ClassMeeting> classMeetings;
};

#endif // !MANAGER_H
