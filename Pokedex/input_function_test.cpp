#define CATCH_CONFIG_MAIN
#include "catch.hpp"



extern int IsChoiceValid(int num);
extern int IsChoosenValid(int num);
extern int IsAddValid(int num);
extern int IsIDValid(int num);
extern int IsTypeValid(int num);
extern int IsDeleteValid(int num);

TEST_CASE( "Only 1 or 2 can be entered", "[IsChoiceValid]" )
{

    CHECK_NOTHROW(IsChoiceValid(1));

    CHECK_NOTHROW(IsChoiceValid(2));

    CHECK_NOTHROW(IsChoiceValid(0));

    CHECK_NOTHROW(IsChoiceValid(3));

    CHECK_NOTHROW(IsChoiceValid(-1));

    CHECK_NOTHROW(IsChoiceValid(-1.5));

    CHECK_NOTHROW(IsChoiceValid(1.5));

    CHECK_NOTHROW(IsChoiceValid(3.5));

}

TEST_CASE("Only 0 - 6 can be entered", "[IsChossenValid]")
{


    CHECK_NOTHROW(IsChoiceValid(0));

    CHECK_NOTHROW(IsChoiceValid(3));

    CHECK_NOTHROW(IsChoiceValid(6));

    CHECK_NOTHROW(IsChoiceValid(-1));

    CHECK_NOTHROW(IsChoiceValid(7));

    CHECK_NOTHROW(IsChoiceValid(-1.5));

    CHECK_NOTHROW(IsChoiceValid(3.5));

    CHECK_NOTHROW(IsChoiceValid(7.5));

}

TEST_CASE("1.Only valid integer number ( bigger than 0 ) can be entered", "[IsAddValid]")
{

    CHECK_NOTHROW(IsAddValid(1));

    CHECK_NOTHROW(IsAddValid(10));

    CHECK_NOTHROW(IsAddValid(10000000));

    CHECK_NOTHROW(IsAddValid(0));

    CHECK_NOTHROW(IsAddValid(-1));

    CHECK_NOTHROW(IsAddValid(-1.5));

    CHECK_NOTHROW(IsAddValid(1.5));

}

TEST_CASE("2.Only valid integer number ( bigger than 0 ) can be entered", "[IsIDValid]")
{

    CHECK_NOTHROW(IsIDValid(1));

    CHECK_NOTHROW(IsIDValid(10));

    CHECK_NOTHROW(IsIDValid(10000000));

    CHECK_NOTHROW(IsIDValid(0));

    CHECK_NOTHROW(IsIDValid(-1));

    CHECK_NOTHROW(IsIDValid(-1.5));

    CHECK_NOTHROW(IsIDValid(1.5));

}

TEST_CASE("Only 1 - 3 can be entered", "[IsTypeValid]")
{

     CHECK_NOTHROW(IsTypeValid(1));

     CHECK_NOTHROW(IsTypeValid(2));

     CHECK_NOTHROW(IsTypeValid(3));

     CHECK_NOTHROW(IsTypeValid(0));

     CHECK_NOTHROW(IsTypeValid(4));

     CHECK_NOTHROW(IsTypeValid(-1));

     CHECK_NOTHROW(IsTypeValid(-1.5));

     CHECK_NOTHROW(IsTypeValid(4.5));

     CHECK_NOTHROW(IsTypeValid(2.5));

}

TEST_CASE("3.Only valid integer number ( bigger than 0 ) can be entered", "[IsDeleteValid]")
{

    CHECK_NOTHROW(IsDeleteValid(1));

    CHECK_NOTHROW(IsDeleteValid(10));

    CHECK_NOTHROW(IsDeleteValid(10000000));

    CHECK_NOTHROW(IsDeleteValid(0));

    CHECK_NOTHROW(IsDeleteValid(-1));

    CHECK_NOTHROW(IsDeleteValid(-1.5));

    CHECK_NOTHROW(IsDeleteValid(1.5));

}
