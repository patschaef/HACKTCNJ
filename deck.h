#ifndef DECK_H
    #define DECK_H
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

enum faceCards{jack = 11, queen = 12, king = 13};
enum suites{hearts, clubs, spades, diamonds};

//Card Value
struct card{
    int value;
    int suite;

    card(int v, int s){
        value = v;
        suite = s;
    }

    string Print(){
        string first;
        string last;
        if (value == 1){first = "Ace";}
        else if(value < 11){first  = to_string(value);}
        else if(value == jack){first = "Jack";}
        else if(value == queen){first = "Queen";}
        else if(value == king){first = "King";}

        switch (suite){
            case hearts:
                last = "Hearts";
                break;
            case clubs:
                last = "Clubs";
                break;
            case spades:
                last = "Spades";
                break;
            case diamonds:
                last = "Diamonds";
                break;
        }
        return first + " of " + last;
    }
};

stack<card> createDeck(){
    //create vector with all possible cards
    srand(time(NULL));
    stack<card> deck;
    vector<card> possibleCards;
    for(size_t i = 1; i<14; i++){
        for(size_t j = 0; j<4; j++){
            possibleCards.push_back(card(i, j));
        }
    }

    //Create stack with cards randomized
    for(int i =0; i<52; i++){
        
        int index =  rand() % possibleCards.size();
        card curr = possibleCards.at(index);
        deck.push(curr);

        possibleCards.at(index) = possibleCards.back();
        possibleCards.pop_back();
    }
   return deck;
};

 /* Test Code
    int i = 1;
    while(!deck.empty()){
        
       cout << i << " " << deck.top().Print() << endl;
       i++;
       deck.pop();
    }
    */
   #endif