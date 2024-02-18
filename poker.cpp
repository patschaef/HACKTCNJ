#include <iostream>
#include "deck.h"
#include "structs.h"
#include "bets.h"
#include "winner.h"
using namespace std;

void round(int playerNum){
    //Initailize players and table
    player *players;
    players = (player*)malloc(playerNum * sizeof(player));
    for(int i = 0; i<playerNum; i++){
        players[i].folded = false;
        players->chips = 10;
    }


    table *curr_table;
    curr_table->pot = 0;
    curr_table->curr_raise = 0;

    //Cards are delt
    stack<card> deck = createDeck();
    for (int i = 0; i<2; i++){
        for(int j = 0; j<playerNum; j++){
            players[j].hand[i] = deck.top();
            deck.pop();
        }
    }
    deck.pop();
    for(int i = 0; i<5; i++){
        curr_table->community[i] = deck.top();
        deck.pop();
    }
    
    //Pre Flop
    bets(players, playerNum, curr_table);
    //Flop
    cout << curr_table->community[0].Print() << endl;
    cout << curr_table->community[1].Print() << endl;
    cout << curr_table->community[2].Print() << endl << endl;
    bets(players, playerNum, curr_table);
    //Turn
    cout << curr_table->community[0].Print() << endl;
    cout << curr_table->community[1].Print() << endl;
    cout << curr_table->community[2].Print() << endl;
    cout << curr_table->community[3].Print() << endl << endl;
    bets(players, playerNum, curr_table);
    //River
    cout << curr_table->community[0].Print() << endl;
    cout << curr_table->community[1].Print() << endl;
    cout << curr_table->community[2].Print() << endl;
    cout << curr_table->community[3].Print() << endl;
    cout << curr_table->community[4].Print() << endl << endl;
    bets(players, playerNum, curr_table);
};




int main(){

    round(3);

    return 0;
}