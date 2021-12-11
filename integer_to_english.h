/**
 * Possible solution to: https://leetcode.com/problems/integer-to-english-words/description/
 * Marvin Manese
 **/

#ifndef GUARD_solution_H
#define GUARD_solution_H

#include <string>
#include <vector>

const std::string PLACE_VALUE[] =
{
    "",
    "Thousand",
    "Million",
    "Billion"
};

const std::string NUM[][10] =
{
{
    "",
    "One",
    "Two",
    "Three",
    "Four",
    "Five",
    "Six",
    "Seven",
    "Eight",
    "Nine"
},
{
    "",
    "",
    "Twenty",
    "Thirty",
    "Forty",
    "Fifty",
    "Sixty",
    "Seventy",
    "Eighty",
    "Ninety"
}
};

const std::string NUM2[] =
{
    "Ten",
    "Eleven",
    "Twelve",
    "Thirteen",
    "Fourteen",
    "Fifteen",
    "Sixteen",
    "Seventeen",
    "Eighteen",
    "Nineteen"
};

template<class T>
T fast_positive_modulo(T input, T ceil)
{
    return input >= ceil ? input % ceil : input;
}

class Solution
{
public:
    typedef std::vector<std::string> string_container;

    std::string numberToWords(int number)
    {
        std::string ret;

        if(number == 0)
            return "Zero";

        string_container temporary_container;
        temporary_container.reserve(100);

        int index = 0;
        while(number >= 1) {
            int digit = fast_positive_modulo(number, 1000);
            number /= 1000;

            if(digit > 0)
                temporary_container.push_back(PLACE_VALUE[index++]);
            else
                ++index;
            hunderdsToWords(digit, temporary_container);
        }

        for(string_container::reverse_iterator it = temporary_container.rbegin(), it_end = temporary_container.rend(); it != it_end; ++it) {
            if(*it != "") {
                ret += (*it) + " ";
            }
        }

        return ret.substr(0, ret.size() - 1);
    }

private:
    void hunderdsToWords(int number, string_container& temporary_container)
    {
        int tens_digit = fast_positive_modulo(number, 100);
        number /= 100;
        int hundreds_digit = fast_positive_modulo(number, 10);

        if(hundreds_digit > 0) {
            tenToWords(tens_digit, temporary_container);
            temporary_container.push_back("Hundred");
            temporary_container.push_back(NUM[0][hundreds_digit]);
        } else {
            tenToWords(tens_digit, temporary_container);
        }
    }

    void tenToWords(int number, string_container& temporary_container)
    {
        if(number >= 10 && number < 20) {
            int digit = fast_positive_modulo(number, 10);
            temporary_container.push_back(NUM2[digit]);
        } else {
            int index = 0;
            while(number >= 1) {
                int digit = fast_positive_modulo(number, 10);
                number /= 10;

                temporary_container.push_back(NUM[index++][digit]);
            }
        }
    }
};

#endif // GUARD_solution_H
