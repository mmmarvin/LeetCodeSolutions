/**
 * Possible solution to https://leetcode.com/problems/array-partition-i
 * Marvin Manese
 **/

class Solution
{
public:
    int arrayPairSum(vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end());

        int sum = 0;
        for(int i = 0, i_size = nums.size() - 1; i < i_size; i += 2) {
            sum += min(nums[i], nums[i + 1]);
        }

        return sum;
    }
};
