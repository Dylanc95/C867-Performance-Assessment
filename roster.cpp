#include <iostream>
#include <string>
#include <map>
#include "student.h"
#include "degree.h"
#include "roster.h"
using namespace std;

//E1 Create roster class
Roster::Roster(int rosterSize) {
	Roster::rosterSize = rosterSize;

	for (int i = 0; i < rosterSize; i++) {
		classRosterArray[i] = nullptr;
	};
};

Roster::~Roster() {
	for (int i = 0; i < rosterSize; i++) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	};
	cout << "Roster destructor called" << endl;
};

void Roster::parse() {
	for (int s = 0; s < rosterSize; s++) {
		classRosterArray[s] = Roster::parseLine(studentDataTable[s]);
	};
};

Student* Roster::parseLine(std::string dataLine) {

	std::string delimiter = ","; 
	std::string studentArray[9];
	std::size_t lastDelimiter = 0; 
	int counter = 0;
	while ((dataLine.find(delimiter, lastDelimiter + delimiter.length())) != std::string::npos) {
		studentArray[counter] = dataLine.substr(lastDelimiter, dataLine.find(delimiter, lastDelimiter) - lastDelimiter);
		lastDelimiter = dataLine.find(delimiter, lastDelimiter) + delimiter.length();
		counter++;
	};
	
	studentArray[8] = dataLine.substr(lastDelimiter);

	return new Student(
		studentArray[0], // studentID
		studentArray[1], // firstName
		studentArray[2], // lastName
		studentArray[3], // email
		std::stoi(studentArray[4]), // age, cast to int
		std::stoi(studentArray[5]), // courseTime1, cast to int
		std::stoi(studentArray[6]), // courseTime2, cast to int
		std::stoi(studentArray[7]), // courseTime3, cast to int
		castToDegreeProgram(studentArray[8]) // degreeProgram, cast to enum DegreeProgram
	);
};

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	classRosterArray[rosterSize] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);

	cout << "Student added" << endl;
}

void Roster::remove(string studentID) {
	bool wasStudentRemoved = false;
	
	for (int i = 0; i < rosterSize; i++) {
		if (classRosterArray[i] == nullptr) {
			continue;
		};
		if (classRosterArray[i]->getStudentID() == studentID) {
			classRosterArray[i] = nullptr;
			wasStudentRemoved = true;
		};
	};

	if (wasStudentRemoved) cout << "Student was removed." << endl;
	else cout << "Student ID not found." << endl;
}

void Roster::printAll() {
	cout << endl;
	for (int s = 0; s < rosterSize; s++) {
		if (classRosterArray[s] != nullptr) {
			classRosterArray[s]->print();
		}
	}
}

void Roster::printInvalidEmails() {
	for (int i = 0; i < rosterSize; i++) {

		if (classRosterArray[i] != nullptr) {
			string email = classRosterArray[i]->getEmailAddress();
			if ((email.find(" ") != string::npos) || (email.find(".") == string::npos) || (email.find("@") == string::npos)) {
				cout << "INVALID EMAIL: " << email << endl;
			}
		}
	}
}

void Roster::AverageDaysInProgram(string studentID) {
	for (int i = 0; i < rosterSize; i++) {
		if (classRosterArray[i] == nullptr) {
			continue;
		};
		if (classRosterArray[i]->getStudentID() == studentID) {
			int* courseArray = classRosterArray[i]->getDaysPerCourseArray();
			int totalDays = 0;
			int arrayLength = 3;

			for (int i = 0; i < arrayLength; i++) {
				totalDays = totalDays + courseArray[i];
			};

			cout << "Average days per course: Student " << studentID << ": " << totalDays / arrayLength << endl;
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	for (int i = 0; i < rosterSize; i++) {
		if (classRosterArray[i] != nullptr) {
			if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
				classRosterArray[i]->print();
			}
		}
	}
}

DegreeProgram Roster::castToDegreeProgram(string degreeString) {
	if (degreeString == "SECURITY") {
		return DegreeProgram::SECURITY;
	}
	else if (degreeString == "NETWORK") {
		return DegreeProgram::NETWORK;
	}
	else if (degreeString == "SOFTWARE") {
		return DegreeProgram::SOFTWARE;
	}
};

string Roster::castDegreeProgramToString(DegreeProgram degreeEnum) {
	if (degreeEnum == DegreeProgram::SECURITY) {
		return "Security";
	}
	else if (degreeEnum == DegreeProgram::NETWORK) {
		return "Network";
	}
	else if (degreeEnum == DegreeProgram::SOFTWARE) {
		return "Software";
	}
}