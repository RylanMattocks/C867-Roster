#pragma once
#ifndef _SECURITYSTUDENT_H_
#define _SECURITYSTUDENT_H_
#include "student.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class SecurityStudent : public Student{
public:
	SecurityStudent(string studentID, string studentFirstName, string studentLastName, string studentEmail,
		string studentAge, vector<string> studentDaysToComplete, string studentDegreeType);
	int GetDegreeProgram();
	void PrintStudentData();
private:
	int degreeDataMember;
};


#endif