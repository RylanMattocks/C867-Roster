
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "roster.h"
#include "student.h"
#include "degree.h"
#include "softwareStudent.h"
#include "securityStudent.h"
#include "networkStudent.h"
using namespace std;

Roster::Roster() {
	return;
}

Roster::~Roster() {
	delete myPointer;
}

void Roster::Add(string studentID, string firstName, string lastName, string emailAddress, 
	string age, string daysInCourse1, string daysInCourse2, string daysInCourse3, string degreeProgram) {
	int degreeSelector = -1;
	this->daysInCourse.push_back(daysInCourse1);
	this->daysInCourse.push_back(daysInCourse2);
	this->daysInCourse.push_back(daysInCourse3);
	vector<string> classObj;
	classObj.push_back(studentID);
	classObj.push_back(firstName);
	classObj.push_back(lastName);
	classObj.push_back(emailAddress);
	classObj.push_back(age);
	classObj.push_back(daysInCourse1);
	classObj.push_back(daysInCourse2);
	classObj.push_back(daysInCourse3);
	classObj.push_back(degreeProgram);
	
	if (degreeProgram == "SECURITY") {
		degreeSelector = 0;
	}
	else if (degreeProgram == "NETWORK") {
		degreeSelector = 1;
	}
	else if (degreeProgram == "SOFTWARE") {
		degreeSelector = 2;
	}
	
	switch (degreeSelector) {
	case SECURITY:
	{
		SecurityStudent secStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
		
		for (int i = 0; i < 9; ++i) {
			myPointer = new string;
			*myPointer = classObj.at(i);
			classRosterArray.push_back(myPointer);
		}
		break;
	}
	case NETWORK:
	{
		NetworkStudent netStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
		
		for (int i = 0; i < 9; ++i) {
			myPointer = new string;
			*myPointer = classObj.at(i);
			classRosterArray.push_back(myPointer);
		}
		break;
	}
	case SOFTWARE:
	{
		SoftwareStudent softStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
		
		for (int i = 0; i < 9; ++i) {
			myPointer = new string;
			*myPointer = classObj.at(i);
			classRosterArray.push_back(myPointer);
		}
		break;
	}
	default:
		break;
	}
	return;
}

void Roster::Remove(string studentID) {
	int count = 0;
	for (int i = 0; i < classRosterArray.size(); i += 9) {
		if (*classRosterArray.at(i) == studentID) {
			classRosterArray.erase((classRosterArray.begin() + i), classRosterArray.begin() + i + 9);
			++count;
		}
	}
	if (count == 0) {
		cout << "Student ID: " << studentID << " not found." << endl;
	}

	return;
}

void Roster::PrintAverageDaysInCourse(string studentID) {
	int averageDays = 0;
	for (int i = 0; i < classRosterArray.size(); i+=9) {
		if (*classRosterArray.at(i) == studentID) {
			string text = "";
			text = *classRosterArray.at(i + 5);
			int number1;
			int number2;
			int number3;
			stringstream ss(text);
			ss >> number1;
			text = *classRosterArray.at(i + 6);
			stringstream SS(text);
			SS >> number2;
			text = *classRosterArray.at(i + 7);
			stringstream Ss(text);
			Ss >> number3;

			averageDays = (number1 + number2 + number3) / 3;
			cout << "Average days in course: " << averageDays << endl;
		}
	}
	return;
}


