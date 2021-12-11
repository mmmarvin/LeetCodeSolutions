/**
 * Possible solution to https://leetcode.com/problems/reverse-string/
 * Marvin Manese
 **/

#include <string>

class Solution {
public:
    std::string reverseString(const std::string& s)
    {
        if(s.size() <= 1)
            return s;

        // Copy the string
        std::string copied_s = s;

        // Implement what std::reverse does, that is swap
        for(std::string::size_type i = 0, j = s.size() - 1; i <= j; ++i, --j) {
            std::swap(copied_s[i], copied_s[j]);
        }

        return copied_s;
    }
};
