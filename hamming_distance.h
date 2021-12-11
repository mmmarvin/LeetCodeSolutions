/**
 * Solution to https://leetcode.com/problems/hamming-distance/
 * Faster than 100%, uses less memory than 100%
 * Marvin Manese
 **/
#include <bitset>

class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        // Convert to binary string
        std::string binary_x = std::bitset<32>(x).to_string();
        std::string binary_y = std::bitset<32>(y).to_string();

        // Count the difference
        int diff = 0;
        for(std::string::size_type i = 0, i_size = binary_x.size(); i < i_size; ++i) {
            if(binary_x[i] != binary_y[i])
                ++diff;
        }

        return diff;
    }
};
