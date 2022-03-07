#ifndef upDate_h
#define upDate_h
#include <string>
using namespace std;

class upDate {

public:
  upDate();
  upDate(int m, int d, int y);
  upDate(int x);
  upDate(const upDate &obj);
  ~upDate();

  void setDate(int M, int D, int Y);
  int julian();

  int getMonth();
  int getDay();
  int getYear();

  std::string getMonthName();
  upDate operator=(upDate D); // why is the = not colored
  upDate operator+=(int n);
  upDate operator-=(int n);

  upDate operator+(int n);
  friend upDate operator+(int n, upDate D); // use greg2julian() with temp. and j2g with temp.
// int operator+(upDate D);

  upDate operator-(int n);
  friend upDate operator-(int n, upDate D); // same as operator+ but with JD -= n;
  int operator-(upDate D);

  static int GetDateCount();
  friend ostream& operator <<(ostream &out, upDate D);

  upDate operator++(); // no temp. for j2g but ++JD;
  upDate operator++(int n);

  upDate operator--();
  upDate operator--(int n); // is --JD; possible?

  bool operator<(upDate D);
  bool operator>(upDate D);
  bool operator==(upDate D);

private:
  static int count;
  int *var; 
};
#endif