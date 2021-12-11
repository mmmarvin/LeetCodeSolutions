/**
 * 25 ms solution to https://leetcode.com/problems/longest-substring-without-repeating-characters
 * Marvin Manese
 **/

#include <unordered_map>
#include <string>

class Solution
{
private:
    struct LetterInformation
    {
        LetterInformation(std::size_t position_found) : positionFound(position_found), count(1) {}
        std::size_t positionFound;
        std::size_t count;
    };

    void checkLongestSoFar(std::string::size_type l_w_size, int& longest_word_so_far_size)
    {
        int l_w_size_int = static_cast<int>(l_w_size);
        if(l_w_size_int > longest_word_so_far_size)
            longest_word_so_far_size = l_w_size_int;
    }

public:
    int lengthOfLongestSubstring(std::string s)
    {
        typedef std::unordered_map<char, LetterInformation> LetterCatalogType;

        int longest_word_so_far_size = 0;

        std::string longest_word_so_far = "";
        LetterCatalogType letter_catalog;
        letter_catalog.reserve(100);

        std::string::size_type old_pos = 0;
        for(std::string::size_type i = 0, i_size = s.size(); i < i_size; ++i) {
            char letter = s[i];

            // Check if letter exists
            LetterCatalogType::iterator find_it = letter_catalog.find(letter);
            if(find_it != letter_catalog.end()) {
                // If letter exists, grab the letter information
                LetterInformation& letter_information = (*find_it).second;

                // Now if the letter count > 0, we have to delete the
                // letters from old_pos -> position from the longest_word_so_far
                if(letter_information.count > 0) {
                    // If letter exists, grab its position
                    std::string::size_type position = letter_information.positionFound + 1;

                    // Substr that position to this to get longest substr so far
                    std::string deleted_word = s.substr(old_pos, position - old_pos);
                    longest_word_so_far = s.substr(position, i - position + 1);
                    old_pos = position;
                    letter_information.positionFound = i;

                    // Check if there is a new longest word
                    checkLongestSoFar(longest_word_so_far.size(), longest_word_so_far_size);

                    // Subtract the letters in between
                    for(std::string::size_type j = 0, j_size = deleted_word.size(); j < j_size; ++j) {
                        char deleted_char = deleted_word[j];
                        letter_catalog.at(deleted_char).count = 0;
                    }

                    // Reset the count of the letter to 1
                    letter_information.count = 1;
                } else {
                    // If the count is == 0, it means the letter has been deleted
                    // so we increase it's count, and set the new position to i
                    letter_information.positionFound = i;
                    ++letter_information.count;

                    // Push to the longest_word_so_far string
                    longest_word_so_far.push_back(letter);

                    // Check if there is a new longest word
                    checkLongestSoFar(longest_word_so_far.size(), longest_word_so_far_size);
                }
            } else {
                // Create a letter information to our hash table
                letter_catalog.emplace(letter, LetterInformation(i));

                // Push to the longest_word_so_far string
                longest_word_so_far.push_back(letter);

                // Check if there is a new longest word
                checkLongestSoFar(longest_word_so_far.size(), longest_word_so_far_size);
            }
        }

        return longest_word_so_far_size;
    }
};
