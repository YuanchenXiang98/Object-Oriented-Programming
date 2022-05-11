#include <iostream>
#include <string>
#include <vector>
#include "PokeDex.h"
#include "Fire.h"
#include "Pokemon.h"
#include "Grass.h"
#include "Water.h"
#include "Doctor.h"
#include "Player.h"
#include <limits>
using namespace std;
extern int IsChoiceValid(int num);
extern int IsChoosenValid(int num);

int main(void) {
	// initial three object
	PokeDex PKD;
	Doctor D;
	Player P;
	// start the loop
	while(true){
		int user_choice = 0;
		int bool_num = 1;
		// this is the interface of login
		cout << "************ 1. log in as Doctor ************" << endl;
		cout << "************ 2. log in as Player ************" << endl;
		cout << "Please choose one of the options above:  ";
		// input validation
		user_choice = IsChoiceValid(user_choice);
		int user_choosen;
		// different choice can login as different user
		switch (user_choice) {
		case 1:
			while (bool_num == 1) {
				cout << "You have log in as a Doctor!" << endl;
				D.show_menu();
				cout << "Please choose one of the options above:  ";
				user_choosen = IsChoosenValid(user_choosen);
				switch (user_choosen) {
				case 0:
					D.exit_pokedex(); // exit
					break;
				case 1:
					D.addPokemon(); // add
					break;
				case 2:
					D.show_Pokemon(); // show
					break;
				case 3:
					D.deletePokemon(); // delete
					break;
				case 4:
					D.ClearPokeDex(); // clear
					break;
				case 5:
					bool_num = 2; // this will return to last login interface
					break;
				default:
					break;
				}
			}
		case 2:
			while (bool_num == 1) {
				cout << "You have log in as a Player!" << endl;
				P.show_menu();
				cout << "Please choose one of the options above:  ";
				// input validation
				user_choosen = IsChoosenValid(user_choosen);
				switch (user_choosen) {
				case 0:
					P.exit_pokedex(); // exit
					break;
				case 1:
					P.addPokemon(); // add
					break;
				case 2:
					P.show_Pokemon(); // show
					break;
				case 3:
					P.deletePokemon(); // delete
					break;
				case 4:
					P.ClearPokemon(); // clear
					break;
				case 5:
					bool_num = 2; // return to last login interface
					break;
				default:
					break;
				}
			}
		}
	}
	return 0;
}
