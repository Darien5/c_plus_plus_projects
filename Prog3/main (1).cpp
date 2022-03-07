// Name : Cameron Hay
// Class (CECS 282-04)
// Project Name (Prog 3 – Student Structs)
// Due Date (10/12/2021)
// I certify that this program is my own original work. I did not copy any part of this program from any other source. I further certify that I typed each and every line of code in this program

#include <iostream>
#include <stdio.h>
#include <iomanip>
#include "myDate.h"
#include <string.h>
#include <cstdlib>
#include <cstring>
using namespace std;

struct Student {

  char name[20];
  char grade;
  int id; // Must be in between 100-999

  myDate birthday;
  string home_town;
};

// Call functions for main to work!
void sortTown(Student *students[]);
void sortID(Student *students[]);
void sortGrade(Student *students[]);
void sortName(Student *students[]);
void sortBday(Student *students[]);

void studentClass(Student *students[]);

int main(){
  Student *students[10];
  studentClass(students);

  while (true){

    cout << setw(20) << left << "Name: ";
    cout << setw(13) << left << "Student ID: ";
    cout << setw(10) << left << "Grade: ";
    cout << setw(20) << left << "Birthday: ";
    cout << setw(10) << left << "Home Town: \n";

    for (int i = 0; i < 10; i++){
      cout << setw(20) << left << students[i]->name;
      cout << setw(13) << left << students[i]->id;
      cout << setw(10) << left << students[i]->grade;
      cout << setw(20) << left << students[i]->birthday.toString();
      cout << setw(10) << left << students[i]->home_town << endl;

    }

// Five things to keep track of:
// Name - In studentClass() under main.cpp - Done
// Student ID - under studentClass() - Done
// Grade - under studentClass()
// Birthday - Use MyDate.cpp from prog2 - Done
// Home Town - under homeTown()

    cout << "\n-----------------------------------------\n" 
        << "1) Display list sorted by Name\n"
        << "2) Display list sorted by Student ID\n"
        << "3) Display list sorted by Grade\n"
        << "4) Display list sorted by Birthday\n"
        << "5) Display list sorted by Home Town\n"
        << "6) Exit\n"
        << "\n-----------------------------------------\n"; 

    int i;
    cin >> i;
    switch (i){
      case 1:
        sortName(students);
        break;

      case 2:
        sortID(students);
        break;

      case 3:
        sortGrade(students);
        break;

      case 4:
        sortBday(students);
        break;

      case 5:
        sortTown(students);
        break;

      case 6:
        exit(0);
        break;

      default:
        cout << "Invalid Input";
        break;
    }
  }
  return 0;
}

void sortTown(Student *students[]){

  for (int i = 0; i < 10; i++){
    for (int j = 0; j < 10; j++){
      if (students[i]->home_town.compare(students[j]->home_town) < 0){

        Student *var = students[i];
        students[i] = students[j];
        students[j] = var;

      }
    }
  }
}
// Sort should be similar to sortTown!!!
void sortID(Student *students[]){

  for (int i = 0; i < 10; i++){
    for (int j = 0; j < 10; j++){
      if (students[i]->id < students[j]->id){

        Student *var = students[i];
        students[i] = students[j];
        students[j] = var;

      }
    }
  }
}

void sortGrade(Student *students[]){

  for (int i = 0; i < 10; i++){
    for (int j = 0; j < 10; j++){
      if (students[i]->grade < students[j]->grade){ 

        Student *var = students[i];
        students[i] = students[j];
        students[j] = var;

      }
    }
  }
}

void sortName(Student *students[]){

  for (int i = 0; i < 10; i++){
    for (int j = 0; j < 10; j++){
      if (strcmp(students[i]->name, students[j]->name) < 0){

        Student *var = students[i];
        students[i] = students[j];
        students[j] = var;

      }
    }
  }
}

void sortBday(Student *students[]){

  for (int i = 0; i < 10; i++){
    for (int j = 0; j < 10; j++){
      if (students[i]->birthday.daysBetween(students[j]->birthday) > 0){ //Fix error for bday!

        Student *var = students[i];
        students[i] = students[j];
        students[j] = var;

      }
    }
  }
}

void studentClass(Student *students[]){
  
  char grades[] = {'A','B','C','D','F'};

  string names[] = {"Jerry Seinfeld","Morgan Freeman","Jeffery Bezos","Danny Devito","Vladimir Putin","Gabe Newell","Tom Thumb","Fred Flintstone", "Sponge Bob", "Quentin Tarantino"}; //10 Names with 10 locations (towns)

  string towns[] = {"Los Angeles", "Bikini Bottem", "Bedrock","Smallville", "Tokyo","Candyland", "New York", "London", "Moscow","Paris"};

  for (int i=0; i<10; i++){

    students[i] = new Student;

    strcpy(students[i]->name, names[i].c_str());
    students[i]->id = rand() % 899 + 100; // ID Generator
    students[i]->grade = grades[rand()%5];

    students[i]->birthday = myDate(); // fix str error for toString()
    students[i]->birthday.random();

    students[i]->home_town = towns[i];
  }
}
