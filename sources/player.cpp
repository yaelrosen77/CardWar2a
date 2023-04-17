#include "player.hpp"

using namespace ariel;

Player :: Player(string nombre){
    name = nombre;
    Numofwins = 0;
}

int Player :: stacksize(){
    return mazoCartas.size();
} 

/// @brief 
/// @return 
int Player:: cardesTaken(){
    return loot.size();
}

Card Player :: play(){
    Card tmp = mazoCartas.back();
    mazoCartas.pop_back();
    return tmp;
}