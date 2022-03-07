#ifndef MYDATE_H
#define MYDATE_H
#include <iostream>
using namespace std;

class myDate {
  // remember its m/d/y
    int month;
    int day;
    int year;

    public:
    myDate();
    myDate(int, int, int); // double check str error for (int,int,int)

    void display();
    void decreaseDate(int);
    void increaseDate(int);

    int daysBetween(myDate D);
    int dayOfYear();

    int getMonth();
    int getDay();
    int getYear();

    string dayName();
};

#endif