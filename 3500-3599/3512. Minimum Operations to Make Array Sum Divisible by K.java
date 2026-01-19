class Solution {
    public int minOperations(int[] nums, int k) {
        int totalSum = Arrays.stream(nums).sum();
        return totalSum % k;
    }
}
