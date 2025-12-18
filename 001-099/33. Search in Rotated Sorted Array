class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        int firstTrueIndex = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            bool feasible;
            if (nums[0] <= nums[mid]) {
                feasible = nums[0] <= target && target <= nums[mid];
            } else {
                feasible = !(nums[mid] < target && target <= nums[n - 1]);
            }

            if (feasible) {
                firstTrueIndex = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        if (firstTrueIndex == -1) {
            return -1;
        }
        return nums[firstTrueIndex] == target ? firstTrueIndex : -1;
    }
};
