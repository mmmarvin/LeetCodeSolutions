/**
 * Solution to https://leetcode.com/problems/basic-calculator
 * Marvin Manese
 **/

#include <sstream>
#include <vector>
#include <string>

struct Equation
{
    Equation(int val, char sign) : left_hand_value(val), next_sign(sign) {}

    int left_hand_value;
    char next_sign;
};

class Solution
{
public:
    Solution() {}
    int calculate(const std::string& s)
    {
        std::string equation = s;
        std::vector<Equation> temporary_cache;
        temporary_cache.reserve(100);

        while(equation.size() > 0) {
            // Find the inner equation first
            size_type inner_left_bracket = find_inner_left_bracket(equation);
            size_type inner_right_bracket = find_inner_right_bracket(inner_left_bracket, equation);

            // If there are brackets, remove it
            if(inner_left_bracket != std::string::npos && inner_right_bracket != std::string::npos) {
                // Grab the inner equation
                std::string inner_equation = equation.substr(inner_left_bracket + 1, inner_right_bracket - 1 - inner_left_bracket);

                // Recurse
                int inner_equation_value = calculate(inner_equation);

                // Convert to string
                std::string inner_equation_value_str = to_string(inner_equation_value);

                // Subtract the inner equation from the whole equation
                equation.replace(inner_left_bracket, 1 + inner_right_bracket - inner_left_bracket, inner_equation_value_str);
            } else if(inner_left_bracket == std::string::npos && inner_right_bracket == std::string::npos) {
                // If no brackets, try to solve
                size_type first_pos_sign = equation.find_first_of('+');
                size_type first_neg_sign = equation.find_first_of('-');

                // If we find the first sign cut the left hand side and
                if(first_pos_sign != std::string::npos && first_pos_sign < first_neg_sign) {
                    char sign_to_use = '+';

                    int left_hand_int = evaluate(equation, first_pos_sign, sign_to_use);
                    push_to_cache(left_hand_int, sign_to_use, temporary_cache);
                } else if(first_neg_sign != std::string::npos && first_neg_sign < first_pos_sign) {
                    char sign_to_use = '-';

                    int left_hand_int = evaluate(equation, first_neg_sign, sign_to_use);
                    push_to_cache(left_hand_int, sign_to_use, temporary_cache);
                } else if(first_pos_sign == std::string::npos && first_neg_sign == std::string::npos) {
                    // If no sign is found, it must be a number
                    int left_hand_int = to_int(equation);
                    push_to_cache(left_hand_int, '+', temporary_cache);

                    // Clear the equation
                    equation.clear();
                }
            }
        }

        // Add all the ones in the temporary cache
        int sum = 0;
        char next_sign = '+';
        for(std::vector<Equation>::iterator it = temporary_cache.begin(), it_end = temporary_cache.end(); it != it_end; ++it) {
            int value = (*it).left_hand_value;
            sum = (next_sign == '+') ? sum + value : sum - value;
            next_sign = (*it).next_sign;
        }

        return sum;
    }

private:
    typedef std::string::size_type size_type;

    size_type find_inner_left_bracket(const std::string& equation)
    {
        // This finds the last bracket of the equation
        return equation.find_last_of('(');
    }

    size_type find_inner_right_bracket(size_type left_bracket_postion, const std::string& equation)
    {
        // This finds the first bracket of the equation that is > left bracket position
        for(size_type i = 0, i_end = equation.size(); i < i_end; ++i) {
            if(equation[i] == ')' && i > left_bracket_postion)
                return i;
        }

        return std::string::npos;
    }

    int find_other_sign(size_type prev_pos, const std::string& equation, char& sign_to_use)
    {
        for(std::string::size_type i = 0, i_size = equation.size(); i < i_size; ++i) {
            char c = equation[i];
            if((c == '+' || c == '-') && i != prev_pos) {
                sign_to_use = c;
                return static_cast<int>(i);
            }
        }

        return -1;
    }

    int evaluate(std::string& equation, std::string::size_type sign_pos, char& sign_to_use)
    {
        // Grab the left hand, and remove it from the equation
        std::string left_hand = equation.substr(0, sign_pos);

        if(left_hand == " " || left_hand == "") {
            int next_sign_pos_i = find_other_sign(sign_pos, equation, sign_to_use);
            if(next_sign_pos_i != -1) {
                size_type next_sign_pos = static_cast<size_type>(next_sign_pos_i);

                left_hand = equation.substr(0, next_sign_pos);
                equation.erase(0, next_sign_pos + 1);
            } else {
                left_hand = equation;
                equation.clear();
            }
        } else {
            equation.erase(0, sign_pos + 1);
        }

        // Convert the left hand to integer
        return to_int(left_hand);
    }

    void push_to_cache(int value, char sign, std::vector<Equation>& temporary_cache)
    {
        temporary_cache.emplace_back(value, sign);
    }

    std::string to_string(int n)
    {
        std::stringstream ss;
        ss << n;
        return ss.str();
    }

    int to_int(const std::string& str)
    {
        int ret = std::atoi(str.c_str());
        return ret;
    }
};
