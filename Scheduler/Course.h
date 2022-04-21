#ifndef COURSE_H
#define COURSE_H

#include <string>
#include "Classroom.h"

using namespace std;

class Course
{
public:
	Course();

	string courseName;
	string courseSubjectCode;
	string courseNumID;
	unsigned short int credits;
	RoomType classroomTypeReq;
};

#endif // !COURSE_H
