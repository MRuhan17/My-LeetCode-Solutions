#include <cstdint>
class Solution {
    int table[256];
public:
    Solution() {
        for (int i = 0; i < 256; ++i) {
            int x = i, cnt = 0;
            while (x) { x &= x - 1; cnt++; }
            table[i] = cnt;
        }
    }
    
    int hammingWeight(uint32_t n) {
        return table[n & 0xFF] + table[(n >> 8) & 0xFF] +
               table[(n >> 16) & 0xFF] + table[(n >> 24) & 0xFF];
    }
};
