#ifndef CARD
#define CARD
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std; 

namespace ariel{
class Card{

    public: 
        int val;
        string suit;

        Card(int vali, string Suit);
        int compare(Card otro);
};
}
#endif