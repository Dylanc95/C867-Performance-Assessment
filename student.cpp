#include <iostream>
#include <string>

#include "student.h"

//D1-Create student class

student::student(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int days1, int days2, int days3, DegreeProgram degreeProgram) {
	studentID = studentID;
	firstName = firstName;
	lastName = lastName;
	emailAddress = emailAddress;
	studentAge = studentAge;
	numDaysInProgramArray[0] = days1;
	numDaysInProgramArray[1] = days2;
	numDaysInProgramArray[2] = days3;
	degreeProgram = degreeProgram;
};

//Student destructor
student::~student() {
	cout << "Student destructor called" << endl;
};

//D2b-mutators
void student::SetStudentID(string studentID) {
	this->studentID = studentID;
};

void student::SetFirstName(string firstName) {
	this->firstName = firstName;
};

void student::SetLastName(string lastName) {
	this->lastName = lastName;
};

void student::SetEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
};

void student::SetAge(int studentAge) {
	this->studentAge = studentAge;
};

void student::SetNumDaysArray(int days1, int days2, int days3) {
	numDaysInProgramArray[0] = days1;
	numDaysInProgramArray[1] = days2;
	numDaysInProgramArray[2] = days3;
};

void student::SetDegreeProgram(DegreeProgram degreeProgram) {

};

//D2a-accessors
string student::GetStudentID() const {
	return studentID;
}

string student::GetFirstName() const {
	return firstName;
}

string student::GetLastName() const {
	return lastName;
}

string student::GetEmailAddress() const {
	return emailAddress;
}

int student::GetAge() const {
	return studentAge;
}

int *student::GetNumDaysArray() const {
	return numDaysInProgramArray; 
}

DegreeProgram student::GetDegreeProgram() const {
	return degreeProgram; 
}

//D2e print function
void student::PrintAll() const {
	cout <<
		"Student ID: " << studentID <<
		"\tFirst Name: " << firstName <<
		"\tLast Name: " << lastName <<
		"\tAge: " << studentAge <<
		"\tDays in Course: " << numDaysInProgramArray[0] << ", " << numDaysInProgramArray[1] << ", " << numDaysInProgramArray[2] <<
		"\tDegree Program: " << Roster::castDegreeProgramToString(degreeProgram) << endl;
}