/**
 * Solution to https://leetcode.com/problems/find-lucky-integer-in-an-array/
 **/
class Solution {
public:
    int findLucky(vector<int>& arr) 
    {
        unordered_map<int, int> m;
        
        for(auto n : arr) {
            if(m.find(n) == m.end())
                m[n] = 1;
            else
                ++m[n];
        }
        
        int largest = -1;
        for(auto [n, count] : m) {
            if(n == count)
                if(n > largest)
                    largest = n;
        }
        
        return largest;
    }
};
