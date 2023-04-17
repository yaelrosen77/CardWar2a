#ifndef GAME
#define GAME
#include <iostream>
#include <cstdlib>
#include <random> 
#include <algorithm> 
using namespace std;
#include "player.hpp"
using namespace ariel;

namespace ariel {
    class Game{
    public: 
        Player& p1;
        Player& p2;
        vector<Card> deck;
        vector <string> log;
        int NumOfTurns;
        int NumOfDraws;

        Game(Player& player1, Player& player2);

        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();

    private:
        void generateCards();
        void dealCards(int mnt);
        string getString(int val);
    };
}

#endif