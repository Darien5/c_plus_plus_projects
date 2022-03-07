#ifndef MyDate_h
#define MyDate_h
#include <string>
using namespace std;

class myDate{
public:
  myDate();
  myDate(int month, int day, int year);

  void display();
  void random();

  string toString();

  void increaseDate(int);
  void decreaseDate(int);

  int daysBetween(myDate);

  int getMonth();
  int getDay();
  int getYear();
  
  int dayOfYear();
  int forBirthday(myDate); // Maybe replace this for dayName?

  string dayName();

private:
  int month, day, year;
  int JD; // Double check

};
#endif