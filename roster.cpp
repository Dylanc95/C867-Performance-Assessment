#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "roster.h"
using namespace std;

//E1 Create roster class
Roster::Roster() {
	const string studentDataTable[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Dylan,Childers,dylanc95@gmail.com,29,10,30,15,SOFTWARE"//Section A
	};

	classRosterArr = new student[5];

	for (int i = 0; i < 5; i++) {
		size_t obj1 = studentDataTable[i].find(",");
		string studentID = studentDataTable[i].substr(0, obj1);

		size_t obj2 = obj1 + 1;
		obj1 = studentDataTable[i].find(",", obj2);
		string firstName = studentDataTable[i].substr(obj2, obj1 - obj2);

		obj2 = obj1 + 1;
		obj1 = studentDataTable[i].find(",", obj2);
		string lastName = studentDataTable[i].substr(obj2, obj1 - obj2);

		obj2 = obj1 + 1;
		obj1 = studentDataTable[i].find(",", obj2);
		string emailAddress = studentDataTable[i].substr(obj2, obj1 - obj2);

		obj2 = obj1 + 1;
		obj1 = studentDataTable[i].find(",", obj2);
		int studentAge = stoi(studentDataTable[i].substr(obj2, obj1 - obj2));

		obj2 = obj1 + 1;
		obj1 = studentDataTable[i].find(",", obj2);
		int numDaysInProgram1 = stoi(studentDataTable[i].substr(obj2, obj1 - obj2));

		obj2 = obj1 + 1;
		obj1 = studentDataTable[i].find(",", obj2);
		int numDaysInProgram2 = stoi(studentDataTable[i].substr(obj2, obj1 - obj2));

		obj2 = obj1 + 1;
		obj1 = studentDataTable[i].find(",", obj2);
		int numDaysInProgram3 = stoi(studentDataTable[i].substr(obj2, obj1 - obj2));

		obj2 = obj1 + 1;
		obj1 = studentDataTable[i].find("\0", obj2);
		string type = studentDataTable[i].substr(obj2, obj1 - obj2);
		DegreeProgram dPr = DegreeProgram::SOFTWARE;
		if (type == "NETWORK") {
			dPr = DegreeProgram::NETWORK;
		}
		else if (type == "SECURITY") {
			dPr = DegreeProgram::SECURITY;
		}

		add(studentID, firstName, lastName, emailAddress, studentAge, numDaysInProgram1, numDaysInProgram2, numDaysInProgram3, dPr);
	}

	this->lastInd = 0;

};

Roster::~Roster() {
	cout << endl;
	cout << "Roster destructor called" << endl;
	//delete[] classRosterArr
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int numDaysInProgram1, int numDaysInProgram2, int numDaysInProgram3, DegreeProgram type) {
	student *stud = new student(studentID, firstName, lastName, emailAddress, studentAge, numDaysInProgram1, numDaysInProgram2, numDaysInProgram3, type);
	classRosterArr[lastInd++] = *stud;

	cout << endl << "Student added." << endl;
}

void Roster::remove(string studentID) {
	cout << endl;
	for (int i = 0; i < 5; ++i) {
		if (classRosterArr[i].GetStudentID() == studentID) {
			cout << "Deleting: " << classRosterArr[i].GetStudentID() << endl;
			classRosterArr[i].SetStudentID("Invalid");
		}
		else {
			cout << "Error: Student not found" << endl;
		}
	}
}

void Roster::printAll() {
	cout << endl;
	for (int i = 0; i < 5; ++i) {
		if (classRosterArr[i].GetStudentID() != "Invalid") {
			cout << " ";
			classRosterArr[i].PrintAll();
		}
	}
}

void Roster::printInvalidEmails() {
	cout << endl << "Invalid emails: " << endl;
	for (int i = 0; i < 5; ++i) {
		string email = classRosterArr[i].GetEmailAddress();
		int atSign = email.find('@');
		int perSign = email.find('.', atSign);
		if (perSign == -1) {
			cout << "\t" << email << endl;
		}
		else if (email.find(' ') != -1) {
			cout << "\t" << email << endl;
		}
	}
}

void Roster::AverageDaysInProgram(string studentID) {
	cout << endl;
	for (int i = 0; i < 5; ++i) {
		if (classRosterArr[i].GetStudentID() == studentID) {
			int* tDays = classRosterArr[i].GetNumDays();
			int avgDays = 0;
			for (int j = 0; j < 3; ++j) {
				avgDays += tDays[j];
			}
			cout << "\tAverage number of days: " << avgDays / 3 << endl;
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degree) {
	int numMatch = 0;
	for (int i = 0; i < 5; ++i) {
		if (classRosterArr[i].GetDegreeProgram() == degree) {
			++numMatch; 
			cout << numMatch << " ";
			classRosterArr[i].PrintAll();
		}
	}
}

student Roster::findStudent(int index) {
	return classRosterArr[index];
}