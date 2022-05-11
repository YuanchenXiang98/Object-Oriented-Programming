#include "Fire.h"
using namespace std;

Fire::Fire(){}
// constructor with initial information.
Fire::Fire(int id, string name, int typeID) {
	this->m_id = id;
	this->m_Name = name;
	this->m_Typeid = typeID;
}
// show all the information of pokemon
void Fire::showInfo() {
	cout << "The Pokemon ID is: " << this->m_id;
	cout << "\tThe name is: " << this->m_Name;
	cout << "\tThe type is: " << this->getType() << endl;
}
// return the type.
string Fire::getType() {
	return string("Fire");
}
