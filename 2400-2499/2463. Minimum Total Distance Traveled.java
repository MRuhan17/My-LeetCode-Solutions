import java.util.*;

class Solution {
    public long minimumTotalDistance(List<Integer> robot, int[][] factory) {
        Collections.sort(robot);
        Arrays.sort(factory, (a, b) -> Integer.compare(a[0], b[0]));

        int n = robot.size();
        int m = factory.length;
        long[][] dp = new long[n + 1][m + 1];
        long INF = (long) 4e18;

        for (int i = 0; i <= n; i++) {
            Arrays.fill(dp[i], INF);
        }
        for (int j = 0; j <= m; j++) {
            dp[0][j] = 0;
        }

        for (int j = 1; j <= m; j++) {
            int pos = factory[j - 1][0];
            int limit = factory[j - 1][1];

            for (int i = 0; i <= n; i++) {
                dp[i][j] = dp[i][j - 1];

                long cost = 0;
                for (int k = 1; k <= Math.min(limit, i); k++) {
                    cost += Math.abs((long) robot.get(i - k) - pos);
                    dp[i][j] = Math.min(dp[i][j], dp[i - k][j - 1] + cost);
                }
            }
        }

        return dp[n][m];
    }
}