void Roster::PrintInvalidEmails() {
	string email = "";
	int atCounter = 0;
	int spaceCounter = 0;
	vector<string> student1Array;
	vector<string> student2Array;
	vector<string> student3Array;
	vector<string> student4Array;
	vector<string> student5Array;
	student1Array.push_back(*classRosterArray.at(5));
	student1Array.push_back(*classRosterArray.at(6));
	student1Array.push_back(*classRosterArray.at(7));
	student2Array.push_back(*classRosterArray.at(14));
	student2Array.push_back(*classRosterArray.at(15));
	student2Array.push_back(*classRosterArray.at(16));
	student3Array.push_back(*classRosterArray.at(23));
	student3Array.push_back(*classRosterArray.at(24));
	student3Array.push_back(*classRosterArray.at(25));
	student4Array.push_back(*classRosterArray.at(32));
	student4Array.push_back(*classRosterArray.at(33));
	student4Array.push_back(*classRosterArray.at(34));
	student5Array.push_back(*classRosterArray.at(41));
	student5Array.push_back(*classRosterArray.at(42));
	student5Array.push_back(*classRosterArray.at(43));

	Student student1(*classRosterArray.at(0), *classRosterArray.at(1), *classRosterArray.at(2), *classRosterArray.at(3), 
		*classRosterArray.at(4), student1Array, *classRosterArray.at(8));
	Student student2(*classRosterArray.at(9), *classRosterArray.at(10), *classRosterArray.at(11), *classRosterArray.at(12), 
		*classRosterArray.at(13), student2Array, *classRosterArray.at(17));
	Student student3(*classRosterArray.at(18), *classRosterArray.at(19), *classRosterArray.at(20), *classRosterArray.at(21), 
		*classRosterArray.at(22), student3Array, *classRosterArray.at(26));
	Student student4(*classRosterArray.at(27), *classRosterArray.at(28), *classRosterArray.at(29), *classRosterArray.at(30), 
		*classRosterArray.at(31), student4Array, *classRosterArray.at(35));
	Student student5(*classRosterArray.at(36), *classRosterArray.at(37), *classRosterArray.at(38), *classRosterArray.at(39),
		*classRosterArray.at(40), student5Array, *classRosterArray.at(44));

	email = student1.GetStudentEmail();
	atCounter = 0;
	spaceCounter = 0;
	for (int i = 0; i < email.length(); ++i) {
		if (email.at(i) == ' ') {
			++spaceCounter;
		}
		if (email.at(i) == '@') {
			++atCounter;
		}
	}

	if (!((email.at(email.length() - 4)) == '.')) {
		cout << "Invalid Email: " << email << endl;
	}
	else if (!(atCounter == 1)) {
		cout << "Invalid Email: " << email << endl;
	}
	else if (spaceCounter > 0) {
		cout << "Invalid Email: " << email << endl;
	}


	email = student2.GetStudentEmail();
	atCounter = 0;
	spaceCounter = 0;
	for (int i = 0; i < email.length(); ++i) {
		if (email.at(i) == ' ') {
			++spaceCounter;
		}
		if (email.at(i) == '@') {
			++atCounter;
		}
	}

	if (!((email.at(email.length() - 4)) == '.')) {
		cout << "Invalid Email: " << email << endl;
	}
	else if (!(atCounter == 1)) {
		cout << "Invalid Email: " << email << endl;
	}
	else if (spaceCounter > 0) {
		cout << "Invalid Email: " << email << endl;
	}


	email = student3.GetStudentEmail();
	atCounter = 0;
	spaceCounter = 0;
	for (int i = 0; i < email.length(); ++i) {
		if (email.at(i) == ' ') {
			++spaceCounter;
		}
		if (email.at(i) == '@') {
			++atCounter;
		}
	}

	if (!((email.at(email.length() - 4)) == '.')) {
		cout << "Invalid Email: " << email << endl;
	}
	else if (!(atCounter == 1)) {
		cout << "Invalid Email: " << email << endl;
	}
	else if (spaceCounter > 0) {
		cout << "Invalid Email: " << email << endl;
	}


	email = student4.GetStudentEmail();
	atCounter = 0;
	spaceCounter = 0;
	for (int i = 0; i < email.length(); ++i) {
		if (email.at(i) == ' ') {
			++spaceCounter;
		}
		if (email.at(i) == '@') {
			++atCounter;
		}
	}

	if (!((email.at(email.length() - 4)) == '.')) {
		cout << "Invalid Email: " << email << endl;
	}
	else if (!(atCounter == 1)) {
		cout << "Invalid Email: " << email << endl;
	}
	else if (spaceCounter > 0) {
		cout << "Invalid Email: " << email << endl;
	}


	email = student5.GetStudentEmail();
	atCounter = 0;
	spaceCounter = 0;
	for (int i = 0; i < email.length(); ++i){
		if (email.at(i) == ' ') {
			++spaceCounter;
		}
		if (email.at(i) == '@') {
			++atCounter;
		}
	}

	if (!((email.at(email.length() - 4)) == '.')) {
		cout << "Invalid Email: " << email << endl;
	}
	else if (atCounter < 1) {
		cout << "Invalid Email: " << email << endl;
	}
	else if (spaceCounter > 0) {
		cout << "Invalid Email: " << email << endl;
	}
	
	return;
}

