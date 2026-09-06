class Solution:
    def numDistinct(self, s, t):
        m, n = len(s), len(t)

        dp = [0] * (n + 1)

        for i in range(1, m + 1):
            last = 1

            for j in range(1, n + 1):
                cur = dp[j]

                take = 0
                if s[i - 1] == t[j - 1]:
                    take = last
                notTake = cur

                dp[j] = (take + notTake)
                last = cur

        return dp[n]
