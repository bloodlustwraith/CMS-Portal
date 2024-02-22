#pragma once
#include <iostream>
#include<vector>
#include<fstream>
using namespace std;
class Attendance
{
public:
	string student;
	string subject;
	string attendance;

	vector<Attendance> getsubjectattendance();
	bool IsStudentRegisterSubjects(string);
	bool doesstudentexist(string);
};

