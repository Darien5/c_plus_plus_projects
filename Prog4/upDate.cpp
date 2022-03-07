#include "upDate.h"
#include <iostream>
#include "math.h"
using namespace std;


int upDate::count = 0;

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

    alpha = 68569 + JD;

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

int upDate::julian() { // Same as G2J but add var[x]
  int month, day, year;
  month = var[0];
  day = var[1];
  year = var[2];

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

upDate::upDate(){
  var = new int[3];

  var[0] = 5;
  var[1] = 11;
  var[2] = 1959;

  count++;
}

upDate::upDate(int M, int D, int Y){
  var = new int[3];

  var[0] = M;
  var[1] = D;
  var[2] = Y;

  int JD = Greg2Julian(M, D, Y);
  Julian2Greg(JD, M, D, Y);

  if (M == var[0] && D == var[1] && Y == var[2]){
    var[0] = M;
    var[1] = D;
    var[2] = Y;
  }
  else {
    var[0] = 5;
    var[1] = 11;
    var[2] = 1959;
  }
  count++;
}

void upDate::setDate(int M, int D, int Y){
  var = new int[3];

  var[0] = M;
  var[1] = D;
  var[2] = Y;
  // Same thing as upDate:upDate remove count++!
  int JD = Greg2Julian(M, D, Y);
  Julian2Greg(JD, M, D, Y);

  if (M == var[0] && D == var[1] && Y == var[2]){
    var[0] = M;
    var[1] = D;
    var[2] = Y;
  }
  else {
    var[0] = 5;
    var[1] = 11;
    var[2] = 1959;
  }
}

upDate::upDate(int x){ // Julian Constructor
  var = new int[3];
  Julian2Greg(x, var[0], var[1], var[2]);

  count++;
}

upDate::~upDate(){ //Deconstructor
  count--;
  delete []var;
}

upDate::upDate(const upDate &obj){
  var = new int[3];

  var[0] = obj.var[0];
  var[1] = obj.var[1];
  var[2] = obj.var[2];

  count++;
}

string upDate::getMonthName(){ // DONT CHANGE TO GETMONTH()
  string months[] = {"January","February","March","April","May","June","August","September","October","November","December"};

  return months[var[0]-1];
}

int upDate::GetDateCount(){
  return count;
}

int upDate::getMonth(){
  return var[0];
}

int upDate::getDay(){
  return var[1];
}

int upDate::getYear(){
  return var[2];
}

//Operators

upDate upDate::operator=(upDate D){
  var = new int[3];
  var[0] = D.var[0];
  var[1] = D.var[1];
  var[2] = D.var[2];

  return (*this);
}

// For the boolean the function should still be the same but with different operand conditions < > ==
bool upDate::operator<(upDate D){
  if (this->julian() < D.julian())
    return true;
  else
    return false;
}

bool upDate::operator>(upDate D){
  if (this->julian() > D.julian())
    return true;
  else
    return false;
}

bool upDate::operator==(upDate D){
  if (this->julian() == D.julian())
    return true;
  else
    return false;
}

ostream &operator<<(ostream& out, upDate D) {
  out << D.getMonth() << "/" << D.getDay() << "/" << D.getYear();
  return out;
}

// Addition Operators
upDate upDate::operator+=(int n){
  upDate temp(*this);

  int JD = Greg2Julian(temp.var[0], temp.var[1], temp.var[2]);
  JD += n;
  Julian2Greg(JD, var[0], var[1], var[2]);

  return temp;
}

upDate upDate::operator+(int n){
  upDate temp(*this);

  int JD = Greg2Julian(temp.var[0], temp.var[1], temp.var[2]);
  JD += n;
  Julian2Greg(JD, temp.var[0], temp.var[1], temp.var[2]); //REMEMBER TO ADD temp.

  return temp;
}

upDate operator+(int n, upDate D){
  return D + n;
}

upDate upDate::operator++(){
  upDate temp(*this);

  int JD = Greg2Julian(temp.var[0], temp.var[1], temp.var[2]);
  JD += 1;
  Julian2Greg(JD, temp.var[0], temp.var[1], temp.var[2]);

  return temp;
}

upDate upDate::operator++(int n){
  upDate temp(*this);

  int JD = Greg2Julian(temp.var[0], temp.var[1], temp.var[2]);
  ++JD;
  Julian2Greg(JD, var[0], var[1], var[2]); // Remove temp. for ++ and --

  return temp;
}

//Subtraction operators

upDate upDate::operator-=(int n){
  upDate temp(*this);

  int JD = Greg2Julian(temp.var[0], temp.var[1], temp.var[2]);
  JD -= n;
  Julian2Greg(JD, var[0], var[1], var[2]);

  return temp;
}

upDate upDate::operator-(int n){
  upDate temp(*this);

  int JD = Greg2Julian(temp.var[0], temp.var[1], temp.var[2]);
  JD -= n;
  Julian2Greg(JD, temp.var[0], temp.var[1], temp.var[2]);

  return temp;
}

upDate operator-(int n, upDate D){
  return D - n;
}

int upDate::operator-(upDate D){
  int JD1 = Greg2Julian(var[0], var[1], var[2]);
  int JD2 = Greg2Julian(D.var[0], D.var[1], D.var[2]);

  int result = JD1 + JD2;
  return result;
}

upDate upDate::operator--(){
  upDate temp(*this);

  int JD = Greg2Julian(temp.var[0], temp.var[1], temp.var[2]);
  JD -= 1;
  Julian2Greg(JD, temp.var[0], temp.var[1], temp.var[2]);

  return temp;
}

upDate upDate::operator--(int n){
  upDate temp(*this);
  --*this;
  return temp;
}

