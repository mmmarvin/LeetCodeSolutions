/**
 * Faster than 88.40%
 **/

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) 
    {
        vector<string> ret;
        unordered_map<char, char> mapper;
        unordered_set<char> mapper2;
        
        for(const auto word : words) {
            mapper.clear();
            mapper2.clear();
            
            size_t i = 0;
            size_t isize = pattern.size();
            for( ; i < isize; ++i) {
                auto p = pattern[i];
                auto w = word[i];
                
                if(auto it = mapper.find(p); it == mapper.end()) {
                    if(mapper2.find(w) == mapper2.end()) {
                        mapper.emplace(p, w);
                        mapper2.emplace(w);
                    } else
                        i = isize + 1;
                } else {
                    if(it->second != w)
                      i = isize + 1;
                }
            }
            
            if(i == isize)
               ret.push_back(word);
        }
        
        return ret;
    }
};