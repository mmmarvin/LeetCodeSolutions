/**
 * Solution to https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
 **/
class Solution {
public:
    int countBits(int n) {
        int cnt = 0;
        while(n) {
            if(n & 0x1)
                ++cnt;
            
            n = n >> 1;
        }
        
        return cnt;
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        unordered_map<int, int> m;
        
        sort(arr.begin(), arr.end(), [&m, this](int a, int b) {
            int av = 0;
            int bv = 0;
            
            if(m.find(a) == m.end()) {
                m.emplace(a, countBits(a));
                av = m[a];
            } else
                av = m[a];
            
            if(m.find(b) == m.end()) {
                m.emplace(b, countBits(b));
                bv = m[b];
            } else
                bv = m[b];
            
            if(av != bv)
                return av < bv;
            
            return a < b;
        });
        
        return arr;
    }
};
