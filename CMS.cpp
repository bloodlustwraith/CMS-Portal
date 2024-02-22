#include <Windows.h>
#include <iostream>
#include "CMS.h"

using namespace std;


int CMS::Portal(string type)
{
	system("cls");
	system("color F0");

	drawer.DesignFirst(20, 100, 5, 12);
	drawer.CordXY(25, 7);
	cout << "\t\tW E L C O M E  T O  " << type << "   P O R T A L\n";

	drawer.CordXY(21, 9);
	drawer.Line(79);

	drawer.DesignFirst(40, 77, 13, 15);
	drawer.CordXY(38, 14);
	cout << "\t\t  Press 1 to Login";

	drawer.DesignFirst(40, 77, 16, 18);
	drawer.CordXY(38, 17);
	cout << "\t\t Press 2 to Register";

	drawer.DesignFirst(38, 79, 19, 21);
	drawer.CordXY(40, 20);
	cout << "      Press 3 to forget password" << endl;

	drawer.DesignFirst(38, 79, 22, 24);
	drawer.CordXY(40, 23);
	cout << "     Press 4 to back to CMS Portal";

	drawer.DesignFirst(48, 60, 25, 27);
	drawer.CordXY(49, 26);
	int a;
	cout << "Choose: ";
	cin >> a;

	return a;
}



void CMS::LoadingScreen()
{
	drawer.CordXY(30, 12);
	system("color F4");
	cout << "Loading:";
	char x = 219;
	for(int i = 0; i < 30; i++)
	{
		cout << x;
		Sleep(30);
		if(i == 5)
		{
			Sleep(500);
		}
		if(i == 20)
		{
			Sleep(200);
		}
	}

}


void CMS::Home()
{
	while(true)
	{
		system("color F0");
		system("cls");

		drawer.DesignFirst(32, 77, 5, 7);
		drawer.CordXY(37, 6);
		cout << "  W E L C O M E   T O    C   M   S" << endl;

		drawer.CordXY(35, 10);
		cout << "Press 1 to open admin portal";

		drawer.CordXY(35, 11);
		drawer.Line(30);

		drawer.CordXY(35, 12);
		cout << "Press 2 to open Faculty Portal";

		drawer.CordXY(35, 13);
		drawer.Line(30);

		drawer.CordXY(35, 14);
		cout << "Press 3 to open Student Portal " << endl;

		drawer.CordXY(35, 15);
		drawer.Line(30);

		drawer.CordXY(35, 16);
		cout << "Press 4 to Exit " << endl;

		drawer.CordXY(35, 17);
		drawer.Line(25);

		cout << endl;

		drawer.DesignFirst(35, 46, 18, 20);
		drawer.CordXY(36, 19);
		cout << "Choose: ";

		int d;
		cin >> d;

		if(d == 1)
		{
			Admin("admin", 1234);
		}
		else if(d == 2)
		{
			FacultyPortal();
		}
		else if(d == 3)
		{
			StudentPortal();
		}
		else if(d == 4)
		{
			return;
		}
	}
}


void CMS::FacultyPortal()
{
	int selection = Portal("F A C U L T Y");
	Faculty faculty;

	if(selection == 1)
	{
		faculty.Login();
	}
	else if(selection == 2)
	{
		faculty.Register();
	}
	else if(selection == 3)
	{
		faculty.ForgotPassword();

	}
	else if(selection == 4)
	{
		return;
	}

	FacultyPortal();
}

void CMS::StudentPortal()
{
	int selection = Portal("S T U D E N T");
	Student student;

	if(selection == 1)
	{
		student.Login();
	}
	else if(selection == 2)
	{
		student.Register();
	}
	else if(selection == 3)
	{
		student.ForgotPassword();
	}
	else if(selection == 4)
	{
		return;
	}

	StudentPortal();
}

int CMS::Admin(string username, int password)
{
	system("cls");

a:
	drawer.DesignFirst(32, 82, 5, 12);
	drawer.CordXY(34, 7);
	cout << "W E L C O M E    T O    A D M I N   P O R T A L\n";

	drawer.CordXY(35, 9);
	drawer.Line(45);

	drawer.DesignFirst(36, 68, 14, 16);
	drawer.CordXY(37, 15);
	cout << "Enter your Username: ";
	cin >> AU;
	cout << endl;

	drawer.DesignFirst(36, 68, 18, 20);
	drawer.CordXY(37, 19);
	cout << "Enter your Password: ";
	cin >> AP;

	if(AU != username || AP != password)
	{
		system("cls");
		cout << "\nWrong password or user name\n";
		goto a;
	}
	else
	{
	b:
		system("cls");

		drawer.DesignFirst(31, 87, 4, 6);
		drawer.CordXY(32, 5);
		cout << "Press 1 to see if a Faculty member is registered or not" << endl;

		drawer.DesignFirst(29, 89, 9, 11);
		drawer.CordXY(30, 10);
		cout << "Press 2 to see if a particular Student is registered or not" << endl;

		drawer.DesignFirst(43, 74, 13, 15);
		drawer.CordXY(44, 14);
		cout << "Press 3 to back to CMS portal";

		drawer.DesignFirst(51, 63, 16, 18);
		drawer.CordXY(52, 17);
		cout << "Choose: ";

		int a;
		cin >> a;
		if(a == 1)
		{
			Faculty faculty;
			faculty.Search();
		}
		else if(a == 2)
		{
			Student student;
			student.Search();
		}
		else if(a == 3)
		{
			Home();
		}
		else if(a > 3)
		{
			goto b;
		}

		return a;
	}
}