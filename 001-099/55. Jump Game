class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReachableIndex = 0;
      
        for (int currentIndex = 0; currentIndex < nums.size(); ++currentIndex) {
            if (maxReachableIndex < currentIndex) {
                return false;
            }
            maxReachableIndex = max(maxReachableIndex, currentIndex + nums[currentIndex]);
        }
        return true;
    }
};
