#ifndef CARD_H
#define CARD_H
#include <string>
using namespace std;

class Card {
  private:
  //card value
    char rank;
  //suit of card 
    char suit; 
    int value; // value for Card.cpp!

  public:
    Card(); 
    Card(char r, char s); 
    //Sets value of card
    void setCard(char r, char s); 
    //Gets the value of the card based on numberic value
    int getValue(); //CHANGE TO getValue()
    //Reveals the card
    void showCard(); 
};
#endif