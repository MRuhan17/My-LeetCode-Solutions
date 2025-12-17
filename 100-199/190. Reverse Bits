#include <cstdint>
#include <vector>
using namespace std;

class Solution {
    uint32_t lookup[256];

public:
    Solution() {
        // Precompute reversed bits for all 1-byte numbers (0–255)
        for (int i = 0; i < 256; ++i) {
            uint32_t x = i, rev = 0;
            for (int j = 0; j < 8; ++j) {
                rev = (rev << 1) | (x & 1);
                x >>= 1;
            }
            lookup[i] = rev;
        }
    }

    uint32_t reverseBits(uint32_t n) {
        return (lookup[n & 0xFF] << 24) |
               (lookup[(n >> 8) & 0xFF] << 16) |
               (lookup[(n >> 16) & 0xFF] << 8) |
               (lookup[(n >> 24) & 0xFF]);
    }
};
