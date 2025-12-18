class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();

        // 1. Base profit and prefix arrays
        long long base = 0;
        vector<long long> prefPrice(n + 1, 0), prefContrib(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            long long contrib = 1LL * strategy[i] * prices[i];
            base += contrib;
            prefPrice[i + 1]   = prefPrice[i] + prices[i];
            prefContrib[i + 1] = prefContrib[i] + contrib;
        }

        long long ans = base;  // no modification

        // 2. Try every window of length k
        for (int l = 0; l + k <= n; ++l) {
            int mid = l + k / 2;
            int r   = l + k - 1;

            // sum of prices in second half
            long long sumSecondPrices = prefPrice[r + 1] - prefPrice[mid];

            // original contribution of first half [l .. mid-1]
            long long origFirst  = prefContrib[mid] - prefContrib[l];

            // original contribution of second half [mid .. r]
            long long origSecond = prefContrib[r + 1] - prefContrib[mid];

            long long delta = sumSecondPrices - origFirst - origSecond;
            ans = max(ans, base + delta);
        }

        return ans;
    }
};
