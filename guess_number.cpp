#include <iostream>

using namespace std;

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
const int ans = 1702766719;
int guess(int num)
{
    return num > ans ? 1 : num < ans ? -1 : 0;
}

class Solution {
public:
    int guessNumber(int n)
    {
        int lo = 0;
        int hi = n;
        int mi = (hi + lo) / 2;

        int g = guess(mi);
        while(g != 0) {
            if(g == -1) {
                hi = mi - 1;
            } else if(g == 1) {
                lo = mi + 1;
            }

            mi = (hi + lo) / 2;
            g = guess(mi);
            cout << mi << endl;
        }

        return mi;
    }
};

int main()
{
    Solution sol;
    cout << sol.guessNumber(2126753390) << endl;
}
