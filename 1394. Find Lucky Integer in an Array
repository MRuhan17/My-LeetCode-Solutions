class Solution {
    public int findLucky(int[] arr) {
         int[] freq = new int[501];
        for (int x : arr) {
            freq[x]++;
        }

        int ans = -1;
        for (int v = 1; v <= 500; v++) {
            if (freq[v] == v) {
                ans = v;
            }
        }
        return ans;
    }
}
