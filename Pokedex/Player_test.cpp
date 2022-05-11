#define CATCH_CONFIG_MAIN
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
#include "catch.hpp"
using namespace std;

TEST_CASE("add pokemon","[addPokemon]")
{

    Player P;


    REQUIRE_NOTHROW(P.addPokemon());


    P.show_Pokemon();

}
