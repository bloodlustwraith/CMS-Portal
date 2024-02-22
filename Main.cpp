#include "Graphics.h"
#include <iostream>
#include <windows.h>
#include "CMS.h"
#include "User.h"
#include "Faculty.h"
#include "Student.h"

int main()
{
	Graphics g;
	CMS cms;
	g.startCMS();
	cms.LoadingScreen();
	cms.Home();
	g.endCMS();

	
}