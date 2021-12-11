#include <bitset>

#include <iostream>

class Solution {
public:
    int findComplement(int num)
    {
        std::bitset<32> num_bit(num);

        bool found_leading_one = false;
        for(int i = num_bit.size() - 1; i >= 0; --i) {
            char bit = num_bit[i];
            if(bit == 0) {
                if(found_leading_one)
                    num_bit.flip(i);
            } else if(bit == 1) {
                found_leading_one = true;
                num_bit.flip(i);
            }
        }

        return num_bit.to_ulong();
    }
};

int main()
{
    Solution sol;
    std::cout << "value:" << sol.findComplement(5) << std::endl;
}
