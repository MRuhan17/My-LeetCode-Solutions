import java.util.*;

class Solution {
    public int[] maximumWeight(List<List<Integer>> intervals) {
        int n = intervals.size();

        int[][] arr = new int[n][4];

        for (int i = 0; i < n; i++) {
            arr[i][0] = intervals.get(i).get(0);
            arr[i][1] = intervals.get(i).get(1);
            arr[i][2] = intervals.get(i).get(2);
            arr[i][3] = i;
        }

        Arrays.sort(arr, (a, b) -> Integer.compare(a[1], b[1]));

        long[][] dp = new long[n + 1][5];
        int[][][] ans = new int[n + 1][5][];

        for (int i = 0; i <= n; i++) {
            for (int k = 0; k <= 4; k++) {
                ans[i][k] = new int[0];
            }
        }

        for (int i = 1; i <= n; i++) {
            int left = arr[i - 1][0];
            int weight = arr[i - 1][2];
            int index = arr[i - 1][3];

            int previous = 0;

            for (int j = i - 1; j > 0; j--) {
                if (arr[j - 1][1] < left) {
                    previous = j;
                    break;
                }
            }

            for (int k = 1; k <= 4; k++) {
                dp[i][k] = dp[i - 1][k];
                ans[i][k] = ans[i - 1][k];

                long newScore = dp[previous][k - 1] + weight;

                int[] newAns = Arrays.copyOf(
                    ans[previous][k - 1],
                    ans[previous][k - 1].length + 1
                );

                newAns[newAns.length - 1] = index;
                Arrays.sort(newAns);

                if (newScore > dp[i][k] ||
                    (newScore == dp[i][k] &&
                     compare(newAns, ans[i][k]) < 0)) {

                    dp[i][k] = newScore;
                    ans[i][k] = newAns;
                }
            }
        }

        return ans[n][4];
    }

    private int compare(int[] a, int[] b) {
        int n = Math.min(a.length, b.length);

        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                return Integer.compare(a[i], b[i]);
            }
        }

        return Integer.compare(a.length, b.length);
    }
}
