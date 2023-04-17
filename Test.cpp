#include "doctest.h"
#include <stdexcept>
using namespace std;
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace ariel;

Player p1("Alice"), p2("Bob");

TEST_CASE("After creating two players:"){
    CHECK(p1.name != "");           //name was assigned seccessfully by the constructor
    CHECK(p2.name != "");
    CHECK(p1.stacksize()==0);        //the player cannot receive cards if the game wasnt yet created
    CHECK(p2.cardesTaken()==0);       //it also cannot have cards without a game 
}

Game game(p1,p2);

TEST_CASE("Testing new game created seccessfully:"){
    CHECK(p1.cardesTaken()==0);
    CHECK(p2.cardesTaken()==0);
    CHECK(p1.stacksize()==26);
    CHECK(p2.stacksize()==26);

    CHECK_NOTHROW(game.playTurn());     //check if throws execption also by various rounds
    CHECK(p1.stacksize()<26);           //if both played than both of them need to maintain less than 26 cards
    CHECK(p2.stacksize()<26);
    bool booli = false;
    booli = (p1.cardesTaken()!=0);
    if (booli==false){
        booli=(p2.cardesTaken()!=0);
    }
    CHECK(booli==true);      //after one turn one of the players have to have cards taken
    CHECK_NOTHROW(game.playTurn());
    CHECK_NOTHROW(game.playTurn());
    CHECK_NOTHROW(game.printLastTurn());
}

TEST_CASE("After the game:"){
    CHECK_NOTHROW(game.playAll());
    CHECK_THROWS(game.playTurn());      //should throw an error while trying to play turn after the game is over
    CHECK(p1.stacksize()==0);           //after the game is over, non of the players can have cards left
    CHECK(p2.stacksize()==0);
    CHECK_NOTHROW(game.printLastTurn());
    CHECK_NOTHROW(game.printLog());
    CHECK_NOTHROW(game.printStats());
    CHECK_NOTHROW(game.printWiner());
}

TEST_CASE("Creating a new game with the same players andd checking that the stats are reset:"){
    Game game2(p2,p1);                                      //creating a new one in reverse order
    CHECK(p1.cardesTaken()==0);                              //all data must be reset
    CHECK(p2.cardesTaken()==0);                              //all data must be reset
    CHECK(p1.stacksize()== 26);
    CHECK(p2.stacksize() ==26);
    CHECK_NOTHROW(game2.playTurn());                        //check that it is not throwing error after playing again with the same players
    CHECK_NOTHROW(game2.playAll());
    CHECK_THROWS(game.playTurn());      //should throw an error while trying to play turn after the game is over
    CHECK(p1.stacksize()==0);           //after the game is over, non of the players can have cards left
    CHECK(p2.stacksize()==0);
    CHECK_NOTHROW(game.printLastTurn());
    CHECK_NOTHROW(game.printLog());
    CHECK_NOTHROW(game.printStats());
    CHECK_NOTHROW(game.printWiner());
}