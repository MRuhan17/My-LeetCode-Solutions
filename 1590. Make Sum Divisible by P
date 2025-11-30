import java.util.*;

class Solution {
    public int minSubarray(int[] nums, int p) {
        long total = 0;
        for (int x : nums) {
            total += x;
        }
        int need = (int)(total % p);
        if (need == 0) return 0;  

        Map<Integer, Integer> lastIndex = new HashMap<>();
        lastIndex.put(0, -1);   
        long prefix = 0;
        int n = nums.length;
        int ans = n;              

        for (int i = 0; i < n; i++) {
            prefix += nums[i];
            int cur = (int)(prefix % p);
            int target = cur - need;
            if (target < 0) target += p;
            Integer j = lastIndex.get(target);
            if (j != null) {
                int len = i - j;
                if (len < ans) ans = len;
            }
            lastIndex.put(cur, i);
        }
        return ans == n ? -1 : ans;
    }
}
