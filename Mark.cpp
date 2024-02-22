#include "Mark.h"


bool Mark :: doesstudentexist(string studentname)
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
vector<Mark> Mark::getsubjectMarks()
{
	vector<Mark> marks;
	ifstream data7("subjectmarks.txt");

	Mark mark;

	while(data7 >> mark.student >> mark.subject >> mark.mark)
	{
		marks.push_back(mark);
	}

	return marks;
}

bool Mark :: IsStudentRegisterSubjects(string studentName)
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
