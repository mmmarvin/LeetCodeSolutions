#include <array>
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool validateBinaryTreeNodes(int n, const vector<int>& leftChild, const vector<int>& rightChild) 
{
  unordered_set<int> ln;
  unordered_set<int> rn;

  auto li = size_t(0);
  auto ri = size_t(0);

  int lr = 0;
  int ll = 0;

  bool done = false;
  while(!done && li < leftChild.size() && ri < rightChild.size()) {
    while(!done && li < leftChild.size()) {
      if(rn.find(leftChild[li]) != rn.end()) {
        return false;
      }
      else {
        if(leftChild[li] == -1) {
          if(lr == -2 && ll == -1)
            return false;
          if(lr == -1) {
            lr = -2;
            break;
          }

          lr = -1;
          break;
        }

        ln.emplace(leftChild[li]);
        lr = 0;
        ll = 0;
        ++li;
      }
    }

    while(!done && ri < rightChild.size()) {
      if(ln.find(rightChild[ri]) != ln.end()) {
        return false;
      }
      else {
        if(rightChild[ri] == -1) {
          if(ll == -2 && lr == -1)
            return false;
          if(ll == -1) {
            ll = -2;
            break;
          }
          
          ll = -1;
          break;
        }

        rn.emplace(rightChild[li]);
        lr = 0;
        ll = 0;
        ++ri;
      }
    }
  }

  return true;
}

int main()
{
  cout << validateBinaryTreeNodes(4, {1, -1, 3, -1}, {2, -1, -1, -1}) << endl;
}