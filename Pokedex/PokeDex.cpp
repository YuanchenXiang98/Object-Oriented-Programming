#include "PokeDex.h"
using namespace std;
#include <limits>
#include <random>
#pragma warning(disable:6386)
extern int IsDeleteValid(int num);
extern int IsAddValid(int num);
extern int IsIDValid(int num);
extern int IsTypeValid(int num);
extern int IsClearValid(int num);

PokeDex::PokeDex() {
	// 1. document does not exist
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open()) {
		this->m_PokemonNum = 0;
		this->m_PokemonArray = NULL;
		this->m_isFileEmpty = true;
		ifs.close();
		return;
	}
	// 2. document does exist but is empty
	char character;
	ifs >> character;
	if (ifs.eof()) {
		this->m_PokemonNum = 0;
		this->m_PokemonArray = NULL;
		this->m_isFileEmpty = true;
		ifs.close();
		return;
	}
	// document does exist, and is not empty
	int num_Pokemon = this->getPokemonNum();
	this->m_PokemonNum = num_Pokemon;
	this->m_PokemonArray = new Pokemon * [this->m_PokemonNum];
	this->initial_Pokemon();

}
void PokeDex::show_menu() {
	cout << "***************************************************************" << endl;
	cout << "*****************Welcome to use the PokeDex********************" << endl;
	cout << "****This tool is used to check the information of Pokemon******" << endl;
	cout << "*******************  0.  Exit the PokeDex  ********************" << endl;
	cout << "*******************  1.  Add new Pokemon   ********************" << endl;
	cout << "*******************  2.  Show all Pokemon  ********************" << endl;
	cout << "*******************  3.  Delete Pokemon    ********************" << endl;
	cout << "*******************  4.  Clear PokeDex     ********************" << endl;
	cout << "*******************  5.  Log Out           ********************" << endl;
	cout << "***************************************************************" << endl;
}
void PokeDex::exit_pokedex() {
	cout << "Thanks for using PokeDex!" << endl;
	exit(0);
}
void PokeDex::savefile() {
	// open file
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	// save all the pokemon in the file
	for (int i = 0; i < this->m_PokemonNum; i++) {
		ofs << this->m_PokemonArray[i]->m_id << " "
			<< this->m_PokemonArray[i]->m_Name << " "
			<< this->m_PokemonArray[i]->m_Typeid << endl;
	}
	ofs.close();
}
int PokeDex::getPokemonNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int num = 0;
	int id;
	string name;
	int typeID;
	// read each line and count how many pokemons in the file
	while (ifs >> id && ifs >> name && ifs >> typeID) {
		num++;
	}
	ifs.close();
	// return the number
	return num;
}

void PokeDex::initial_Pokemon() {
	// initial the array
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int index = 0;
	int id;
	string name;
	int typeID;
	// read all the pokemon in file and store in a array
	while (ifs >> id && ifs >> name && ifs >> typeID) {
		Pokemon* PKM = NULL;
		if (typeID == 1) {
			PKM = new Grass(id, name, typeID);
		}
		else if (typeID == 2) {
			PKM = new Fire(id, name, typeID);
		}
		else{
			PKM = new Water(id, name, typeID);
		}
		this->m_PokemonArray[index] = PKM;
		index++;
	}
	ifs.close();
}
void PokeDex::show_Pokemon() {
	// if the file is empty, display nothing and ask user to catch pokemon
	if (this->m_isFileEmpty == true) {
		cout << "The PokeDex is empty by now! Catch more Pokemon!" << endl;
	}
	// if the file is not empty, display all the pokemon
	else {
		for (int i = 0; i < this->m_PokemonNum; i++) {
			this->m_PokemonArray[i]->showInfo();
		}
	}
}
void PokeDex::deletePokemon() {
	// if the file is empty, there is nothing to delete
	if (this->m_isFileEmpty == true) {
		cout << "File is empty or does not even exist!" << endl;
	}
	// we can start to delete
	else {
		int id = 0;
		cout << "Please enter the id of Pokemon that you want to delete:  ";
		id = IsDeleteValid(id);
		// check whether this pokemon exist in the file
		int result = this->isExisted(id);
		// use next one to cover the present one
		if (result != -1) {
			for (int i = result; i < this->m_PokemonNum - 1; i++) {
				this->m_PokemonArray[i] = this->m_PokemonArray[i + 1];
			}
			this->m_PokemonNum--;
			this->savefile();
			cout << "Successfully deleted!" << endl;
		}
		else {
			cout << "This id of Pokemon does not exist!!" << endl;
		}
	}
}

