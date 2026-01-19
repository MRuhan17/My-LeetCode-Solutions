class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int numColumns = strs[0].size();
        vector<int> dp(numColumns, 1);
      
        for (int currentCol = 1; currentCol < numColumns; ++currentCol) {
            for (int prevCol = 0; prevCol < currentCol; ++prevCol) {
                bool canExtend = true;
                for (const string& str : strs) {
                    if (str[prevCol] > str[currentCol]) {
                        canExtend = false;
                        break;
                    }
                }
                if (canExtend) {
                    dp[currentCol] = max(dp[currentCol], dp[prevCol] + 1);
                }
            }
        }
        int maxValidColumns = *max_element(dp.begin(), dp.end());
        return numColumns - maxValidColumns;
    }
};
