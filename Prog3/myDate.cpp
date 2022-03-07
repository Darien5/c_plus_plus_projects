#include "myDate.h"
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <sstream>
#include <cstdlib>
using namespace std;

myDate::myDate(){
    month = 5;
    day = 11;
    year = 1959;
}

myDate::myDate(int M, int D, int Y){
    if ((M >0 && M <13) && (D > 0 && D < 32)){
        month = M;
        day = D;
        year = Y;
    }
    else{
      month = 5;
      day = 11;
      year = 1959;
    }
}
// Julian Calender ---> Gregorian
void Julian2Greg(int JD, int &month, int &day, int &year){
  // Separate the equations to make sure everything works... Big functions dont work
    int alpha; 
    int beta; 
    int delta; 
    int gamma; 
    int zeta; 
    int theta; 
    int tau; 

    alpha = JD + 68569;

    beta = alpha * 4;
    beta = beta / 146097;

    delta = alpha - (146097 * beta + 3)/ 4;

    gamma = 4000 * (delta + 1) / 1461001;
    zeta = delta - 1461 * gamma / 4 + 31;
    theta = 80*zeta / 2447;
    tau = theta / 11;

    year = tau + gamma + 100 * (beta - 49);
    month = theta + 2 - (12 * tau);
    day = zeta - 2447 * theta / 80;
}
// Gregorian Calender ---> Julian
int Greg2Julian(int month, int day, int year) {
    double xi = (month + 9)/12;
    int xi2 = xi; 

    double epsilon = 7*(xi2 + year)/4;
    int epsilon2 = epsilon; 

    double eta = (275 * month)/ 9;
    int eta2 = eta; 
      
    double half = 12/24;

    double doubleSin = 0.5 * sin(100 * year + month - 19002.5);
    double round_GJ = round(half + doubleSin); 
    int halfint = round_GJ;
      
    int JD = 367*year - epsilon2 + eta2 + day + 1721013.5 + halfint + 0.5;
    return JD;
}
int myDate::forBirthday(myDate){
  int JD = Greg2Julian(month, day, year);
  return JD;
}

string myDate::toString(){
  string months[12] = {"January","February","March","April","May","June","July","August","September","October","November","December"};

  stringstream buffer;
  buffer << months[month - 1] << " " << day << ", " << year;
  
  return buffer.str();
}
//getMonth,Day,Year
int myDate::getMonth(){
    return month;
}

int myDate::getDay(){
    return day;
}

int myDate::getYear(){
    return year;
}

int myDate::daysBetween(myDate D){
    int thisJD = Greg2Julian(month, day, year);
    int otherJD = Greg2Julian(D.getMonth(), D.getDay(), D.getYear());

    return otherJD - thisJD;
}

void myDate::increaseDate(int N){
    int JD = Greg2Julian(month, day, year);
    JD += N;

    Julian2Greg(JD, month,day,year);
}

void myDate::decreaseDate(int N){
    int JD = Greg2Julian(month, day, year);
    JD -= N;

    Julian2Greg(JD, month,day,year);
}

int myDate::dayOfYear(){
    int leap_year[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int noLeap_year[] = {0,31,29,31,30,31,30,31,31,30,31,30,31};

    int dayOfYear = 0;
      
    
    if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
    for (int x = 0; x < month; x++){
      // Edit and correct the accumulator for non leaps
    dayOfYear += noLeap_year[x];
}
else
    for(int x = 0; x<month;x++){
        dayOfYear += leap_year[x];
    }
    dayOfYear += day;
    return dayOfYear;
}

string myDate::dayName(){
    int JD = Greg2Julian(month, day, year);

    if(JD % 7 == 0)
        return "Monday";

    else if(JD % 7 == 1)
        return "Tuesday";

    else if(JD % 7 == 2)
        return "Wednesday";

    else if(JD % 7 == 3)
        return "Thursday";

    else if(JD % 7 == 4)
        return "Friday";

    else if(JD % 7 == 5)
        return "Saturday";

    else
        return "Sunday";
}

void myDate::random(){
  myDate start = myDate(1, 1, 2000);
  myDate end = myDate(12,31,2024);

  int JD = rand() % start.daysBetween(end) + start.forBirthday(start);
  Julian2Greg(JD, month, day, year);
}