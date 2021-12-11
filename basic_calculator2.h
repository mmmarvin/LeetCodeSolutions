/**
 * Solution to https://leetcode.com/problems/basic-calculator-ii
 * Marvin Manese
 **/

#include <algorithm>
#include <string>

class Solution
{
public:
    int calculate(const std::string& s)
    {
        std::vector<int> numbers;
        std::vector<char> operations;

        // Grab the numbers
        grabNumbers(s, numbers, operations);

        // Now do the add or subtract for the numbers in the vector
        int rst = 0;

        // If there is only 1 element to the vector, just return it
        if(numbers.size() == 1)
            return numbers[0];
        else {
            // If there is more, we will operate it one by one.
            // First grab the first number
            int n = numbers[0];
            rst = n;

            // And do the necessary operation with the other numbers in the array
            // We can assume that operations.size() == numbers.size() - 1
            for(int i = 1, j = 0; i < numbers.size(); ++i, ++j) {
                int left_hand = numbers[i];
                char ops = operations[j];

                switch(ops) {
                case '+': rst += left_hand; break;
                default: rst -= left_hand; break;
                }
            }
        }

        return rst;
    }

private:
    void grabNumbers(const std::string& s, std::vector<int>& numbers, std::vector<char>& operations)
    {
        bool mul_or_div = false;
        char mul_or_div_sign = ' ';
        int num = 0;

        // Traverse the string
        for(std::string::const_iterator it = s.begin(), it_end = s.end(); it != it_end; ++it) {
            char n = *it;

            // If the character is a digit, we add it to the num
            if(isdigit(n)) {
                num = (num * 10) + (n - '0');
            } else {
                // Else, if the character is not a digit, it could be
                // a sign, a space, or other characters we don't care.
                // If it is not a space, we grab the character
                if(!isspace(n)) {
                    // Check first if there was a previous multiplication sign set.
                    multiplyOrDivide(mul_or_div, mul_or_div_sign, numbers, num);

                    // Check what sign, and add it to the operations vector
                    if(n == '+' || n == '-')
                        operations.push_back(n);
                    else if(n == '*' || n == '/') {
                        // If the sign is * or /, we set the mul_or_div flag to tell the next operations
                        // that there will be a multiplication or divide operation
                        mul_or_div = true;
                        mul_or_div_sign = n;
                    }
                }
            }
        }
        // Check for the last number
        multiplyOrDivide(mul_or_div, mul_or_div_sign, numbers, num);
    }

    void multiplyOrDivide(bool& mul_or_div, char mul_or_div_sign, std::vector<int>& numbers, int& num)
    {
        // If the multiply or divide flag is set, we multiply / divide the last integer pushed to the vector
        // and the last num grabbed
        if(mul_or_div) {
            // Grab the left hand value, and the right hand value
            int left_hand = numbers.back(); numbers.pop_back();
            int right_hand = num;

            // Reset the num to 0
            num = 0;

            int result = 0;

            // Determine what the sign was (* or /, for multiply and divide respectively)
            // and do the necessary operations
            switch(mul_or_div_sign) {
            case '*': result += (left_hand * right_hand); break;
            default: result += (left_hand / right_hand); break;
            }

            // Push it back to the array, and reset the multiply or divide flag
            numbers.push_back(result);
            mul_or_div = false;
        } else {
            // If there are no multiply or divide flag set, just push the number read
            // to the vector, and reset num
            numbers.push_back(num);
            num = 0;
        }
    }
};
