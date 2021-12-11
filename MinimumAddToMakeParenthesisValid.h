/**
 * Solution to https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
 * Faster than 100%, Uses less memory than 100% 
 **/
class Solution {
public:
    int minAddToMakeValid(string S) 
    {
        stack<char> parenthesis;
        int extraCount = 0;
        
        for(auto c : S) {
            if(c == '(')
                parenthesis.push(c);
            else if(c == ')')
                if(parenthesis.empty())
                    ++extraCount;
                else
                    parenthesis.pop();
        }
        
        return extraCount + parenthesis.size();
    }
};
