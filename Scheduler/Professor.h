#ifndef PROFESSOR_H
#define PROFESSOR_H

#include <string>
#include <vector>
#include "Course.h"

using namespace std;

class Professor
{
public:
	Professor();
	Professor(string firstName_, string LastName_, unsigned short int employeeID_,
		vector<Course> qualifiedToTeachCourses_);

	string firstName;
	string LastName;
	string employeeID;
	vector<Course> qualifiedToTeachCourses;
};

#endif // !PROFESSOR_H



