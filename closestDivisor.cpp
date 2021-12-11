#include <iostream>
#include <cmath>
#include <cstdio>
#include <limits>
#include <vector>
using namespace std;

pair<vector<int>, int> closest(int num)
{
  int diff = std::numeric_limits<int>::max();
  vector<int> divisors;
  divisors.resize(2);

  for(int i = 1, iend = sqrt(num); i <= iend; ++i) {
    if(num % i == 0) {
      auto d1 = num / i;
      auto d2 = i;
      auto d = abs(d2 - d1);
      if(d < diff) {
        diff = d;
        divisors[0] = d1;
        divisors[1] = d2;
      }
    }
  }

  return make_pair(divisors, diff);
}

vector<int> closestDivisors(int num) 
{
  auto n1 = num + 1;
  auto n2 = num + 2;

  auto r1 = closest(n1);
  auto r2 = closest(n2);

  if(r1.second < r2.second)
    return r1.first;

  return r2.first;
}

int main()
{
  auto r = closestDivisors(123);
  for(auto n : r) 
    cout << n << endl;
}