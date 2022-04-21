#ifndef CLASSMEETING_H
#define CLASSMEETING_H

#include <string>
#include <vector>
#include "Classroom.h"
#include "Date.h"
#include "Professor.h"

using namespace std;

struct Course
{
	string courseName;
	string courseSubjectCode;
	string courseNumID;
	unsigned short int credits;
	RoomType classroomTypeReq;
};

class ClassMeeting
{
public:
	ClassMeeting();
	ClassMeeting(Course course_,
		string sectionID_,
		unsigned short int maxCourseSeats_,
		vector<DaysOfWeek> weekdayMeet_,
		Time startTime_,
		Time endTime_,
		Date startDate_,
		Date endDate_, 
		Professor instructor);

	Course course;
	string sectionID;
	unsigned short int maxCourseSeats;
	vector<DaysOfWeek> weekdayMeet;
	Time startTime;
	Time endTime;
	Date startDate;
	Date endDate;
	Professor assignedInstructor;
};

#endif // !COURSE_H

