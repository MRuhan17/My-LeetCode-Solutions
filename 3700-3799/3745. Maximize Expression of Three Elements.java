class Solution {
    public int maximizeExpressionOfThree(int[] nums) {
        int n = nums.length;
        int max_val = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {       
            for (int j = 0; j < n; j++) {   
                if (i == j) continue;       
                for (int k = 0; k < n; k++) { 
                    if (k == i || k == j) continue;
                    max_val = Math.max(max_val, nums[i] + nums[k] - nums[j]);
                }
            }
        }
        return max_val;
    }
}
