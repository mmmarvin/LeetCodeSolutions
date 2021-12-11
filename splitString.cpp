#include <numeric>
#include <iostream>
#include <vector>
using namespace std;

vector<int> sumZero(int n) 
{
  vector<int> ret;
  ret.reserve(n);

  if(n % 2 == 0) {
    auto n2 = n / 2;
    auto floor = -n2;
    auto ceil = n2;

    for(auto i = floor; i <= ceil; ++i)
      if(i != 0)
        ret.push_back(i);
    
    return ret;
  }

  auto n2 = n / 2;
  auto floor = -n2;
  auto ceil = n2;
  for(auto i = floor; i <= ceil; ++i)
    if(i != 0)
      ret.push_back(i);
  ret.push_back(0);

  return ret;
}

int main()
{
  auto v = sumZero(100);
  cout << "Size: " << v.size() << endl;

  for(auto n : v)
    cout << n << ",";
  cout << endl;
  auto a = std::accumulate(v.begin(), v.end(), 0);
  cout << "Sum: " << a << endl;
  cout << endl;
}