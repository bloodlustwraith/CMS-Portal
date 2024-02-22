#include "Subject.h"
#include "CMS.h"
#include "Drawer.h"
#include "Student.h"
using namespace std;

void Subject::ViewAvailableSubjects()
{


	ifstream subjects("subjects.txt");
	while(subjects >> subjectName >> creditHours)
	{
		cout << subjectName << endl;
	}
}

int Subject::GetSubjectCount()
{
	string a;
	int b;
	int count = 0;

	ifstream data("subjects.txt");
	while(data >> a >> b)
	{
		count++;
	}

	return count;
}
int Subject::getSubjectMarkCount()
{
	string a, b;
	int c;
	ifstream data6("subjectmarks.txt");
	int count = 0;
	while(data6 >> a >> b >> c)
	{
		count++;
	}
	data6.close();
	return count;

}

int Subject::getSubjectAttendanceCount()
{
	string a, b, c;

	ifstream data11("subjectattendance.txt");
	int count = 0;
	while(data11 >> a >> b >> c)
	{
		count++;
	}
	data11.close();
	return count;

}

void Subject::RegisterSubjectToStudent(string studentName)
{
	string selectedSubject;

	ofstream studentSubjects("studentSubjects.txt", ios::app);

	while(true)
	{
		cout << "Enter the name of the subject to register: " << endl << endl;
		cin >> selectedSubject;

		if(DoesSubjectExist(selectedSubject)==false)
		{
			cout << "Subject does not exist!" << endl << endl;
			continue;
		}
		
	

	    if(IsSubjectRegistered(studentName, selectedSubject))
		{
			cout << "You have already registerd this subject!" << endl << endl;
			continue;
		}
		break;
	
	}


	studentSubjects << studentName << " " << selectedSubject << endl;
	
	cout << "You have successfully registerd: " << selectedSubject << endl;
	cout << endl;
}

bool Subject::DoesSubjectExist(string subject)
{
	string a;
	int b;

	ifstream data1("subjects.txt");
	while(data1 >> a >> b)
	{
		if(a == subject)
		{
			return true;
		}
	}

	return false;
}

bool Subject::IsSubjectRegistered(string studentName, string subject)
{
	string a, b;

	ifstream data2("studentSubjects.txt");
	while(data2 >> a >> b)
	{
		if(a != studentName)
		{
			continue;
		}
		if(b == subject)
		{
			return true;
		}
	}

	return false;
}
void Subject::Add()
{
	ofstream subjects("subjects.txt", ios::app);
	int show, a;

	while(true)
	{
		system("cls");

		cout << "Enter the subjects name:" << endl;
		cin >> subjectName;
		cout << "Enter the subject credit hour:" << endl;
		cin >> creditHours;

		if(DoesSubjectExist(subjectName))
		{
			string a;
			cout << "This Subject is Already being added, Press 1 to try again!: ";
			cin >> a;
			continue;

		}
	
		subjects << subjectName << " " << " " << creditHours << endl;

		cout << endl;
	
		cout << "Added subject: " << subjectName << endl;
		cout << endl;

		cout << "Press 1 to go back to proceed or 2 to register another subject: " << endl;
		string b;
		cin >> b;


		if(b == "1")
		{
			break;
		}

	}
	cout << "Press 1 to proceed: ";
	cin >> a;
	if(a == 1)
	{
		Drawer drawer;

		system("cls");
		drawer.DesignFirst(25, 83, 9, 11);
		drawer.CordXY(28, 10);
		cout << "Press 1 to go to the student login to register subjects";
		drawer.DesignFirst(30, 78, 12, 14);
		drawer.CordXY(33, 13);
		cout << "Press 2 to go back to go back CMS Portal";
		drawer.DesignFirst(28, 78, 15, 17);
		drawer.CordXY(33, 16);
		cout << "   Press 3 to go back to faculty Portal";
		drawer.DesignFirst(47, 63, 18, 20);
		drawer.CordXY(48, 19);
		cout << "Choose: ";
		cin >> show;

		if(show == 1)
		{
			Student student;
			student.Login();
		}
		else if(show == 2)
		{
			CMS cms;
			cms.Home();
		}
		else if(show == 3)
		{
			return;
		}
	}


}