void Roster::PrintByDegreeProgram(int degreeProgram) {
	switch (degreeProgram) {
	case SOFTWARE: {
		for (int i = 0; i < classRosterArray.size(); ++i) {
			if (*classRosterArray.at(i) == "SOFTWARE") {
				cout << "StudentID is: " << *classRosterArray.at(i - 8) << endl;
				cout << "Student First Name is: " << *classRosterArray.at(i - 7) << endl;
				cout << "Student Last Name is : " << *classRosterArray.at(i - 6) << endl;
				cout << "Student Email is: " << *classRosterArray.at(i - 5) << endl;
				cout << "Student Age is: " << *classRosterArray.at(i - 4) << endl;
				cout << "Student Days To Complete: " << *classRosterArray.at(i - 3) << ", " <<
					*classRosterArray.at(i - 2) << ", " << *classRosterArray.at(i - 1) << endl;
				cout << "Student Degree Type: " << "SOFTWARE" << endl;
			}
		}
		break;
	}
	case NETWORK: {
		for (int i = 0; i < classRosterArray.size(); ++i) {
			if (*classRosterArray.at(i) == "NETWORK") {
				cout << "StudentID is: " << *classRosterArray.at(i - 8) << endl;
				cout << "Student First Name is: " << *classRosterArray.at(i - 7) << endl;
				cout << "Student Last Name is : " << *classRosterArray.at(i - 6) << endl;
				cout << "Student Email is: " << *classRosterArray.at(i - 5) << endl;
				cout << "Student Age is: " << *classRosterArray.at(i - 4) << endl;
				cout << "Student Days To Complete: " << *classRosterArray.at(i - 3) << ", " <<
					*classRosterArray.at(i - 2) << ", " << *classRosterArray.at(i - 1) << endl;
				cout << "Student Degree Type: " << "NETWORK" << endl;
			}
		}
		break;
	}

	case SECURITY: {
		for (int i = 0; i < classRosterArray.size(); ++i) {
			if (*classRosterArray.at(i) == "SECURITY") {
				cout << "StudentID is: " << *classRosterArray.at(i - 8) << endl;
				cout << "Student First Name is: " << *classRosterArray.at(i - 7) << endl;
				cout << "Student Last Name is : " << *classRosterArray.at(i - 6) << endl;
				cout << "Student Email is: " << *classRosterArray.at(i - 5) << endl;
				cout << "Student Age is: " << *classRosterArray.at(i - 4) << endl;
				cout << "Student Days To Complete: " << *classRosterArray.at(i - 3) << ", " <<
					*classRosterArray.at(i - 2) << ", " << *classRosterArray.at(i - 1) << endl;
				cout << "Student Degree Type: " << "SECURITY" << endl;
			}
		}
		break;
	}
				   return;
	}
}

void Roster::PrintAll() {
	int i = 0;
	i = classRosterArray.size();
	int j = 0;
	while (j < i) {
		cout << (j / 9) + 1 << "\t" << "First Name: " << *classRosterArray.at(j + 1) << "\t" << "Last Name: " << 
			*classRosterArray.at(j + 2) << "\t" << "Age: " << *classRosterArray.at(j + 4) << "\t" << "daysInCourse: {" << 
			*classRosterArray.at(j + 5) << ", " << *classRosterArray.at(j + 6) << ", " << *classRosterArray.at(j + 7) << 
			"} " << "Degree Program: " << *classRosterArray.at(j + 8) << endl;
		j+=9;
	}
	return;
}




int main() {
	cout << "Scripting and Programming - Applications - C867, Using C++, Student ID: #000939513, Rylan Mattocks" << endl;

	const string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Rylan,Mattocks,rmattoc@wgu.edu,22,31,57,21,SOFTWARE" };
	vector<string> studentDataNew;
	string temp;

	for (int j = 0; j < 5; ++j) {
		stringstream ss(studentData[j]);
		for (int i = 0; i < 9; ++i) {
			getline(ss, temp, ',');
			studentDataNew.push_back(temp);
		}
	}

	Roster classRoster;
	classRoster.Add(studentDataNew.at(0), studentDataNew.at(1), studentDataNew.at(2), studentDataNew.at(3), studentDataNew.at(4),
		studentDataNew.at(5), studentDataNew.at(6), studentDataNew.at(7), studentDataNew.at(8));
	classRoster.Add(studentDataNew.at(9), studentDataNew.at(10), studentDataNew.at(11), studentDataNew.at(12), studentDataNew.at(13),
		studentDataNew.at(14), studentDataNew.at(15), studentDataNew.at(16), studentDataNew.at(17));
	classRoster.Add(studentDataNew.at(18), studentDataNew.at(19), studentDataNew.at(20), studentDataNew.at(21), studentDataNew.at(22), 
		studentDataNew.at(23), studentDataNew.at(24), studentDataNew.at(25), studentDataNew.at(26));
	classRoster.Add(studentDataNew.at(27), studentDataNew.at(28), studentDataNew.at(29), studentDataNew.at(30), studentDataNew.at(31),
		studentDataNew.at(32), studentDataNew.at(33), studentDataNew.at(34), studentDataNew.at(35));
	classRoster.Add(studentDataNew.at(36), studentDataNew.at(37), studentDataNew.at(38), studentDataNew.at(39), studentDataNew.at(40),
		studentDataNew.at(41), studentDataNew.at(42), studentDataNew.at(43), studentDataNew.at(44));
	
	classRoster.PrintAll();
	classRoster.PrintInvalidEmails();

	for (int i = 0; i < studentDataNew.size(); i += 9) {
		classRoster.PrintAverageDaysInCourse(studentDataNew.at(i));
	}

	classRoster.PrintByDegreeProgram(SOFTWARE);
	classRoster.Remove("A3");
	classRoster.Remove("A3");
}