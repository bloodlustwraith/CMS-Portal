#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include "Mark.h"
#include "Attendance.h"

using namespace std;

class Subject
{
private:
	Mark m;
	Attendance *attendance;
	string subjectName;
	int creditHours;

public:
	void ViewAvailableSubjects();
	int GetSubjectCount();
	int getSubjectMarkCount();
	int getSubjectAttendanceCount();
	void RegisterSubjectToStudent(string studentName);
	bool DoesSubjectExist(string subject);
	bool IsSubjectRegistered(string studentName, string subject);
	void Add();
	void addmarks();
	void markattendance();

};
