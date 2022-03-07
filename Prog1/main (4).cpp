// Name : Cameron Hay
// Class (CECS 282-04)
// Project Name (Prog 1 – Solitaire Prime)
// Due Date (09/14/2021)
// I certify that this program is my own original work. I did not copy any part of this program from any other source. I further certify that I typed each and every line of code in this program
#include <stack> // double check with professor to see if you can use this!
#include <iostream>
#include "Deck.h"
#include "Card.h"
using namespace std;
Deck deck;

//void playGame();
//void isPrime(int number);

bool isPrime(int number){
  if (number <= 1)
      return false;
  for (int i = 2; i <= number/2; i++)
      if (number % i == 0)
        return false;
  return true;
}


void printStackReverse(stack<Card> s){
  if (s.empty()){
    return;
  }
  Card var = s.top();
  s.pop();

  printStackReverse(s);
  var.showCard();
  cout << " ";
  s.push(var);
}

void playGame(Deck deck){

  int piles = 0;
  int sum = 0;
  stack<Card> cards_count;
  cout << "\nPlaying Solitaire Prime!!!\n\n";
 
  while (deck.leftCards() != 0) {
 
    Card card = deck.deal();
    sum += card.getValue();
 
    if (isPrime(sum) == true) {
    cards_count.push(card);
 
    printStackReverse(cards_count);
    cards_count = stack<Card>();
    cout << " Prime: " << sum << endl;
    piles ++;
    sum = 0;
  }
  else {
    cards_count.push(card);
  }
}
 
 if (sum!=0) {
   printStackReverse(cards_count);
   cards_count = stack<Card>();
   cout << " Loser\n";
 }
 else {
   cout << "\nWinner in " << piles << " piles!\n";
 }
}


int main() {
  int option;
	Deck deck;
  do
    {   
      cout << "Welcome to Solitaire Prime!\n1) New Deck\n2) Display Deck\n3) Shuffle Deck\n4) Play Solitaire\n5) Exit\n\nPlease enter your choice: ";
      option = 0;
      cin >> option;
      if (option ==1){
        cout << "You have refreshed the deck... \n" <<endl;
        deck.newDeck();
      }
      else if(option==2){
       deck.deckDisplay();
      }
      else if(option ==3){
      cout << "You have shuffled the deck... \n" <<endl;
      deck.shuffle();
       }
      else if(option ==4){
      playGame(deck);
      }
      else if(option ==5){
      cout << "You have left the game... Goodbye\n" <<endl;
      }
      else{
      cout << "Incorrect response... Try again\n" <<endl;
      }
       
    } while (option != 5);
return 0;
}

