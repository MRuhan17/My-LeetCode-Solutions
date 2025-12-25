class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(), happiness.rend());
      
        long long totalHappiness = 0;
      
        for (int i = 0; i < k; ++i) {
            int adjustedHappiness = happiness[i] - i;
          
            totalHappiness += max(adjustedHappiness, 0);
        }
      
        return totalHappiness;
    }
};
