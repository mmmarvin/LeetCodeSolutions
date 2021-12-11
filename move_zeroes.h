/**
 * Possible solution to https://leetcode.com/problems/move-zeroes/
 * Faster than 91% uses less memory than 100%
 * Marvin Manese
 **/

#include <algorithm>
#include <vector>

class Solution
{
public:
    void moveZeroes(std::vector<int>& nums)
    {
        typedef std::vector<int>::size_type size_type;

        size_type i = 0;    // Non-zero indexer
        size_type j = 0;    // Zero indexer

        // Grab the size
        size_type size = nums.size();

        // Find the first zero
        while(i < size && nums[i] != 0)
            ++i;
        j = i;

        // Find the non-zeroes and swap it back to the first zero found
        for(size_type j = i; j < size; ++j) {
            if(nums[j] == 0)
                continue;

            std::swap(nums[i], nums[j]);
            ++i;
        }
    }
};
