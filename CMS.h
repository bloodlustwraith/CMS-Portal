#pragma once

#include <Windows.h>
#include <iostream>
#include "Drawer.h"
#include "Faculty.h"
#include "Student.h"
#include "User.h"


using namespace std;



class CMS
{
private:
	
	Drawer drawer;
	User user;
	int Portal(string type);

	string AU;
	int AP;


public:

	string StudentID;

	void LoadingScreen();

	void Home();
	void FacultyPortal();
	void StudentPortal();
	int Admin(string username, int password);

	
};