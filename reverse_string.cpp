#include <iostream>
#include <vector>
#include <string>

//class Solution
//{
//public:
//    /// Cases to check for
//    /// Empty string
//    /// One word /
//    /// Leading whitespaces /
//    void reverseWords(std::string &s)
//    {
//        std::string::size_type size = s.size();
//
//        if(size == 0)
//            return;
//
//        int forward_i = 0;
//        int forward_j = forward_i;
//        int reverse_i = static_cast<int>(size) - 1;
//        int reverse_j = reverse_i;
//
//        while(forward_j <= reverse_j) {
//            // Get left word
//            while(forward_i < size && s[forward_i] == ' ' && forward_i <= reverse_j)
//                ++forward_i;
//            forward_j = forward_i;
//            while(forward_j < size && s[forward_j] != ' ' && forward_j <= reverse_j)
//                ++forward_j;
//
//            // First word is from range:
//            // forward_i -> forward_j
//
//            // Get right word
//            while(reverse_i > 0 && s[reverse_i] == ' ' && reverse_i >= forward_j)
//                --reverse_i;
//            reverse_j = reverse_i;
//            while(reverse_j > 0 && s[reverse_j] != ' ' && reverse_j >= forward_j)
//                --reverse_j;
//
//            // Left word is from range
//            // reverse_i -> reverse_j
//
//            if(forward_j <= reverse_j) {
//                // Calculate the length of the forward word
//                int length_of_forward_word = forward_j - forward_i;
//                int length_of_reverse_word = reverse_i - reverse_j;
//
//                // Get the words
//                std::string forward_word = s.substr(forward_i, length_of_forward_word);
//                std::string reverse_word = s.substr(reverse_j + 1, length_of_reverse_word);
//
//                // Replace the forward word to the last of the string
//                s.replace(forward_i, length_of_forward_word, reverse_word);
//
//                // Since the size of the first word has changed, we have to adjust the position of
//                // the indexes. We do that by calculating the difference between the old length and the
//                // new length of the words, and add it to the indexes
//                int difference_in_length = length_of_reverse_word - length_of_forward_word;
//
//                // Adjust the indexes
//                forward_j += difference_in_length;
//                reverse_j += difference_in_length;
//
//                // Replace
//                s.replace(reverse_j + 1, length_of_reverse_word, forward_word);
//
//                // Set j = i
//                forward_i = forward_j;
//                reverse_i = reverse_j;
//            }
//        }
//    }
//};

class Solution
{
public:
    void reverseWords(std::string &s)
    {
        std::vector<std::string> word_list;

        std::string::size_type i = 0;
        std::string::size_type j = 0;
        std::string::size_type size = s.size();

        while(i < size) {
            while(i < size && s[i] == ' ')
                ++i;
            j = i;
            while(j < size && s[j] != ' ')
                ++j;

            if(i != j) {
                word_list.push_back(s.substr(i, j - i));
                i = j;
            }
        }

        s = "";
        if(word_list.size() > 0) {
            for(std::vector<std::string>::reverse_iterator it = word_list.rbegin(), it_end = word_list.rend(); it != it_end; ++it) {
                s += (*it) + " ";
            }
            s.pop_back();
        }
    }
};

int main()
{
    Solution reverse_word;

    std::string darkeness = " Hello    Darkness  My    Old Friend";
    reverse_word.reverseWords(darkeness);

    std::cout << "Word reversed:\"" << darkeness << "\"" << std::endl;
    return 0;
}
