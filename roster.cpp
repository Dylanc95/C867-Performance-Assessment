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
};

void Roster::parse() {
	for (int s = 0; s < rosterSize; s++) {
		classRosterArray[s] = Roster::parseLine(studentData[s]);
	};
};

student* Roster::parseLine(string dataLine) {
	string delim = ",";
	string sArray[9];
	size_t lastDelim = 0;
	int count = 0;

	while ((dataLine.find(delim, lastDelim + delim.length())) != string::npos) {
		sArray[count] = dataLine.substr(lastDelim, dataLine.find(delim, lastDelim) - lastDelim);
		lastDelim = dataline.find(delim, lastDelim) + delim.length();
		count++;
	};

	studentArray[8] = dataLine.substr(lastDelim);

	return new Student(
		studentArray[0], //studentID
		studentArray[1], //firstName
		studentArray[2], //lastName
		studentArray[3], //email
		stoi(studentArray[4]), //age
		stoi(studentArray[5]), //daysInCourse1
		stoi(studentArray[6]), //daysInCourse2
		stoi(studentArray[7]), //daysInCourse3
		castToDegreeProgram(studentArray[8]) //degree program
	);
};

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int studentAge, int numDaysInProgram1, int numDaysInProgram2, int numDaysInProgram3, DegreeProgram degreeProgram) {
	classRosterArray[rosterSize] = new Student(studentID, firstName, lastName, emailAddress, studentAge, numDaysInProgram1, numDaysInProgram2, numDaysInProgram3, degreeProgram);

	cout << "Student added" << endl;
}

void Roster::remove(string studentID) {
	bool wasStudentRemoved = false;
	
	for (int i = 0; i < rosterSize; i++) {
		if (classRosterArray[i] == nullptr) {
			continue;
		};
		else if (classRosterArray[i]->GetStudentID() == studentID) {
			classRosterArray[i] = nullptr;
			wasStudentRemoved = true;
		};
	};

	if (wasStudentRemoved) {
		cout << "Student was removed." << endl;
	};
	else {
		cout << "Student ID not found." << endl;
	};
}

void Roster::printAll() {
	cout << endl;
	for (int s = 0; s < rosterSize; s++) {
		if (classRosterArray[s] != nullptr) {
			classRosterArray[s].PrintAll();
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
	for (int i = 0; i < rosterSize; i++) {
		if (classRosterArray[i] == nullptr) {
			continue;
		}
		else if (classRosterArray[i]->GetStudentID() == studentID) {
			int* courseArray = classRosterArray[i]->GetNumDaysArray();
			int totalDays = 0;
			int arrayLength = 3;

			for (int i = 0; i < arrayLength; i++) {
				totalDays = totalDays + courseArray[i];
			}

			cout << "Average days per course: " << totalDays / arrayLength << endl;
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degree) {
	for (int i = 0; i < rosterSize; i++) {
		if (classRosterArray[i] != nullptr) {
			if (classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
				classRosterArray[i]->PrintAll();
			}
		}
	}
}

DegreeProgram Roster::castToDegreeProgram(string degreeString) {
	if (degreeString == "SECURITY") {
		return SECURITY;
	}
	else if (degreeString == "NETWORK") {
		return NETWORK;
	}
	else if (degreeString == "SOFTWARE") {
		return SOFTWARE;
	}
};

string Roster::castDegreeProgramToString(DegreeProgram degreeEnum) {
	if (degreeEnum == SECURITY) {
		return "Security";
	}
	else if (degreeEnum == NETWORK) {
		return "Network";
	}
	else if (degreeEnum == SOFTWARE) {
		return "Software";
	}
}