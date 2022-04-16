#include "Professor.h"

Professor::Professor()
{
	firstName = "Void";
	LastName = "Void";
	employeeID = "00000";
}

Professor::Professor(string firstName_, string LastName_, unsigned short int employeeID_, vector<Course> qualifiedToTeachCourses_)
{
	firstName = firstName_;
	LastName = LastName_;
	employeeID = employeeID_;
	qualifiedToTeachCourses = qualifiedToTeachCourses_;
}
