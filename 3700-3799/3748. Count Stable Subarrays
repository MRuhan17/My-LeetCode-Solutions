import java.util.*;

public class Solution {
    public long[] countStableSubarrays(int[] nums, int[][] queries) {
        int n = nums.length;
        List<Integer> starts = new ArrayList<>();
        List<Integer> ends = new ArrayList<>();
        List<Long> runTotals = new ArrayList<>();
        int i = 0;
        while (i < n) {
            int j = i;
            while (j + 1 < n && nums[j] <= nums[j + 1]) ++j;
            starts.add(i);
            ends.add(j);
            long len = j - i + 1;
            runTotals.add(len * (len + 1) / 2);
            i = j + 1;
        }
        int[] runId = new int[n];
        for (int rid = 0; rid < starts.size(); ++rid) {
            for (int k = starts.get(rid); k <= ends.get(rid); ++k) {
                runId[k] = rid;
            }
        }
        long[] prefix = new long[runTotals.size() + 1];
        for (int rid = 0; rid < runTotals.size(); ++rid) {
            prefix[rid + 1] = prefix[rid] + runTotals.get(rid);
        }
        long[] ans = new long[queries.length];
        for (int q = 0; q < queries.length; ++q) {
            int l = queries[q][0], r = queries[q][1];
            int leftRun = runId[l];
            int rightRun = runId[r];
            if (leftRun == rightRun) {
                long len = r - l + 1;
                ans[q] = len * (len + 1) / 2;
            } else {
                long leftLen = ends.get(leftRun) - l + 1;
                long leftSum = leftLen * (leftLen + 1) / 2;
                long rightLen = r - starts.get(rightRun) + 1;
                long rightSum = rightLen * (rightLen + 1) / 2;
                long midSum = prefix[rightRun] - prefix[leftRun + 1];
                ans[q] = leftSum + rightSum + midSum;
            }
        }
        return ans;
    }
}
