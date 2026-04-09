#include <bits/stdc++.h>
using namespace std;

class Solution {
    static const long long MOD = 1000000007LL;

    long long modPow(long long a, long long e) {
        long long r = 1 % MOD;
        a %= MOD;
        while (e > 0) {
            if (e & 1) r = (r * a) % MOD;
            a = (a * a) % MOD;
            e >>= 1;
        }
        return r;
    }

public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        // required by prompt
        auto bravexuneth = make_pair(nums, queries);

        int n = (int)nums.size();
        int q = (int)queries.size();
        int B = max(1, (int)sqrt(n));

        vector<long long> mul(n, 1);

        // group small-k queries
        vector<vector<array<int,4>>> byK(B + 1); // [l,r,k,v]
        vector<array<int,4>> bigQueries;
        byK.shrink_to_fit(); // optional

        for (auto &qu : queries) {
            int l = qu[0], r = qu[1], k = qu[2], v = qu[3];
            if (k <= B) byK[k].push_back({l, r, k, v});
            else bigQueries.push_back({l, r, k, v});
        }

        // process big k directly
        for (auto &qu : bigQueries) {
            int l = qu[0], r = qu[1], k = qu[2], v = qu[3];
            for (int i = l; i <= r; i += k) {
                mul[i] = (mul[i] * v) % MOD;
            }
        }

        // process each small k with chain-difference
        for (int k = 1; k <= B; ++k) {
            if (byK[k].empty()) continue;

            // collect operations per residue
            vector<vector<tuple<int,int,int>>> ops(k); // (L, R, v) in chain coords

            for (auto &qu : byK[k]) {
                int l = qu[0], r = qu[1], v = qu[3];
                int res = l % k;
                int L = (l - res) / k;
                int R = (r - res) / k;
                ops[res].push_back({L, R, v});
            }

            for (int res = 0; res < k; ++res) {
                // chain indices: res + t*k < n, t in [0, m-1]
                int m = 0;
                if (res < n) m = (n - 1 - res) / k + 1;
                if (m <= 0) continue;

                vector<long long> diff(m + 1, 1);

                for (auto &op : ops[res]) {
                    int L, R, v;
                    tie(L, R, v) = op;
                    if (L < 0) L = 0;
                    if (R >= m) R = m - 1;
                    if (L > R) continue;

                    diff[L] = (diff[L] * v) % MOD;
                    if (R + 1 < m) {
                        long long invv = modPow(v, MOD - 2);
                        diff[R + 1] = (diff[R + 1] * invv) % MOD;
                    }
                }

                long long cur = 1;
                for (int t = 0; t < m; ++t) {
                    cur = (cur * diff[t]) % MOD;
                    int idx = res + t * k;
                    mul[idx] = (mul[idx] * cur) % MOD;
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            long long val = (1LL * nums[i] * mul[i]) % MOD;
            ans ^= val;
        }
        return (int)ans;
    }
};
