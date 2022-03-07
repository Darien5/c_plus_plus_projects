#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include <string>

using namespace std;

class Deck{
  private:
    Card deck[52]; // Does 52 include jokers? (Lookup)
    int cardsCount;
    int count; //remaining counted
    int top;

  public:
    Deck();
    //Function to refresh deck
    void newDeck(); 

    Card deal();
    //Function should shuffle the deck out of original order
    void shuffle(); 
//Remaining cards
    int leftCards(); 
    void deckDisplay(); //Reveals deck to player

};
#endif
