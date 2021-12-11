/**
 * 6ms solution to https://leetcode.com/problems/single-element-in-a-sorted-array/
 * Marvin Manese
 **/
#include<vector>

template<class T>
T fast_positive_modulo(T input, T ceil)
{
    return input >= ceil ? input % ceil : input;
}

class Solution
{
public:
    int singleNonDuplicate(const std::vector<int>& nums)
    {
        typedef std::vector<int>::size_type size_type;

        // Grab the size of the array
        size_type size = nums.size();

        // The binary search indexes
        size_type first = 0;
        size_type last = size;
        size_type half = first + ((last - first) / 2);

        int element = nums[half];
        do {
            if(half == 0 || half >= size)
                break;

            // First determine if the half is odd or even
            int is_odd = fast_positive_modulo(static_cast<int>(half), 2);
            if(is_odd > 0) {
                // If it is odd, and
                // If the element == the array's next element, then we know that
                // the element we are looking for is in the first half
                if(element == nums[half + 1]) {
                    last = half;
                    half = first + ((last - first) / 2);
                    continue;
                }

                // If the element == the array's previous element, then we know that
                // the element we are looking for is in the second half
                if(element == nums[half - 1]) {
                    first = half;
                    half = first + ((last - first) / 2);
                    continue;
                }

                // If we reached this point, we know that this is the element we are looking for
                break;
            } else {
                // If it is even, and
                // If the element == the array's next element, then we know that
                // the element we are looking for is in the second half
                if(element == nums[half + 1]) {
                    first = half;
                    half = first + ((last - first) / 2);
                    continue;
                }

                // If the element == the array's previous element, then we know that
                // the element we are looking for is in the first half
                if(element == nums[half - 1]) {
                    last = half;
                    half = first + ((last - first) / 2);
                    continue;
                }

                // If we reached this point, we know that this is the element we are looking for
                break;
            }
        } while(element = nums[half], true);

        return element;
    }
};
