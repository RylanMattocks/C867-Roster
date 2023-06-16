
#include <iostream>
#include <vector>
#include <string>
#include "student.h"
#include "networkStudent.h"
#include "degree.h"
using namespace std;

NetworkStudent::NetworkStudent(string studentID, string studentFirstName, string studentLastName, string studentEmail,
	string studentAge, vector<string> studentDaysToComplete, string studentDegreeType) {
	this->studentID = studentID;
	this->studentFirstName = studentFirstName;
	this->studentLastName = studentLastName;
	this->studentEmail = studentEmail;
	this->studentAge = studentAge;
	this->studentDaysToComplete = studentDaysToComplete;
	this->studentDegreeType = studentDegreeType;
	return;
}

void NetworkStudent::PrintStudentData() {
	cout << "StudentID is: " << studentID << endl;
	cout << "Student First Name is: " << studentFirstName << endl;
	cout << "Student Last Name is : " << studentLastName << endl;
	cout << "Student Email is: " << studentEmail << endl;
	cout << "Student Age is: " << studentAge << endl;
	cout << "Student Days To Complete: " << studentDaysToComplete.at(0) << ", " <<
		studentDaysToComplete.at(1) << ", " << studentDaysToComplete.at(2) << endl;
	cout << "Student Degree Type: " << studentDegreeType << endl;
	return;
}

int NetworkStudent::GetDegreeProgram() {
	degreeDataMember = NETWORK;
	return(degreeDataMember);
}