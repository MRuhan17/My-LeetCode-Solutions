class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
      
        dp[0] = 1;
      
        for (int nodeCount = 1; nodeCount <= n; ++nodeCount) {
            for (int rootPosition = 0; rootPosition < nodeCount; ++rootPosition) {
                dp[nodeCount] += dp[rootPosition] * dp[nodeCount - rootPosition - 1];
            }
        }
      
        return dp[n];
    }
};
