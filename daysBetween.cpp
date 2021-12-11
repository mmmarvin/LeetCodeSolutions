#include <iostream>
#include <time.h>
#include <sstream>
using namespace std;

int convertToInt(string s)
{
  stringstream ss;
  ss.str(s);

  int ret;
  ss >> ret;
  return ret;
}

int daysBetweenDates(string date1, string date2) 
{
  auto* y1Begin = &date1[0];
  auto* m1Begin = &date1[5];
  auto* d1Begin = &date1[8];
  auto* y2Begin = &date2[0];
  auto* m2Begin = &date2[5];
  auto* d2Begin = &date2[8];

  auto y1 = convertToInt(string(y1Begin, y1Begin + 4)) - 1900;
  auto m1 = convertToInt(string(m1Begin, m1Begin + 2)) - 1;
  auto d1 = convertToInt(string(d1Begin, d1Begin + 2));
  auto y2 = convertToInt(string(y2Begin, y2Begin + 4)) - 1900;
  auto m2 = convertToInt(string(m2Begin, m2Begin + 2)) - 1;
  auto d2 = convertToInt(string(d2Begin, d2Begin + 2));

  cout << y1 << ' ' << y2 << endl;
  cout << m1 << ' ' << m2 << endl;
  cout << d1 << ' ' << d2 << endl;

  tm t1 = { 0 };
  t1.tm_year = y1;
  t1.tm_mon = m1;
  t1.tm_mday = d1;

  tm t2 = { 0 };
  t2.tm_year = y2;
  t2.tm_mon = m2;
  t2.tm_mday = d2;

  return abs(difftime(mktime(&t1), mktime(&t2))) / 60 / 60 / 24;
}

int main()
{
  cout << daysBetweenDates("1971-06-29", "2010-09-23") << endl;
}