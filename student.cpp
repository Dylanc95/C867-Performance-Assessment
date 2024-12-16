#include <iostream>
#include <string>

#include "student.h"

//D1-Create student class
student::student() {
	studentID = "";
	firstName = "";
	lastName = "";
	emailAddress = "";
	studentAge = 0;
	this->numDaysInProgram = new int[3];
}

student::student(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int days1, int days2, int days3, DegreeProgram type) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->studentAge = studentAge;
	this->numDaysInProgram = new int[3];
	numDaysInProgram[0] = days1;
	numDaysInProgram[1] = days2;
	numDaysInProgram[2] = days3;
}

//D2b-mutators
void student::SetStudentID(string studentID) {
	this->studentID = studentID;
}

void student::SetFirstName(string firstName) {
	this->firstName = firstName;
}

void student::SetLastName(string lastName) {
	this->lastName = lastName;
}

void student::SetEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}

void student::SetAge(int studentAge) {
	this->studentAge = studentAge;
}

void student::SetNumDays(int* days) {
	numDaysInProgram[0] = days[0];
	numDaysInProgram[1] = days[1];
	numDaysInProgram[2] = days[2];
}

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

int *student::GetNumDays() const {
	return numDaysInProgram; 
}

DegreeProgram student::GetDegreeProgram() const {
	return degreeProgram; 
}

//D2e print function
void student::PrintAll() const {
	int* tDays = GetNumDays();
	string degPr = "Software";
	if (GetDegreeProgram() == DegreeProgram::NETWORK) {
		degPr = "Network";
	}
	if (GetDegreeProgram() == DegreeProgram::SECURITY) {
		degPr = "Security";
	}
	cout << GetStudentID();
	cout << "\tFirst Name: " << GetFirstName();
	cout << "\tLast Name: " << GetLastName();
	cout << "\tAge: " << GetAge();
	cout << "\tDays in course: " << "{" << tDays[0] << ", " << tDays[1] << ", " << tDays[2] << "}";
	cout << "\tDegree Program: " << degPr << "." << endl;
}