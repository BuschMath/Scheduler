#ifndef MANAGER_H
#define MANAGER_H

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "Professor.h"
#include "ClassMeeting.h"

using namespace std;

class Manager
{
public:
	Manager();
	~Manager();

	void AddProfessor();
	void AddCourse();
	void AddClassroom();
	void DisplayProfessors();
	void DisplayCourses();
	void DisplayClassrooms();
	void Save();
	void Load();

private:
	void QualBySubject(Professor& temp);
	void QualByCourse(Professor& temp);

	vector<Professor> instructors;
	vector<Course> courses;
	vector<Classroom> classrooms;

};

#endif // !MANAGER_H
