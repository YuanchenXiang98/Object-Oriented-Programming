#pragma once
#include <iostream>
#include "Pokemon.h"
#include "Fire.h"
#include "Grass.h"
#include "Water.h"
#include <fstream>
#define FILENAME "PokemonList.txt"

class PokeDex {
public:
	void show_menu(); // user interface
	void exit_pokedex(); // exit
	void savefile(); // save to a text file and can used to initialise the array
	void PokemonBattle(); // used to battle and show the differences between different type class
	void show_Pokemon(); // Show all the pokemons
	void initial_Pokemon(); // read all pokemon in text file into array
	void deletePokemon(); // delete released pokemon
	void addPokemon(); // add new pokemon
	void ClearPokemon(); // clear all pokemon
	int isExisted(int id); // check whether pokemon exists in the file
	bool m_isFileEmpty;
	int getPokemonNum(); // return the number of Pokemon in the list
	int m_PokemonNum; // Pokemon number
	Pokemon** m_PokemonArray; // pointer to Pokemon
	//void addPokemon(); // add Pokemon to Array
	PokeDex();
	~PokeDex();
};
