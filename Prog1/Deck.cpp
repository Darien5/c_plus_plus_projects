#include "Card.h"
#include "Deck.h"
#include <iostream>
using namespace std;

// Deck and NewDeck can be the same?
Deck :: Deck(){
  char ranks[] = {'A','1','2','3','4','5','6','7','8','9','J','Q','K'};
  char suits[] = {'C','S','H','D'};

int k = 0;
for (int i = 0; i < 4; i++){
  for (int j = 0; j < 13; j++){
    deck[k++] = Card(ranks[j], suits[i]);
  }
}
cardsCount = 52;
}

void Deck :: newDeck(){
  char ranks[] = {'A','1','2','3','4','5','6','7','8','9','J','Q','K'};
  char suits[] = {'C','S','H','D'};

int k = 0;
for (int i = 0; i < 4; i++){
  for (int j = 0; j < 13; j++){
    deck[k++] = Card(ranks[j], suits[i]);
  }
}
cardsCount = 52;
}


Card Deck :: deal(){
  Card count = deck[cardsCount - 1];
  cardsCount--;
  return count;
}

void Deck :: shuffle(){
  srand(0);
  for (int i = 0; i < cardsCount; i++){
    int r = i + (rand() % (52-i));
    Card v = deck[i];
    deck[i] = deck[r];
    deck[r] = v;
  }
}

int Deck::leftCards() {
	return cardsCount; // 52 - cardCount
}

void Deck :: deckDisplay(){
  for (int i=0; i<52; i++){
    if (i % 13 == 0 && i !=0){
      cout << endl;
      deck[i].showCard();
      cout << " ";
    }
    else{
      deck[i].showCard();
      cout << ' ';
    }
  }
}
