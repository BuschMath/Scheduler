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
	void Save();

private:
	void QualBySubject(Professor& temp);

	vector<Professor> instructors;
	vector<Course> courses;

};

#endif // !MANAGER_H
