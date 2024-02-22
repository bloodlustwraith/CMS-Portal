#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include "User.h"
#include "Subject.h"

using namespace std;

class Faculty : public User
{
	Subject subject;
	string userID, password;

protected:
	bool CheckRegistration(string registerID) ;
public:
	void Register() ;
	void Login() ;
	void ForgotPassword() ;
	void Search() ;
	
};