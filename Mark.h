#pragma once
#include <iostream>
#include<vector>
#include<fstream>
using namespace std;

class Mark
{

public:
	string student;
	string subject;
	int mark;

	vector<Mark> getsubjectMarks();
	bool IsStudentRegisterSubjects(string);
	bool doesstudentexist(string);


};

