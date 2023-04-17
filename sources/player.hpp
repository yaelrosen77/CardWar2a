#ifndef PLAYER
#define PLAYER
#include <iostream>
#include "card.hpp"
#include <vector>
#include <cstdlib>
constexpr int CAPACITY = 52;

using namespace std;

namespace ariel{
    
class Player{
    public: 
        string name;
        vector<Card> loot;
        vector<Card> mazoCartas;
        int Numofwins;

        Player(string nombre);
        int stacksize();
        int cardesTaken();
        Card play();
};
}
#endif