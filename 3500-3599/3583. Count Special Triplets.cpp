class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> leftCount;
        unordered_map<int, int> rightCount;
      
        for (int num : nums) {
            rightCount[num]++;
        }
      
        long long result = 0;
        const int MOD = 1e9 + 7;
      
        for (int middleValue : nums) {
            rightCount[middleValue]--;
          
            int targetValue = middleValue * 2;
            result = (result + 1LL * leftCount[targetValue] * rightCount[targetValue] % MOD) % MOD;
          
            leftCount[middleValue]++;
        }
      
        return static_cast<int>(result);
    }
};
