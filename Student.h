#pragma once

#include "User.h"
#include <fstream>
#include "Subject.h"

using namespace std;

class Student : public User
{
private:
	Subject subject;
protected:

	string studentId;
	bool CheckRegistration(string registerID) ;

public:
	void Login() ;
	void Register() ;
	void ForgotPassword();
	void StudentPortal();
	void RegisterSubjectsForStudent(string studentName);
	void Search();
	void viewMarks();
	void viewAttendance();
};
