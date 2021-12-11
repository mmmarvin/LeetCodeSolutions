/**
 * Possible solution to https://leetcode.com/problems/find-all-duplicates-in-an-array
 * Marvin Manese
 **/

class Solution
{
public:
    vector<int> findDuplicates(vector<int>& nums)
    {
        vector<int> ret;

        for(int num : nums) {
            int abs_num = abs_helper(num);
            int n_index = abs_num - 1;
            if(nums[n_index] < 0) {
                ret.push_back(abs_num);
                continue;
            }
            nums[n_index] *= -1;
        }

        return ret;
    }

private:
    int abs_helper(int num)
    {
        return num < 0 ? (num * -1) : num;
    }
};
