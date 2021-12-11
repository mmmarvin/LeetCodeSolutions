#include <iostream>
#include <vector>
#include <unordered_set>

//class Solution
//{
//public:
//    int removeDuplicates(std::vector<int>& nums)
//    {
//        typedef std::unordered_set<int>     NumberSetType;
//        typedef std::vector<std::size_t>    NumberArrayType;
//
//        // Number set for reference
//        NumberSetType number_set;
//        NumberArrayType number_to_delete_array;
//
//        for(std::vector<int>::size_type i = 0, i_size = nums.size(); i < i_size; ++i) {
//            int val = nums[i];
//
//            NumberSetType::iterator find_it = number_set.find(val);
//            if(find_it != number_set.end()) {
//                number_to_delete_array.emplace_back(i);
//            } else {
//                number_set.emplace(val);
//            }
//        }
//
//        std::size_t adjuster = 0;
//        for(NumberArrayType::iterator it = number_to_delete_array.begin(), it_end = number_to_delete_array.end(); it != it_end; ++it) {
//            NumberArrayType::difference_type diff = static_cast<NumberArrayType::difference_type>(*it - adjuster);
//            nums.erase(nums.begin() + diff);
//
//            ++adjuster;
//        }
//
//        return nums.size();
//    }
//};

class Solution {
    public:
    int removeDuplicates(std::vector<int>& A)
    {
        int num_duplicates = 0;

        std::size_t a_size = A.size();
        if(a_size < 2)
            return a_size;

        int id = 1;
        for(int i = 1; i < a_size; ++i)
            if(A[i] != A[i-1]) {
                A[id++] = A[i];
                ++num_duplicates;
            }

        for(int i = 0; i < num_duplicates; ++i)
            A.pop_back();
        return id;
    }
};

void print_arr(const std::vector<int>& arr)
{
    for(int i : arr) {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> dup = { 1, 1, 2, 3, 4, 5, 6, 6, 8 };
    print_arr(dup);

    Solution sol;
    std::cout << "Count: " << sol.removeDuplicates(dup) << std::endl;
    print_arr(dup);
}
