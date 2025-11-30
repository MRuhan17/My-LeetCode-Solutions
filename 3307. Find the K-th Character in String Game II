class Solution {
    public char kthCharacter(long k, int[] operations) {
        int n = operations.length;

        long[] len = new long[n + 1];
        len[0] = 1L;
        for (int i = 0; i < n; i++) {
            len[i + 1] = Math.min(len[i] * 2, k);
        }

        int shift = 0;
        for (int i = n - 1; i >= 0; i--) {
            long curLen = len[i + 1];
            long lenBefore = len[i];

            if (k > lenBefore) {
                k -= lenBefore;
                if (operations[i] == 1) {
                    shift = (shift + 1) % 26;
                }
            }
        }

        int ch = (shift % 26 + 26) % 26;
        return (char) ('a' + ch);
    }
}
