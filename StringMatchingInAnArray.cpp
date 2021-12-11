/**
 * Solution to https://leetcode.com/contest/weekly-contest-184/problems/string-matching-in-an-array/
 **/
class Solution {
public:
    bool isSubstr(const string& str, const string& substr)
    {
        for(size_t i = 0; i < str.size(); ++i) {
            auto c = str[i];
            
            if(c == substr.front()) {
                if(str.size() - i >= substr.size()) {
                    if(substr == str.substr(i, substr.size()))
                        return true;
                }
            }
        }
        
        return false;
    }
    
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ret;
        set<string> ret_set;
        for(size_t i = 0; i < words.size(); ++i) {
            auto str = words[i];
            for(size_t j = i + 1; j < words.size(); ++j) {
                auto substr = words[j];
                if(isSubstr(str, substr)) {
                    if(ret_set.find(substr) == ret_set.end()) {
                        ret_set.emplace(substr);
                        ret.push_back(substr);
                    }
                } else if(isSubstr(substr, str)) {
                    if(ret_set.find(str) == ret_set.end()) {
                        ret_set.emplace(str);
                        ret.push_back(str);
                    }
                }
            }
        }
        
        return ret;
    }
};
