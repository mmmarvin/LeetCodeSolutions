/**
 * 3ms Solution to https://leetcode.com/problems/reverse-bits
 * Marvin Manese
 **/

#include <algorithm>
#include <bitset>

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        std::bitset<32> num_bits(n);

        // Swap the bits
        for(std::size_t i = 0, j = num_bits.size() - 1; i<= j; ++i, --j) {
            char bit_i = num_bits[i];
            num_bits[i] = num_bits[j];
            num_bits[j] = bit_i;
        }

        return num_bits.to_ulong();
    }
};
