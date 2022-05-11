#include "Doctor.h"
#include <iostream>
#include <limits>
using namespace std;
extern int IsClearValid(int num);
//constructor
Doctor::Doctor(){}

// Doctor is not able to add pokemon, therefore, we rewrite the function in doctor class.
void Doctor::addPokemon() {
	cout << "You are a doctor! your duty is not catching Pokemon!" << endl;
}

// Doctor is able to clear all the Pokemon
void Doctor::ClearPokeDex() {
	cout << "Do you really want to clear all your PokeDex?" << endl;
	cout << endl;
	cout << "Press 1 for Confirm!" << "      " << "Press 2 for Cancel!" << endl;
	int user_choice = 0;
	cout << "Enter your choice:  ";
	// input validation, check whether user give valid input.
	user_choice = IsClearValid(user_choice);
	// if user choose confirm, then it will clear all the Pokemons.
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

Doctor::~Doctor(){}
