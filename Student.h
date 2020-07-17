#pragma once
//#include <iostream>
//#include <string>
#include "DegreeProgram.h"

using namespace std;

class Student
{
public:
	const static int SIZE = 3;

private:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int num_days[SIZE];
	DegreeProgram dp;

public:

	Student(); //empty constructor
	Student(string id, string fname, string lname, string em, int ag, int num_days[], DegreeProgram dp);

	//Accessors
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getNumDays();
	DegreeProgram getDegreeProgram();

	//Mutators
	void setStudentID(string id);
	void setFirstName(string fname);
	void setLastName(string lname);
	void setEmail(string em);
	void setAge(int ag);
	void setNumDays(int num_days[]);
	void setDegreeProgram(DegreeProgram dp);

	void print();

	~Student();

};
