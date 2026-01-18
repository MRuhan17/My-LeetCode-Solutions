class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int n = nums.length;
        int closest = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1, right = n - 1;
            while (left < right) {
                int currSum = nums[i] + nums[left] + nums[right];
                if (Math.abs(currSum - target) < Math.abs(closest - target)) {
                    closest = currSum;
                }
                if (currSum < target) {
                    left++;
                } else if (currSum > target) {
                    right--;
                } else {
                    return target; 
                }
            }
        }
        return closest;
    }
}
