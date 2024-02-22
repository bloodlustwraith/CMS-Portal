#pragma once

#include "Drawer.h"

class User
{


protected:
	Drawer drawer;

	virtual bool CheckRegistration(string registerID) { return true; }
public:

	virtual void Login() {};
	virtual void Register() {};
	virtual void ForgotPassword() {};
	virtual void Search() {};
};

