#include <fstream>
#include <string>
#include "Faculty.h"
#include "Subject.h"
#include <iostream>

using namespace std;

void Faculty::ForgotPassword()
{
	
	system("cls");

	drawer.DesignFirst(33, 72, 3, 5);
	drawer.CordXY(34, 4);
	cout << "Press 1 to search your ID by username " << endl;

	drawer.DesignFirst(33, 72, 6, 8);
	drawer.CordXY(34, 7);
	cout << "Press 2 to go back to Faculty Portal " << endl;

	drawer.DesignFirst(45, 60, 9, 11);
	drawer.CordXY(46, 10);
	cout << "Choose: ";
	int option;
	cin >> option;

	switch(option)
	{
	case 1:
	{
	c:
		system("cls");

		int count = 0, d, v;
		string searchid, sID, searchpassword;

		drawer.DesignFirst(29, 90, 9, 11);
		drawer.CordXY(30, 10);
		cout << "Enter the username which you remembered: ";
		cin >> searchid;

		ifstream search("facultyacc.txt");

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
			cout << "Press 1 to back to Faculty Portal: ";
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

bool Faculty::CheckRegistration(string registerID)
{
	string a;
	int b;
	ifstream data5("facultyacc.txt");

	while(data5 >> a >> b)
	{
		if(a == registerID)
		{
			return true;
		}
	}

	return false;
}
void Faculty::Register()
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

	ofstream regist("facultyacc.txt", ios::app);
	regist << registerID << ' ' << registerpassword << endl;

	drawer.CordXY(37, 15);
	cout << "Registration is successful!";

	drawer.CordXY(32, 18);
	cout << "Press 1 to got back to faculty portal: ";

	drawer.CordXY(71, 18);

	string s;
	cin >> s;

	return;
}

void Faculty::Login()
{
	system("color F0");
	system("cls");

	string  id,  pass;
	int count = 0, a;
b:
	drawer.CordXY(39, 5);
	cout << "Please Enter User ID and Password " << endl;

	drawer.DesignFirst(38, 66, 9, 11);
	drawer.CordXY(39, 10);
	cout << "USERNAME: ";
	cin >> userID;

	drawer.DesignFirst(38, 66, 9, 13);
	drawer.CordXY(39, 12);
	cout << "PASSWORD: ";
	cin >> password;

	ifstream data("facultyacc.txt");
	while(data >> id >> pass)
	{
		if(id == userID && pass == password)
		{
			count = 1;
			system("cls");
		}
	}

	if(count == 1)
	{
		system("color F0");

		drawer.CordXY(39, 5);
		cout << userID << " You are successfully login";

		drawer.CordXY(45, 7);
		cout << "Thank You for login";
		cout << endl;

		drawer.DesignFirst(42, 68, 9, 11);
		drawer.CordXY(43, 10);
		cout << " Press 4 to add subjects";
		drawer.DesignFirst(44, 65, 12, 14);
		drawer.CordXY(45, 13);
		cout << "Press 5 to add marks" << endl;
		drawer.DesignFirst(37, 73, 15, 17);
		drawer.CordXY(38, 16);
		cout << " Press 6 for mark your Attendance";;
		drawer.DesignFirst(40, 70, 18, 20);
		drawer.CordXY(41, 19);
		cout << "  Press 7 to back to portal";
		drawer.DesignFirst(49, 60, 21, 23);
		drawer.CordXY(50, 22);
		cout << "Choose: ";
		cin >> a;
		
		if(a == 4)
		{
			
			subject.Add();
		}
		if(a == 5)
		{
			system("cls");
			subject.addmarks();
		}
		else if(a == 6)
		{
			system("cls");
			subject.markattendance();
		}
		else if(a == 7)
		{
			return;
		}
	}
	else
	{
		system("cls");
		system("color 4");
		cout << "\n Error! you have entered wrong username or password please try again :( \n";
		goto b;
	}
}

void Faculty::Search()
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

	ifstream data("facultyacc.txt");
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
	drawer.CordXY(35, 10);
	cout << "Press 1 to go back to portal: ";
	cin >> a;
	if(a == 1)
	{
		return;
	}
}

