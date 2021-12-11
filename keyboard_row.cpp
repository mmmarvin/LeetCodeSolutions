#include <iostream>

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

const std::unordered_set<char> ROW[3] =
{
    { 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P' },
    { 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L' },
    { 'Z', 'X', 'C', 'V', 'B', 'N', 'M' }
};

const std::unordered_map<char, int> LETTER_ROW =
{
    {'Q', 0}, {'W', 0}, {'E', 0}, {'R', 0}, {'T', 0}, {'Y', 0}, {'U', 0}, {'I', 0}, {'O', 0}, {'P', 0},
    {'A', 1}, {'S', 1}, {'D', 1}, {'F', 1}, {'G', 1}, {'H', 1}, {'J', 1}, {'K', 1}, {'L', 1},
    {'Z', 2}, {'X', 2}, {'C', 2}, {'V', 2}, {'B', 2}, {'N', 2}, {'M', 2}
};

class Solution
{
public:
    std::vector<std::string> findWords(const std::vector<std::string>& words)
    {
        std::vector<std::string> ret;

        for(std::vector<std::string>::const_iterator it = words.begin(), it_end = words.end(); it != it_end; ++it) {
            const std::string& word = *it;

            // Grab the word's first letter to determine which row to use
            char letter = toupper(word[0]);
            if(isalpha(letter)) {
                int row = LETTER_ROW.at(letter);

                bool same_row = true;
                for(std::string::size_type i = 1, i_size = word.size(); i < i_size && same_row; ++i) {
                    char other_letters = toupper(word[i]);
                    std::unordered_set<char>::const_iterator find_it = ROW[row].find(other_letters);

                    // If the letter is in the row
                    if(find_it == ROW[row].end()) {
                        same_row = false;
                    }
                }

                if(same_row) {
                    ret.push_back(word);
                }
            }
        }

        return ret;
    }
};

#include "helpers/array_helpers.h"

int main()
{
    Solution sol;
    std::vector<std::string> words = sol.findWords({"Hello", "Alaska", "Dad", "Peace"});
    print_array(words);

    return 0;
}
