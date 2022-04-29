#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <iostream>
#include <fstream>
#include "Professor.h"

using namespace std;

class Department
{
public:
	void AddProfessor();
	void AddCourse();
	void DisplayProfessors();
	void DisplayCourses();

private:
	void OutputProfessors(ostream& oStream, string dlimit, string ending);
	void OutputCourses(ostream& oStream, string dlimit);
	void CollectProfessorID(Professor& temp);
	bool CollectProfessorQual(Professor& temp);
	void CollectCourseID(Course& temp);
	RoomType CollectReqClassroomType();
	void QualBySubject(Professor& temp);
	void QualByCourse(Professor& temp);

	vector<Professor> instructors;
	vector<Course> courses;
};

#endif // !DEPARTMENT_H
