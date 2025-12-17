class Solution {
public:
    static const int MOD = 1'000'000'007;

    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<long long, long long> cntByY;
        cntByY.reserve(points.size() * 2);

        for (auto &p : points) {
            long long y = p[1];
            ++cntByY[y];
        }

        vector<long long> segs;
        segs.reserve(cntByY.size());
        for (auto &kv : cntByY) {
            long long k = kv.second;
            if (k >= 2) {
                long long seg = (k * (k - 1) / 2) % MOD;
                segs.push_back(seg);
            }
        }

        int m = (int)segs.size();
        if (m < 2) return 0;

        long long total = 0;
        long long suffix = 0;

        for (int i = m - 1; i >= 0; --i) {
            long long s = segs[i];
            total = (total + s * suffix) % MOD;
            suffix = (suffix + s) % MOD;
        }

        return (int)total;
    }
};
