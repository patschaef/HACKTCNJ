#ifndef WINNER_H
    #define WINNER_H
#include "deck.h"
#include "structs.h"

using namespace std;

bool Flush(card* cards){
    int hCount = 0, cCount = 0, sCount = 0, dCount = 0;
    for(int i = 0; i<7; i++){
        switch(cards[i].suite){
            case 0:
                hCount++;
                break;
            case 1:
                cCount++;
                break;
            case 2:
                sCount++;
                break;
            case 3: 
                dCount++;
                break;
        }
    }
    int biggest = max(max(hCount, cCount), max(sCount, dCount));
    return biggest > 4;
};

bool Straight(card* cards){

};

bool StraightFlush(card* cards){return Flush(cards) && Straight(cards);};

bool FullHouse(card* cards){

};
bool FourKind(card* cards){

};
bool ThreeKind(card* cards){

};
bool TwoPair(card* cards){

};
bool Pair(card* cards){

};

int winner(player *players, int index, table *curr_table){

};

#endif