/**
 * Solution to https://leetcode.com/contest/weekly-contest-184/problems/queries-on-a-permutation-with-key/
 **/ 
class Solution {
public:
    void swap_to_first(vector<int>& mc, int i)
    {
        while(i > 0) {
            swap(mc[i], mc[i - 1]);
            --i;
        }
    }
    
    int find(const vector<int>& mc, int n)
    {
        for(size_t i = 0; i < mc.size(); ++i) {
            if(mc[i] == n)
                return i;
        }
        
        return 0;
    }
    
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> mc;
        for(int i = 1; i <= m; ++i) {
            mc.push_back(i);
        }
        
        vector<int> ret;
        for(size_t i = 0; i < queries.size(); ++i) {
            auto in = find(mc, queries[i]);
            swap_to_first(mc, in);
            ret.push_back(in);
        }
        
        return ret;
    }
};
