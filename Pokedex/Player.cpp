#include "Player.h"
#include <iostream>
#include <limits>
using namespace std;
extern int IsAddValid(int num);
extern int IsIDValid(int num);
extern int IsTypeValid(int num);

Player::Player() {}

void Player::addPokemon() {
	cout << "How many Pokemon do you want to add:  ";
	int addNum = 0;
	// input validation
	addNum = IsAddValid(addNum);
	// this is the newsize of the new array
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
		// ask user to choose which type they want
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
	// delete old array
	delete[] this->m_PokemonArray;
	this->m_PokemonArray = newArray;
	this->m_PokemonNum = newSize;
	this->m_isFileEmpty = false;
	cout << "Successfully Added " << addNum << " Pokemons!" << endl;
	// save it in the file
	this->savefile();
}

void Player::ClearPokemon() {
	cout << "You are a Player! You do not have right to clear Pokemon!!" << endl;
}

Player::~Player(){}
