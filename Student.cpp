#include "Student.h"

using namespace std;

void Student::ForgotPassword()
{
	int option;

	system("cls");
	
	drawer.DesignFirst(33, 72, 3, 5);
	drawer.CordXY(34, 4);
	cout << "Press 1 to search your ID by username " << endl;

	drawer.DesignFirst(33, 72, 6, 8);
	drawer.CordXY(34, 7);
	cout << "Press 2 to go back to Student Portal " << endl;

	drawer.DesignFirst(45, 60, 9, 11);
	drawer.CordXY(46, 10);
	cout << "Choose: ";
	cin >> option;

	switch(option)
	{
	case 1:
	{
	c:
		int count = 0, v, d;
		string searchid, sID, searchpassword;

		system("cls");

		drawer.DesignFirst(29, 90, 9, 11);
		drawer.CordXY(30, 10);
		cout << "Enter the username which you remembered: ";
		cin >> searchid;

		ifstream search("studentacc.txt");

		while(search >> sID >> searchpassword)
		{
			if(sID == searchid)
			{
				count = 1;
				break;
			}
		}
		search.close();
		if(count == 1)
		{
			drawer.CordXY(35, 14);
			cout << "Your account has been found!";

			drawer.CordXY(38, 17);
			cout << "Your password is: " << searchpassword << endl;

			drawer.CordXY(38, 18);
			drawer.Line(20);
			cout << endl;

			drawer.DesignFirst(34, 80, 19, 21);
			drawer.CordXY(35, 20);
			cout << "Press 1 to back to student portal: ";
			cin >> d;
			if(d == 1)
			{
				return;
			}
		}
		else
		{
			drawer.CordXY(39, 13);
			cout << "Sorry your account is not found! " << endl;

			drawer.CordXY(39, 14);
			drawer.Line(33);

			drawer.DesignFirst(34, 80, 16, 18);
			drawer.CordXY(35, 17);
			cout << "Press 1 to again check your password: ";
			cin >> v;
			if(v == 1)
			{
				goto c;
			}
		}
		break;
	}
	case 2:
	{
		return;
	}
	default:
		cout << "\t\t\t Wrong choice! Please try again";

		break;
	}
}

bool Student::CheckRegistration(string registerID)
{
	string a;
	int b;

	ifstream data4("studentacc.txt");
	while(data4 >> a >> b)
	{
		if(a == registerID)
		{
			return true;
		}
	}

	return false;
}

void Student::StudentPortal()
{
	system("cls");
	system("color F0");
	drawer.CordXY(39, 5);
	cout << studentId << " You are successfully login";

	drawer.CordXY(45, 7);
	cout << "Thank You for login";
	cout << endl;


	drawer.DesignFirst(38, 73, 9, 11);
	drawer.CordXY(39, 10);
	cout << " Press 4 to register for subjects";
	drawer.DesignFirst(41, 69, 12, 14);
	drawer.CordXY(42, 13);
	cout << "Press 5 to view your marks" << endl;
	drawer.DesignFirst(37, 73, 15, 17);
	drawer.CordXY(38, 16);
	cout << "  Press 6 to view your Attendance";;
	drawer.DesignFirst(40, 70, 18, 20);
	drawer.CordXY(41, 19);
	cout << "  Press 7 to back to portal";
	drawer.DesignFirst(49, 60, 21, 23);
	drawer.CordXY(50, 22);
	cout << "Choose: ";
	int a;
	cin >> a;

	if(a == 4)
	{
		system("cls");
		RegisterSubjectsForStudent(studentId);
		StudentPortal();
	}

	if(a == 5)
	{
		system("cls");
		viewMarks();
	}
	if(a == 6)
	{
		system("cls");
		viewAttendance();
	}

	if(a == 7)
	{
		return;
	}
}

