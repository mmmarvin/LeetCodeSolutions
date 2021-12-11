#include <iostream>
#include <vector>

// OPTIMIZE

class Solution
{
public:
    // Complexity:
    // best case: O(1), worse case: O()
    int findMin(const std::vector<int>& nums)
    {
        // Grab the size
        int size = nums.size();
        int front_element = nums.front();
        int back_element = nums.back();

        // Check for cases where num.size() < 2;
        if(size <= 2 && size > 0) {
            return std::min(front_element, back_element);
        }

        // Check for a case where there is no rotation. We can do this by checking
        // if the back element > front element. If this is true, we know there is no
        // rptation, so we just return the front element
        if(back_element > front_element)
            return front_element;

        // Get the low, high middle indexers
        int low = 0;
        int high = size - 1;
        int middle = findMiddle(low, high);

        // Set the maximum
        int minimum = INT32_MAX;

        while(low <= high) {
            // Get the high and low elements
            int high_element = nums[high];
            int middle_element = nums[middle];
            int low_element = nums[low];

            // If there are only 3 elements left, we min the three elements
            if((high - 1 == middle && middle - 1 == low) || high == middle || low == middle) {
                return std::min(std::min(std::min(high_element, middle_element), low_element), minimum);
            }

            // Check for minimum
            minimum = std::min(minimum, middle_element);

            // If lowest element > middle element, we know that the minimum is on the first half
            // or the left half of the array
            if(low_element > middle_element) {
                high = middle;
            // Else, if the lowest element < middle element, we know that the minimum is on the second half
            // or the right half of the array
            } else if(low_element < middle_element) {
                low = middle;
            } else if(low_element == middle_element) {
                // If the lowest element == middle element, there is repetition on the array.
                // To find the minimum, we split the array  into two halves, left and right.
                // We do a binary search on each halves, and get the minimum of the two halves
                int left_min = halfBinarySearch(nums, low, middle);
                int right_min = halfBinarySearch(nums, middle, high);

                return std::min(left_min, right_min);
            }

            middle = findMiddle(low, high);
        }

        return minimum;
    }

private:
    int halfBinarySearch(const std::vector<int>& nums, int low, int high)
    {
        int ret = -1;

        // Calculate the middle
        int middle = findMiddle(low, high);

        while(low <= high) {
            // Get the high and low elements
            int high_element = nums[high];
            int middle_element = nums[middle];
            int low_element = nums[low];

            // If there are only 3 elements left, we min the three elements
            if((high - 1 == middle && middle - 1 == low) || high == middle || low == middle) {
                return std::min(std::min(high_element, middle_element), low_element);
            }

            // If lowest element > middle element, we know that the minimum is on the first half
            // or the left half of the array
            if(low_element > middle_element) {
                high = middle;
            // Else, if the lowest element < middle element, we know that the minimum is on the second half
            // or the right half of the array
            } else if(low_element < middle_element) {
                low = middle;
            } else if(low_element == middle_element) {
                // If the lowest element == middle element, there is repetition on the array.
                // To find the minimum, we split the array  into two halves, left and right.
                // We do a binary search on each halves, and get the minimum of the two halves
                // To do this, we do a recursive binary search on each halves
                int left_min = halfBinarySearch(nums, low, middle);
                int right_min = halfBinarySearch(nums, middle, high);

                return std::min(left_min, right_min);
            }

            middle = findMiddle(low, high);
        }

        return ret;
    }

    int findMiddle(int low, int high)
    {
        return low + ((high - low) / 2);
    }
};

int main()
{
    Solution sol;
    std::vector<int> arr;

    arr = { 7, 0, 1, 2, 3, 4, 5, 6 };
    std::cout << sol.findMin(arr) << std::endl;

    arr = { 6, 7, 0, 1, 2, 3, 4, 5 };
    std::cout << sol.findMin(arr) << std::endl;

    arr = { 5, 6, 7, 0, 1, 2, 3, 4 };
    std::cout << sol.findMin(arr) << std::endl;

    arr = { 4, 5, 6, 7, 0, 1, 2, 3 };
    std::cout << sol.findMin(arr) << std::endl;

    arr = { 3, 4, 5, 6, 7, 0, 1, 2 };
    std::cout << sol.findMin(arr) << std::endl;

    arr = { 2, 3, 4, 5, 6, 7, 0, 1 };
    std::cout << sol.findMin(arr) << std::endl;

    arr = { 1, 2, 3, 4, 5, 6, 7, 0 };
    std::cout << sol.findMin(arr) << std::endl;

    arr = { 0, 1, 2, 3, 4, 5, 6, 7 };
    std::cout << sol.findMin(arr) << std::endl;

    arr = { 1, 1 };
    std::cout << sol.findMin(arr) << std::endl;

    arr = { 1, 1, 1 };
    std::cout << sol.findMin(arr) << std::endl;

    arr = { 3, 3, 3, 3, 3, 3, 3, 1, 3 };
    std::cout << sol.findMin(arr) << std::endl;

    arr = {6, 2, 3, 5};
    std::cout << sol.findMin(arr) << std::endl;

    std::vector<int> arr4 = { 2, 3, 4, 0, 1, 2, 2, 2 };
    std::cout << sol.findMin(arr4) << std::endl;
}
