#pragma once
#include "Pokemon.h"
#include <iostream>
#include <string>
class Fire : public Pokemon {
public:
	Fire(); // constructor
	Fire(int id, std::string name, int typeID); // constructor with initial information
	virtual void showInfo(); // show information of pokemon
	virtual std::string getType(); // rerurn the type
};