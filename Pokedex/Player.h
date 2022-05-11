#include "PokeDex.h"
#pragma once

class Player : public PokeDex {
public:
	Player(); // constructor
	void addPokemon(); // add Pokemon, rewrite the function
	void ClearPokemon(); // clear Pokemon, rewrite the function
	~Player(); // destructor
};