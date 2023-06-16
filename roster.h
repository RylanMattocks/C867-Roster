#pragma once
#ifndef _ROSTER_H_
#define _ROSTER_H_
#include <vector>
#include <string>
using namespace std;
class Roster{
public:
	Roster();
	void Add(string studentID, string firstName, string lastName, string emailAddress,
		string age, string daysInCourse1, string daysInCourse2, string daysInCourse3, string degreeProgram);
	void Remove(string studentID);
	void PrintAll();
	void PrintAverageDaysInCourse(string studentID);
	void PrintInvalidEmails();
	void PrintByDegreeProgram(int degreeProgram);
	~Roster();
private:
	string studentID = "";
	string firstName = "";
	string lastName = "";
	string emailAddress = "";
	string age = "";
	string daysInCourse1 = "";
	string daysInCourse2 = "";
	string daysInCourse3 = "";
	string degreeProgram = "";
	vector<string> daysInCourse;
	vector<string*> classRosterArray;
	string* myPointer = nullptr;
};
#endif