#define CATCH_CONFIG_MAIN
#include <iostream>
#include <string>
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

TEST_CASE("Print menu" , "[show_menu]")
{

    PokeDex P;
    
    CHECK_NOTHROW(P.show_menu());
    
}



TEST_CASE("Print all of the pokemon" , "[show_Pokemon]")
{

    Player P2;
    
    SECTION("empty")
    {

       CHECK_NOTHROW(P2.show_Pokemon());

    }

    SECTION("There is data to be show")
    {

       P2.addPokemon();

       CHECK_NOTHROW(P2.show_Pokemon());

    }
    
}

TEST_CASE("delete the data of pokemons" , "[deletePokemon]")
{

    PokeDex P;

    Player P2;

    Doctor D;

    D.ClearPokeDex();
    
    SECTION("empty")
    {

        CHECK_NOTHROW(P.deletePokemon());

    }

    SECTION("Delete the Pokémon with the specified ID")
    {

        P2.addPokemon();

        P2.show_Pokemon();

        CHECK_NOTHROW(P.deletePokemon());

        P2.show_Pokemon();

    }
    
}

TEST_CASE("get the number of pokemon","[getPokemonNum]")
{

    PokeDex P;

    Player P2;

    Doctor D;

    SECTION("return the number of pokemon")
    {
    
         CHECK_NOTHROW(P.getPokemonNum());

    }

    SECTION("empty")
    {
         
         D.ClearPokeDex();
    
         CHECK_NOTHROW(P.getPokemonNum());

    }
    
}
