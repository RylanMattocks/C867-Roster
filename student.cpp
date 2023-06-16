
#include <iostream>
#include <vector>
#include <string>
#include "student.h"
#include "degree.h"
using namespace std;

Student::Student() {
	this->studentID = "";
	this->studentFirstName = "";
	this->studentLastName = "";
	this->studentEmail = "";
	this->studentAge = "";

	for (int i = 0; i < 3; i++) {
		this->studentDaysToComplete.push_back("");
	}
	return;
}

Student::Student(string studentID, string studentFirstName, string studentLastName, string studentEmail,
	string studentAge, vector<string> studentDaysToComplete, string studentDegreeType) {
	this->studentID = studentID;
	this->studentFirstName = studentFirstName;
	this->studentLastName = studentLastName;
	this->studentEmail = studentEmail;
	this->studentAge = studentAge;
	/*studentDaysToComplete.push_back(studentDaysToComplete1);
	studentDaysToComplete.push_back(studentDaysToComplete2);
	studentDaysToComplete.push_back(studentDaysToComplete3);*/
	this->studentDaysToComplete.push_back(studentDaysToComplete.at(0));
	this->studentDaysToComplete.push_back(studentDaysToComplete.at(1));
	this->studentDaysToComplete.push_back(studentDaysToComplete.at(2));
	this->studentDegreeType = studentDegreeType;
	return;
}
Student::~Student() {
}
string Student::GetStudentID(){
	return studentID;
}
void Student::SetStudentID(string studentID){
	this->studentID = studentID;
	return;
}
string Student::GetStudentFirstName() {
	return (studentFirstName);
}
void Student::SetStudentFirstName(string studentFirstName) {
	this->studentFirstName = studentFirstName;
	return;
}
string Student::GetStudentLastName() {
	return studentLastName;
}
void Student::SetStudentLastName(string studentLastName) {
	this->studentLastName = studentLastName;
	return;
}
string Student::GetStudentEmail() {
	return studentEmail;
}
void Student::SetStudentEmail(string studentEmail) {
	this->studentEmail = studentEmail;
	return;
}
string Student::GetStudentAge() {
	return studentAge;
}
void Student::SetStudentAge(string studentAge) {
	this->studentAge = studentAge;
	return;
}
vector<string> Student::GetStudentDaysToComplete() {
	return studentDaysToComplete;
}
void Student::SetStudentDaysToComplete(string studentDaysToComplete1, string studentDaysToComplete2, string studentDaysToComplete3) {
	studentDaysToComplete.push_back(studentDaysToComplete1);
	studentDaysToComplete.push_back(studentDaysToComplete2);
	studentDaysToComplete.push_back(studentDaysToComplete3);
	return;
}
void Student::SetDegreeProgram(string studentDegreeType) {
	this->studentDegreeType = studentDegreeType;
	return;
}
int Student::GetDegreeProgram() {
	return(-1);
}
void Student::PrintStudentData() {
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