void PokeDex::ClearPokemon() {
	cout << "Do you really want to clear all your PokeDex?" << endl;
	cout << endl;
	cout << "Press 1 for Confirm!" << "      " << "Press 2 for Cancel!" << endl;
	int user_choice = 0;
	cout << "Enter your choice:  ";
	// input validation
	user_choice = IsClearValid(user_choice);
	// if user confirms, then we start to clear
	if (user_choice == 1) {
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (this->m_PokemonArray != NULL) {
			for (int i = 0; i < this->m_PokemonNum; i++) {
				if (this->m_PokemonArray[i] != NULL) {
					delete this->m_PokemonArray[i];
					this->m_PokemonArray[i] = NULL;
				}
			}
			delete[] this->m_PokemonArray;
			this->m_PokemonArray = NULL;
			this->m_isFileEmpty = true;
		}
		cout << "Successfully clear all the Pokemon in PokeDex!" << endl;
	}
}

void PokeDex::addPokemon() {
	cout << "How many Pokemon do you want to add:  ";
	int addNum = 0;
	addNum = IsAddValid(addNum);
	int newSize = this->m_PokemonNum + addNum;
	// create a new array to store the Pokemon
	Pokemon** newArray = new Pokemon * [newSize];
	// copy the old array to the new array
	if (this->m_PokemonArray != NULL) {
		for (int i = 0; i < this->m_PokemonNum; i++) {
			newArray[i] = this->m_PokemonArray[i];
		}
	}
	// add new Pokemon
	for (int i = 0; i < addNum; i++) {
		int id = 0;
		string name;
		int typeChoice = 0;
		cout << "Please enter the id for " << i + 1 << "th Pokemon:  ";
		id = IsIDValid(id);
		cout << "Please enter the name for " << i + 1 << "th Pokemon:  ";
		cin >> name;
		cout << "1. Grass" << endl;
		cout << "2. Fire" << endl;
		cout << "3. Water" << endl;
		cout << "Please enter the type for " << i + 1 << "th Pokemon:  ";
		typeChoice = IsTypeValid(typeChoice);
		Pokemon* PKM = NULL;
		// ask user to choose type
		switch (typeChoice) {
		case 1:
			PKM = new Grass(id, name, typeChoice);
			break;
		case 2:
			PKM = new Fire(id, name, typeChoice);
			break;
		case 3:
			PKM = new Water(id, name, typeChoice);
			break;
		default:
			break;
		}
		// store all new Pokemon in the Array
		newArray[this->m_PokemonNum + i] = PKM;
	}
	delete[] this->m_PokemonArray;
	this->m_PokemonArray = newArray;
	this->m_PokemonNum = newSize;
	this->m_isFileEmpty = false;
	cout << "Successfully Added " << addNum << " Pokemons!" << endl;
	this->savefile();
}

int PokeDex::isExisted(int id) {
	int index = -1;
	// check whether the pokemon exist in the file
	for (int i = 0; i < this->m_PokemonNum; i++) {
		if (this->m_PokemonArray[i]->m_id == id) {
			index = i;
		}
	}
	return index;
}
PokeDex::~PokeDex() {
	if (this->m_PokemonArray != NULL) {
		for (int i = 0; i < this->m_PokemonNum; i++) {
			if (this->m_PokemonArray[i] != NULL) {
				delete this->m_PokemonArray[i];
			}
		}
		delete[] this->m_PokemonArray;
		this->m_PokemonArray = NULL;
	}
}
