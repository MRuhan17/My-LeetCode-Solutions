class Solution {
    public int numberOfPaths(int[][] grid, int k) {
        int m = grid.length;
        int n = grid[0].length;
        int MOD = 1_000_000_007;

        int[][] prev = new int[n][k];
        for (int i = 0; i < m; i++) {
            int[][] curr = new int[n][k];
            for (int j = 0; j < n; j++) {
                for (int rem = 0; rem < k; rem++) {
                    int val = grid[i][j];
                    if (i == 0 && j == 0) {
                        if (rem == val % k) {
                            curr[j][rem] = 1;
                        }
                    } else {
                        int pre_rem = ((rem - val % k) + k) % k;
                        if (i > 0) {
                            curr[j][rem] = (curr[j][rem] + prev[j][pre_rem]) % MOD;
                        }
                        if (j > 0) {
                            curr[j][rem] = (curr[j][rem] + curr[j-1][pre_rem]) % MOD;
                        }
                    }
                }
            }
            prev = curr;
        }
        return prev[n-1][0];
    }
}
