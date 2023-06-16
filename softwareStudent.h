#pragma once
#ifndef _SOFTWARESTUDENT_H_
#define _SOFTWARESTUDENT_H_
#include "student.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class SoftwareStudent : public Student {
public:
	SoftwareStudent(string studentID, string studentFirstName, string studentLastName, string studentEmail,
		string studentAge, vector<string> studentDaysToComplete, string studentDegreeType);
	int GetDegreeProgram();
	void PrintStudentData();
private:
	int degreeDataMember;
};


#endif