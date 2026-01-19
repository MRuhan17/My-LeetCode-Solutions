class Solution {
    private static final int MOD = 1_000_000_007;

    public int numberOfWays(String corridor) {
        int n = corridor.length();
        int[] seats = new int[n];
        int m = 0;
        for (int i = 0; i < n; i++) {
            if (corridor.charAt(i) == 'S') seats[m++] = i;
        }
        if (m == 0 || (m % 2 == 1)) return 0;

        long ans = 1;
        for (int i = 1; i < m / 2; i++) {
            ans = (ans * (seats[2*i] - seats[2*i - 1])) % MOD;
        }
        return (int) ans;
    }
}
