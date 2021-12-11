/**
 * 6ms Solution to https://leetcode.com/problems/add-strings/
 * Marvin Manese
 **/
#include <string>

static const char NUMBER_ZERO = '0';
static const char NUMBER_NINE = '9';

class Solution {
public:
    std::string addStrings(const std::string& num1, const std::string& num2)
    {
        std::string output;
        char carry = 0;

        std::string::const_reverse_iterator it = num1.rbegin();
        std::string::const_reverse_iterator it2 = num2.rbegin();
        std::string::const_reverse_iterator it_end = num1.rend();
        std::string::const_reverse_iterator it2_end = num2.rend();
        for(; it != it_end || it2 != it2_end; it = it != it_end ? ++it : it, it2 = it2 != it2_end ? ++it2 : it2) {
            // Get the "numbers". If the iterator is at it end, get a '0'
            char n1 = it != it_end ? (*it): '0';
            char n2 = it2 != it2_end ? (*it2) : '0';

            // Add the "numbers" and push it to the output string
            output.push_back(addNumbers(n1, n2, carry));
        }

        if(carry > 0) {
            output.push_back('0' + carry);
        }

        // Reverse the output string
        std::reverse(output.begin(), output.end());
        return output;
    }

private:
    char addNumbers(char n1, char n2, char& carry)
    {
        // First, grab the "real" value of n1 and n2, in terms
        // of the 0-9 value by subtracting n1 and n2 from the encoding value
        // of '0'. This will give us a range from 0-9
        char real_n1 = n1 - NUMBER_ZERO;
        char real_n2 = n2 - NUMBER_ZERO;

        // Next add their values, along with the carry
        char sum = real_n1 + real_n2 + carry;

        // Add it back by the value of '0' to get the character representation
        // once again
        sum += NUMBER_ZERO;

        // Now, if the sum > '9', there is a carry
        if(sum > NUMBER_NINE) {
            // So we carry 1, and adjust the sum
            carry = 1;
            sum = sum - NUMBER_NINE + NUMBER_ZERO - 1;
        } else {
            // If sum < '9', we reset the carry
            carry = 0;
        }
        return sum;
    }
};
