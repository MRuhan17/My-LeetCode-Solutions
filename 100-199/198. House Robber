class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
      
        int dp[n];
        memset(dp, -1, sizeof(dp));
      
        auto dfs = [&](this auto&& dfs, int i) -> int {
            if (i >= n) {
                return 0;
            }
          
            if (dp[i] < 0) {
                dp[i] = max(nums[i] + dfs(i + 2), dfs(i + 1));
            }
          
            return dp[i];
        };
      
        return dfs(0);
    }
};
