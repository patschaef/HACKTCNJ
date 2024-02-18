#ifndef BETS_H
    #define BETS_H
#include "structs.h"

using namespace std;

void fold(player *players, int index, table *curr_table);
void match(player *players, int index, table *curr_table);
void raise(player *players, int index, table *curr_table);

void bets(player *players, int playerNum, table *curr_table){
    for(int i = 0; i < playerNum; i++){
        if(players[i].folded == false){
            players[i].PrintHand();
            cout << "Chips: " << players[i].chips << endl;
            cout << "Player Number: " << i << "\nRaise[0], Check/Match[1], or Fold[2]" << endl;
            int choice;
            cin >> choice;
            if(choice == 0){
                raise(players, i, curr_table);
            }
            else if (choice == 1){
                match(players, i, curr_table);
            }
            else if(choice == 2){
                fold(players, i, curr_table);
            }
            else{
                cout << "Choice error" << endl;
            }
        }
    }
};

void fold(player *players, int index, table *curr_table){
    players[index].folded = true;
};

void match(player *players, int index, table *curr_table){
    if(players[index].chips >= curr_table->curr_raise){
        players[index].chips -= curr_table->curr_raise;
    }
    else{
        cout << "Matching Error: Auto Fold" << endl;
        fold(players, index, curr_table);
    }
};

void raise(player *players, int index, table *curr_table){
    int ammount;
    cout << "How much?" << endl;
    cin >> ammount;
    if(players[index].chips > ammount && curr_table->raise(ammount)){
        players[index].chips -= ammount;
    }
    else{
        cout << "Raise Error: Auto Match" << endl;
        match(players, index, curr_table);
    }
};
#endif