void Subject::addmarks()
{
	int a;
	string studentName;
	
	while(true)
	{
		cout << "Enter the name of the student: ";
		cin >> studentName;
		if(m.doesstudentexist(studentName)==false)
		{
			cout << "This student does not exit!" << endl << endl;
			continue;
		}
		if(m.IsStudentRegisterSubjects(studentName)==false)
		{
			cout << "Student have not registerd subjects yet" << endl;
			continue;
		}
		break;

	}

	cout << endl;
	cout << endl;

	cout << "List of subjects the student is registerd to:" << endl;

	ifstream search("studentSubjects.txt");

	string nameSubject;
	string subjectName;

	while(search >> nameSubject >> subjectName)
	{
		if(nameSubject == studentName)
		{
			cout << subjectName << " ";
		}
	}

	cout << endl;
	cout << endl;



	string selectedSubject;

	while(true)
	{
		cout << "Select the subjects you want to add marks to: ";
		cin >> selectedSubject;
		if(DoesSubjectExist(selectedSubject))
		{
			break;
		}
		cout << "Please try again this subject does not exist!" << endl;
	}

	int mark;
	cout << "Type the mark you want to assign to subject " << ": ";
	cin >> mark;

	vector<Mark> marks = m.getsubjectMarks();

	bool doesMarkExist = false;

	for(int i = 0; i < marks.size(); i++)
	{
		if(marks[i].subject != selectedSubject || marks[i].student != studentName)
		{
			continue;
		}

		marks[i].mark = mark;
		doesMarkExist = true;
	}

	if(doesMarkExist == false)
	{
		Mark m;
		m.student = studentName;
		m.subject = selectedSubject;
		m.mark = mark;

		marks.push_back(m);
	}

	ofstream out("subjectmarks.txt", ios::trunc);

	for(int i = 0; i < marks.size(); i++)
	{
		out << marks[i].student << " " << marks[i].subject << " " << marks[i].mark << endl;
	}

	cout << "Do you want to add marks again then press 1: ";
	cin >> a;
	if(a == 1)
	{
		addmarks();
	}
	else
	{
		cout << "Press 1 to go back to portal: ";
		int b;
		cin >> b;
		return;
	}
}


void Subject::markattendance()
{
	int a;
	string studentName;

	while(true)
	{
		cout << "Enter the name of the student: ";
		cin >> studentName;
		if(attendance->doesstudentexist(studentName) == false)
		{
			cout << "This student does not exit!" << endl << endl;
			continue;
		}
		if(attendance->IsStudentRegisterSubjects(studentName) == false)
		{
			cout << "Student have not registerd subjects yet" << endl;
			continue;
		}
		break;

	}

	cout << endl;
	cout << endl;

	cout << "List of subjects the student is registerd to:" << endl;

	ifstream search("studentSubjects.txt");

	string nameSubject;
	string subjectName;

	while(search >> nameSubject >> subjectName)
	{
		if(nameSubject == studentName)
		{
			cout << subjectName << " ";
		}
	}

	cout << endl;
	cout << endl;


	string selectedSubject;

	while(true)
	{
		cout << "Select the subjects you want to mark attendance to: ";
		cin >> selectedSubject;
		if(DoesSubjectExist(selectedSubject))
		{
			break;
		}
		cout << "Please try again this subject does not exist!" << endl;
	}

	string subjectattendance;
	cout << "Mark Attendance (P for Present and A for Absent) " << ": ";
	cin >> subjectattendance;

	vector<Attendance> attendances = attendance->getsubjectattendance();

	bool doesMarkExist = false;

	for(int i = 0; i < attendances.size(); i++)
	{
		if(attendances[i].subject != selectedSubject || attendances[i].student != studentName)
		{
			continue;
		}

		attendances[i].attendance = subjectattendance;
		doesMarkExist = true;
	}

	if(doesMarkExist == false)
	{
		Attendance a;
		a.student = studentName;
		a.subject = selectedSubject;
		a.attendance = subjectattendance;

		attendances.push_back(a);
	}

	ofstream out("subjectattendance.txt", ios::trunc);

	for(int i = 0; i < attendances.size(); i++)
	{
		out << attendances[i].student << " " << attendances[i].subject << " " << attendances[i].attendance << endl;
	}

	cout << "Do you want to mark attendance again then press 1: ";
	cin >> a;
	if(a == 1)
	{

		markattendance();
	}
	else
	{
		cout << "Press 1 to go back to portal: ";
		int b;
		cin >> b;
		return;
	}
}


