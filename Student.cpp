#include <iostream>
//#include <iomanip>
//#include <string>
#include "student.h"
using namespace std;

Student::Student()
{
}

Student::Student(string id, string fname, string lname, string em, int ag, int num_days[], DegreeProgram dp) {
	this->studentID = id;
	this->firstName = fname;
	this->lastName = lname;
	this->email = em;
	this->age = ag;
	for (int i = 0; i < 3; ++i) this->num_days[i] = num_days[i];
	this->dp = dp;
}

// setters 
void Student::setStudentID(string id) {
	this->studentID = id;
}
void Student::setFirstName(string fname) {
	this->firstName = fname;
}
void Student::setLastName(string lname) {
	this->lastName = lname;
}
void Student::setEmail(string em) {
	this->email = em;
}
void Student::setAge(int ag) {
	this->age = ag;
}
void Student::setNumDays(int num_days[]) {

	for (int i = 0; i < 3; ++i) {
		this->num_days[i] = num_days[i];
	}
}
void Student::setDegreeProgram(DegreeProgram dp) {
	this->dp = dp;
}

//Getters
string Student::getStudentID() {
	return studentID;
}
string Student::getFirstName() {
	return firstName;
}
string Student::getLastName() {
	return lastName;
}
string Student::getEmail() {
	return email;
}
int Student::getAge() {
	return age;
}
int* Student::getNumDays() {
	return num_days;
}
DegreeProgram Student::getDegreeProgram() {
	return dp;
}

void Student::print() {
	cout << left << "ID: " << studentID << " ";
	cout << left << "First: " << firstName << " ";
	cout << left << "Last: " << lastName << " ";
	cout << left << "Email: " << email << " ";
	cout << left << "Age: " << age << " ";
	cout << left << "Days In Courses: {";
	cout << left << num_days[0] << ", ";
	cout << left << num_days[1] << ", ";
	cout << left << num_days[2] << "}" << " Degree Program: ";
	cout << degreeProgramStrings[dp] << " ";
	cout << endl;
}

Student::~Student()
{
}