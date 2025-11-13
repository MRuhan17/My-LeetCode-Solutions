public class Solution {
    public double new21Game(int n, int k, int maxPts) {
        // Edge case: Alice always wins if k == 0 or n >= k + maxPts - 1
        if (k == 0 || n >= k + maxPts - 1) return 1.0;

        double[] dp = new double[n + 1]; // dp[i]: probability to get i points
        dp[0] = 1.0;
        double windowSum = 1.0; // sum of last maxPts dp values
        double result = 0.0;

        for (int i = 1; i <= n; i++) {
            // Probability to get i points
            dp[i] = windowSum / maxPts;
            // Alice continues only if points < k
            if (i < k) {
                windowSum += dp[i];
            } else {
                // She stops, accumulate result
                result += dp[i];
            }
            // Remove dp[i - maxPts] from windowSum if outside window
            if (i - maxPts >= 0) {
                windowSum -= dp[i - maxPts];
            }
        }
        return result;
    }
}
