/**
 * Solution to https://leetcode.com/problems/four-divisors/
 **/

class Solution {
public:
    vector<int> getDivisors(int n)
    {
        vector<int> ret;
        for(int i = 1, isize = sqrt(n); i <= isize; ++i) {
            if(n % i == 0) {
                if(n / i == i) {
                    ret.push_back(i);
                } else {
                    ret.push_back(n / i);
                    ret.push_back(i);
                }
            }
        }
        
        return ret;
    }
    
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        
        for(auto n : nums) {
            auto d = getDivisors(n);
            if(d.size() == 4) {
                auto s = accumulate(d.begin(), d.end(), 0);
                sum += s;
            }
        }
        
        return sum;
    }
};
