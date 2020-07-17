#include <iostream>
//#include <string>
#include "Roster.h"
//#include "student.h"
//#include "student.cpp"

using namespace std;

Roster::Roster()
{
	//this->capacity = 5;
	this->lastIndex = -1; //means empty
}

void Roster::parseThenAdd(string row)
{
	if (lastIndex < capacity) {
		lastIndex++;

		//set id
		size_t rhs = row.find(",");
		string s1 = row.substr(0, rhs);

		//set fname
		size_t lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string s2 = row.substr(lhs, rhs - lhs);

		//set lname
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string s3 = row.substr(lhs, rhs - lhs);

		//set email
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string s4 = row.substr(lhs, rhs - lhs);

		//set age
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		size_t s5 = stoi(row.substr(lhs, rhs - lhs));

		//set days to complete courses
		//num_days[0]
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		size_t s6 = stoi(row.substr(lhs, rhs - lhs));

		//num_days[1]
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		size_t s7 = stoi(row.substr(lhs, rhs - lhs));

		//num_days[2]
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		size_t s8 = stoi(row.substr(lhs, rhs - lhs));

		//set age
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string s9 = (row.substr(lhs, rhs - lhs));

		DegreeProgram d = Security;
		if (s9 == "NETWORK") {
			d = Network;
		}
		if (s9 == "SOFTWARE") {
			d = Software;
		}

		add(s1, s2, s3, s4, s5, s6, s7, s8, d);
	}
}

void Roster::add(string tID, string tFirst, string tLast, string tEmail, int tAge, int tDays0, int tDays1, int tDays2, DegreeProgram tDeg)
{
	int days[Student::SIZE];
	days[0] = tDays0;
	days[1] = tDays1;
	days[2] = tDays2;

	classRosterArray[lastIndex] = new Student(tID, tFirst, tLast, tEmail, tAge, days, tDeg);

}

void Roster::printAll()
{
	for (int i = 0; i < 5; i++)
	{
		if (classRosterArray[i] != NULL)
		{
			classRosterArray[i]->print();
		}
	}
}
void Roster::remove(string studentID)
{
	bool found = false;
	string temp = "";
	int j = 0;

	while (j < 5)
	{
		if (classRosterArray[j] != nullptr)
		{
			temp = classRosterArray[j]->getStudentID();
		}
		if (temp == studentID)
		{
			classRosterArray[j] = nullptr;
			cout << "Student with ID " << studentID << " has been removed." << endl;
			delete classRosterArray[j];
			found = true;
			break;
		}

		j++;

	}
	if (found == false)
	{
		cout << "Student with ID: " << studentID << " is not found." << endl;
	}
	return;
}
void Roster::printAverageDaysInCourse(string studentID)
{
	bool found = false;
	for (int i = 0; i < 5; i++)
	{
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			found = true;
			int sum = classRosterArray[i]->getNumDays()[0] + classRosterArray[i]->getNumDays()[1] + classRosterArray[i]->getNumDays()[2];
			cout << "Average days in course spent by student # " << studentID << " is " << sum / 3 << endl;
		}
	}
	if (!found)cout << "Student not found" << endl;
}

void Roster::printInvalidEmails()
{
	for (int i = 0; i < 5; ++i)
	{
		string email = this->classRosterArray[i]->getEmail();
		if ((email.find("@") == string::npos || email.find(".") == string::npos) || (email.find(" ") != string::npos))
		{
			cout << email << endl;
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram dp)
{
	for (int i = 0; i < 5; i++)
	{
		if (classRosterArray[i]->getDegreeProgram() == dp) classRosterArray[i]->print();
	}
}

Roster::~Roster()//destructor
{
	for (int i = 0; i < 5; i++)
	{
		if (classRosterArray[i] != NULL)
		{
			delete classRosterArray[i];
		}
	}
}