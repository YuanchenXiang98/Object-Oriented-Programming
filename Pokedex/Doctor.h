#include "PokeDex.h"
#pragma once

class Doctor : public PokeDex {
public:
	Doctor(); // constructor
	void ClearPokeDex(); // rewrite the clear function!
	void addPokemon(); // rewrite the add function!
	~Doctor(); // destructor
};