/**
 * Possible solution to https://leetcode.com/problems/rotate-array/
 * Marvin Manese
 **/

template<class T>
T fast_positive_modulo(T input, T ceil)
{
    return input >= ceil ? input % ceil : input;
}

class Solution
{
public:
    void rotate(vector<int>& nums, int k)
    {
        if(nums.size() == 0 || k == 0)
            return;

        // Copy the nums
        std::vector<int> copy_nums = nums;

        // First modulo the k to the size of the nums
        // This gives how many rotations there is without
        // doing a full rotation
        int final_k = fast_positive_modulo(k, static_cast<int>(nums.size()));

        nums.clear();
        // Now grab the last item on the array
        for(int i = copy_nums.size() - final_k; i < copy_nums.size(); ++i) {
            nums.push_back(copy_nums[i]);
        }

        // Now grab the other items
        for(int i = 0, i_end = copy_nums.size() - final_k; i < i_end; ++i)
            nums.push_back(copy_nums[i]);
    }
};
