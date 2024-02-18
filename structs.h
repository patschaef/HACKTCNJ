#ifndef STRUCTS_H
    #define STRUCTS_H
#include "deck.h"

using namespace std;

//Each Player has 2 cards
struct player{
    card hand[2];
    int chips;
    bool folded;

    void PrintHand(){
        cout << hand[0].Print() << endl;
        cout << hand[1].Print() << endl;
    }
}; 

struct table{
    int pot;
    int curr_raise;
    card community[5];

    bool raise(int raise){
        if (raise > curr_raise){
            pot += raise;
            curr_raise = raise;
            return true;
        }
        cout << "Raise invalid" << endl;
        return false;
    }
};

#endif