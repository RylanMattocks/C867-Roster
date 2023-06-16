#pragma once
#ifndef _NETWORKSTUDENT_H_
#define _NETWORKSTUDENT_H_
#include "student.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class NetworkStudent : public Student{
public:
	NetworkStudent(string studentID, string studentFirstName, string studentLastName, string studentEmail,
		string studentAge, vector<string> studentDaysToComplete, string studentDegreeType);
	int GetDegreeProgram();
	void PrintStudentData();
private:
	int degreeDataMember;
};


#endif