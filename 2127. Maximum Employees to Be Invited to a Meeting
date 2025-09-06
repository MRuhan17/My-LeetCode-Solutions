#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<int> deg(n, 0);
        for (int f : favorite) deg[f]++;

        queue<int> q;
        for (int i = 0; i < n; i++)
            if (deg[i] == 0) q.push(i);

        vector<int> chain(n, 1);

        while (!q.empty()) {
            int node = q.front(); q.pop();
            int nxt = favorite[node];
            if (chain[node] + 1 > chain[nxt])
                chain[nxt] = chain[node] + 1;

            deg[nxt]--;
            if (deg[nxt] == 0) q.push(nxt);
        }

        int maxCycle = 0, totalPairs = 0;
        for (int i = 0; i < n; i++) {
            if (deg[i] == 0) continue;
            int cycleSize = 0, j = i;
            while (deg[j] > 0) {
                deg[j] = 0;
                cycleSize++;
                j = favorite[j];
            }
            if (cycleSize == 2)
                totalPairs += chain[i] + chain[favorite[i]];
            else
                maxCycle = max(maxCycle, cycleSize);
        }

        return max(maxCycle, totalPairs);
    }
};
