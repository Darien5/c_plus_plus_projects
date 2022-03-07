#include <iostream>
#include "Card.h"
using namespace std;


Card :: Card() {
  rank = ' ';
  suit = ' ';
};

Card :: Card(char r, char s){
  rank = r;
  suit = s;
}

void Card :: setCard(char r, char s){
  rank = r;
  suit = s;
}
int Card :: getValue(){
  if (rank == 'A'){
   value = 1;
  }
  else if (rank == '2'){
    value = 2;
  }
  else if (rank == '3'){
    value = 3;
  }
  else if (rank == '4'){
    value = 4;
  }
  else if (rank == '5'){
    value = 5;
  }
  else if (rank == '6'){
    value = 6;
  }
  else if (rank == '7'){
    value = 7;
  }
  else if (rank == '8'){
    value = 8;
  }
  else if (rank == '9'){
    value = 9;
  }
   
// Jack Queen and Kings have a value of 10!
  else if (rank == 'J'){
    value = 10;
  }
  else if (rank == 'Q'){
    value = 10;
  }
  else if (rank == 'K'){
    value = 10;
  }
  else if (rank == 'T'){
    value = 10;
  }
  return value;
}

 void Card :: showCard(){
  if (rank == 'T'){
    cout << 10 << suit << " ";
  }
  else {
    cout << rank << suit << " ";
  }
}