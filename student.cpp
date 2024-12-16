#include <iostream>
#include <string>

#include "student.h"
#include "roster.h"
#include "degree.h"

//D1-Create student class

Student::Student(string sID, string fName, string lName, string email, int sAge, int courseTime1, int courseTime2, int courseTime3, DegreeProgram degreeProg) {
	studentID = sID;
	firstName = fName;
	lastName = lName;
	emailAddress = email;
	age = sAge;
	daysPerCourseArray[0] = courseTime1;
	daysPerCourseArray[1] = courseTime2;
	daysPerCourseArray[2] = courseTime3;
	degreeProgram = degreeProg;
};

//D2b-mutators
void Student::setStudentID(std::string newStudentID) {
	studentID = newStudentID;
};

void Student::setFirstName(std::string newFirstName) {
	firstName = newFirstName;
};

void Student::setLastName(std::string newLastName) {
	lastName = newLastName;
};

void Student::setEmailAddress(std::string newEmailAddress) {
	emailAddress = newEmailAddress;
};

void Student::setAge(int newAge) {
	age = newAge;
};

void Student::setDaysPerCourseArray(int courseTime1, int courseTime2, int courseTime3) {
	daysPerCourseArray[0] = courseTime1;
	daysPerCourseArray[1] = courseTime2;
	daysPerCourseArray[2] = courseTime3;
};

void Student::setDegreeProgram(DegreeProgram newDegreeProgram) {

};

//D2a-accessors
string Student::getStudentID() {
	return studentID;
};

string Student::getFirstName() {
	return firstName;
};

string Student::getLastName() {
	return lastName;
};

string Student::getEmailAddress() {
	return emailAddress;
};

int Student::getAge() {
	return age;
};

int* Student::getDaysPerCourseArray() {
	return daysPerCourseArray;
};

DegreeProgram Student::getDegreeProgram() {
	return degreeProgram;
}

//D2e print function
void Student::print() {
	cout <<
		"Student ID: " << studentID <<
		"\tFirst Name: " << firstName <<
		"\tLast Name: " << lastName <<
		"\tAge: " << age <<
		"\tDays in Course: " << daysPerCourseArray[0] << ", " << daysPerCourseArray[1] << ", " << daysPerCourseArray[2] <<
		"\tDegree Program: " << Roster::castDegreeProgramToString(degreeProgram) << endl;
}