/**
 * Possible solution to https://leetcode.com/problems/valid-palindrome
 * Marvin Manese
 **/

#include <string>

class Solution
{
public:
    bool isPalindrome(const std::string& s)
    {
        typedef std::string::size_type size_type;

        // Grab the size
        size_type size = s.size();
        int i_size = static_cast<int>(size);

        // If the string is empty or there is only 1 character, it is a valid palindrome
        if(size <= 1)
            return true;

        // Traverse the element on both sides
        int i = 0;
        int j = i_size - 1;
        while(i <= j) {
            // Get the letter on the left, and it's partner on the right
            char letter_i = tolower(s[static_cast<size_type>(i)]);
            char letter_j = tolower(s[static_cast<size_type>(j)]);

            // While the letter is a space, or is not alpha, or is not a digit, we increment the index
            // and get the next letter
            while(i < i_size && i <= j && (letter_i == ' ' || !isalpha(letter_i)) && !isdigit(letter_i)) {
                ++i;
                letter_i = tolower(s[static_cast<size_type>(i)]);
            }
            // Do the same for the right side letter
            while(j >= 0 && i <= j && (letter_j == ' ' || !isalpha(letter_j)) && !isdigit(letter_j)) {
                --j;
                letter_j = tolower(s[static_cast<size_type>(j)]);
            }

            // Now, we check if the letters match, or if the indexes passed each other. If the indexes passed
            // each other, we know that the indexer could not find any letters, and is therefore considered
            // a palindrome. If the indexers have not passed each other, then we check if the letters match.
            // If they do not match, not a palindrome therefore return false
            if(i <= j && letter_i != letter_j)
                return false;

            ++i;
            --j;
        }

        // If we have reached this point, we know that it is a palindrome
        return true;
    }
};
