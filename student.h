#pragma once
#ifndef _STUDENT_H_
#define _STUDENT_H_
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Student {
public:
	string GetStudentID();
	void SetStudentID(string studentID);
	string GetStudentFirstName();
	void SetStudentFirstName(string studentFirstName);
	string GetStudentLastName();
	void SetStudentLastName(string studentLastName);
	string GetStudentEmail();
	void SetStudentEmail(string studentEmail);
	string GetStudentAge();
	void SetStudentAge(string studentAge);
	vector<string> GetStudentDaysToComplete();
	void SetStudentDaysToComplete(string studentDaysToComplete1, string studentDaysToComplete2, string studentDaysToComplete3);
	void SetDegreeProgram(string studentDegreeType);
	virtual void PrintStudentData();
	virtual int GetDegreeProgram();
	~Student();
	Student();
	Student(string studentID, string studentFirstName, string studentLastName, string studentEmail,
		string studentAge, vector<string> studentDaysToComplete, string studentDegreeType);

	string studentID = "";
	string studentLastName = "";
	string studentFirstName = "";
	string studentEmail = "";
	string studentAge = "";
	string studentDaysToComplete1;
	string studentDaysToComplete2;
	string studentDaysToComplete3;
	string studentDegreeType = "";
	vector<string> studentDaysToComplete;
private:
};
#endif