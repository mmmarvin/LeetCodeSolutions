/**
 * Solution to https://leetcode.com/problems/find-the-difference/submissions/
 */
#include <unordered_map>
#include <string>

class Solution
{
public:
    char findTheDifference(const std::string& s, const std::string& t)
    {
        std::unordered_map<char, int> letter_map;
        for(std::string::const_iterator it = s.begin(), it_end = s.end(); it != it_end; ++it) {
            char letter = *it;
            letter_map[letter] += 1;
        }

        for(std::string::const_iterator it = t.begin(), it_end = t.end(); it != it_end; ++it) {
            char letter = *it;
            std::unordered_map<char, int>::iterator find_it = letter_map.find(letter);
            if(find_it == letter_map.end())
                return letter;

            (*find_it).second += 1;
        }

        for(std::unordered_map<char, int>::iterator it = letter_map.begin(), it_end = letter_map.end(); it != it_end; ++it) {
            if((*it).second % 2 != 0)
                return (*it).first;
        }
        return ' ';
    }
};

int main()
{

}
