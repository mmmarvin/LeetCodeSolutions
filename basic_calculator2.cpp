#include <iostream>

#include <stack>
#include <string>
#include <queue>

class Solution
{
public:
    int calculate(const std::string& s)
    {
        std::vector<int> numbers;
        std::vector<char> operations;

        bool mul_or_div = false;
        char mul_or_div_sign = ' ';
        int num = 0;
        for(std::string::const_iterator it = s.begin(), it_end = s.end(); it != it_end; ++it) {
            char n = *it;
            if(isdigit(n)) {
                num = (num * 10) + (n - '0');
            } else {
                if(!isspace(n)) {
                    if(mul_or_div) {
                        int left_hand = numbers.back();
                        numbers.pop_back();
                        int right_hand = num;
                        num = 0;

                        int result = 0;
                        switch(mul_or_div_sign) {
                        case '*':
                            result += (left_hand * right_hand);
                            break;
                        case '/':
                            result += (left_hand / right_hand);
                            break;
                        default:
                            break;
                        }
                        numbers.push_back(result);
                        mul_or_div = false;
                    } else {
                        numbers.push_back(num);
                        num = 0;
                    }

                    if(n == '+' || n == '-')
                        operations.push_back(n);
                    else if(n == '*' || n == '/') {
                        mul_or_div = true;
                        mul_or_div_sign = n;
                    }
                }
            }
        }

        if(mul_or_div) {
            int left_hand = numbers.back();
            numbers.pop_back();
            int right_hand = num;
            num = 0;

            int result = 0;
            switch(mul_or_div_sign) {
            case '*':
                result += (left_hand * right_hand);
                break;
            case '/':
                result += (left_hand / right_hand);
                break;
            default:
                break;
            }
            numbers.push_back(result);
            mul_or_div = false;
        } else {
            numbers.push_back(num);
            num = 0;
        }

        // Now do the add or subtract
        int rst = 0;

        if(numbers.size() == 1)
            rst += numbers[0];
        else {
            // Grab the first number
            int n = numbers[0];
            rst += n;

            for(int i = 1, j = 0; i < numbers.size(); ++i, ++j) {
                int left_hand = numbers[i];
                char ops = operations[j];

                switch(ops) {
                case '+':
                    rst += left_hand;
                    break;
                default:
                    rst -= left_hand;
                    break;
                }
            }
        }

        return rst;
    }
};

int main()
{
    Solution sol;
    std::cout << sol.calculate("1+1-1+1") << std::endl;
}