void Student::Login()
{
	system("color F0");
	system("cls");
b:

	string userId, id, password, pass;

	drawer.CordXY(39, 5);
	cout << "Please Enter User ID and Password " << endl;

	drawer.DesignFirst(38, 66, 9, 11);
	drawer.CordXY(39, 10);
	cout << "USERNAME: ";
	cin >> userId;

	drawer.DesignFirst(38, 66, 9, 13);
	drawer.CordXY(39, 12);
	cout << "PASSWORD: ";
	cin >> password;

	int count = 0;
	ifstream data("studentacc.txt");
	while(data >> id >> pass)
	{
		if(id == userId && pass == password)
		{
			count = 1;
			system("cls");
		}
	}

	if(count == 1)
	{
		
		studentId = userId;
		StudentPortal();
	}
	else
	{
		system("cls");
		system("color 4");
		cout << "\n Error! you have entered wrong username or password please try again :( \n";
		goto b;
	}
}

void Student::RegisterSubjectsForStudent(string studentName)
{


	cout << "Available subjects: " << endl;

	subject.ViewAvailableSubjects();

	cout << endl;
	cout << endl;

	int subjectCount = 0;

	while(true)
	{
		subject.RegisterSubjectToStudent(studentName);
		cout << "Press 1 to go back to portal or 2 to register another subject: " << endl;
		string b;
		cin >> b;

		if(b == "1")
		{
			return;
		}
	}
}

void Student::Register()
{
	string registerID, id, pass, registerpassword;
	while(true)
	{
		system("cls");

		drawer.CordXY(32, 6);
		cout << "Enter Username and Password for Registration";
		drawer.DesignFirst(38, 66, 9, 11);

		drawer.CordXY(39, 10);
		cout << "Enter Username: ";
		cin >> registerID;

		drawer.DesignFirst(38, 66, 9, 13);
		drawer.CordXY(39, 12);
		cout << "Enter Password: ";
		cin >> registerpassword;

		if(CheckRegistration(registerID) == false)
		{
			break;
		}

		drawer.CordXY(37, 15);
		cout << "This username exist!" << endl;
		system("pause");

	}
	ofstream regist("studentacc.txt", ios::app);
	regist << registerID << ' ' << registerpassword << endl;

	drawer.CordXY(37, 15);
	cout << "Registration is successfull!";

	drawer.CordXY(32, 18);
	cout << "Press 1 to got back to student portal: ";

	drawer.CordXY(71, 18);
	string s;
	cin >> s;
}

void Student::Search()
{
	system("color F0");
	string userID, id, password, pass, USP;
	int count = 0, a;
	system("cls");
b:
	drawer.CordXY(39, 5);
	cout << "Please Enter User ID and Password " << endl;
	drawer.DesignFirst(38, 66, 9, 11);
	drawer.CordXY(39, 10);
	cout << "USERNAME: ";
	cin >> userID;

	ifstream data("studentacc.txt");
	while(data >> id >> USP)
	{
		if(id == userID)
		{
			count = 1;
			system("cls");
		}
	}
	data.close();

	if(count == 1)
	{
		drawer.CordXY(47, 5);
		cout << userID;
		drawer.CordXY(45, 7);
		cout << " User Is found";
		cout << endl;



	}
	else
	{
		system("cls");
		drawer.CordXY(45, 2);
		cout << "User is Not Found";
		cout << endl;
		goto b;
	}

	drawer.CordXY(40, 10);
	cout << "Press 1 to go back to portal: ";
	cin >> a;
	if(a == 1)
	{
		return;
	}
}

void Student::viewMarks()
{
	
	string studentName;
	string subjectName;
	string subjectMark;
	
	ifstream data("subjectmarks.txt");
	while(data >> studentName >> subjectName >> subjectMark)
	{
		if(studentName == studentId)
		{
			cout << subjectName << ": " << subjectMark << endl;
		}
	}

	cout << "Press 1 to go back: ";
	int b;
	cin >> b;
	if(b == 1)
	{
		StudentPortal();
	}
}

void Student::viewAttendance()
{
	string studentName;
	string subjectName;
	string attendance;
	ifstream data("subjectattendance.txt");
	while(data >> studentName >> subjectName >> attendance)
	{
		if(studentName == studentId)
		{
			cout << "Your attendance: " << endl;
			cout << subjectName << ": " << attendance << endl;
		}
	}

	cout << "Press 1 to go back: ";
	int b;
	cin >> b;
	if(b == 1)
	{
		StudentPortal();
	}
}