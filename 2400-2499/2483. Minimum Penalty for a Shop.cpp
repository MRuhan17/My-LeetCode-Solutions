class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
      
        vector<int> prefixSum(n + 1);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + (customers[i] == 'Y');
        }
      
        int bestHour = 0;
        int minCost = INT_MAX;
      
        for (int closingHour = 0; closingHour <= n; ++closingHour) {
            int noCustomerPenalty = closingHour - prefixSum[closingHour];
            int customerPenalty = prefixSum[n] - prefixSum[closingHour];
            int totalCost = noCustomerPenalty + customerPenalty;
          
            if (totalCost < minCost) {
                bestHour = closingHour;
                minCost = totalCost;
            }
        }
      
        return bestHour;
    }
};
