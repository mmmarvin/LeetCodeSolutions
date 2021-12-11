class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        std::size_t ns = sizeof(n);
        std::size_t nsh = 0;

        while(nsh < ns) {
            // grab first 8 bits
            unsigned char f8b = n;

            // count how many 1s
            unsigned char m = 0x1;
            while(m) {
                // mask the bits, and determine if the value is anything
                // but 0
                if(m & f8b)
                    ++count;

                // shift by 1 bit
                m = m << 1;
            }

            // increment counter
            ++nsh;

            // shift the value by 8 bits to the right
            n = n >> 8;
        }

        return count;
    }
};