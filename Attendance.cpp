#include "Attendance.h"


bool Attendance::doesstudentexist(string studentname)
{
	string a;
	int b;
	ifstream data3("studentacc.txt");
	while(data3 >> a >> b)
	{
		if(a == studentname)
		{
			return true;
		}
	}
	data3.close();
	return false;
}

bool Attendance::IsStudentRegisterSubjects(string studentName)
{
	string a;
	string b;


	ifstream data8("studentSubjects.txt");

	while(data8 >> a >> b)
	{
		return true;
	}
	data8.close();
	return false;
}

 vector <Attendance> getsubjectattendance()
 {
	vector<Attendance> attendances;

	ifstream data10("subjectattendance.txt");

	Attendance attendance;

	while(data10 >> attendance.student >> attendance.subject >> attendance.attendance)
	{
		attendances.push_back(attendance);
	}

	return attendances;
 }

 vector<Attendance> Attendance::getsubjectattendance()
 {
	 return vector<Attendance>();
 }

