#pragma once
#include <iostream>
#include <string>

class Pokemon {
public:
	virtual void showInfo() = 0; // pure virtual function
	virtual std::string getType() = 0; // pure virtual function

	int m_id;
	std::string m_Name;
	int m_Typeid;
};
