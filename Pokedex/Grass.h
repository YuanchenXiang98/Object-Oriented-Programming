#pragma once
#include <iostream>
#include <string>
#include "Pokemon.h"

class Grass : public Pokemon {
public:
	Grass(); // constructor
	Grass(int id, std::string name, int typeID); // constructor with initial information
	virtual void showInfo(); // show information of pokemon
	virtual std::string getType(); // rerurn the type
};