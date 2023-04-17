#include "card.hpp"
using namespace ariel;

Card :: Card(int v, string Suit){
    val = v;
    suit = Suit;
}

int Card :: compare(Card otro){
    if (val ==1 && otro.val>2){
        return 1;
    }
    if (otro.val ==1 && val >2){
        return -1;
    }    
    if (val == otro.val)
        return 0;
    return (val >= otro.val ? (val == otro.val ? 0 : 1) : -1);
}

