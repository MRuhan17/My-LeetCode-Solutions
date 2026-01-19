#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> prefix_sum(n, 0);
        int total = 0;

        auto isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };

        for (int i = 0; i < n; i++) {
            if (isVowel(words[i][0]) && isVowel(words[i].back())) {
                total++;
            }
            prefix_sum[i] = total;
        }

        int q = queries.size();
        vector<int> ans(q, 0);
        for (int i = 0; i < q; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            if (l == 0)
                ans[i] = prefix_sum[r];
            else
                ans[i] = prefix_sum[r] - prefix_sum[l - 1];
        }
        return ans;
    }
};
