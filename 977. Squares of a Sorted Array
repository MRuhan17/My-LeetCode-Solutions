#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int left = 0, right = n - 1;
        int pos = n - 1;

        while (left <= right) {
            if (abs(nums[left]) > abs(nums[right])) {
                res[pos--] = nums[left] * nums[left];
                left++;
            } else {
                res[pos--] = nums[right] * nums[right];
                right--;
            }
        }
        return res;
    }
};
