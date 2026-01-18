class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
      
        int currentStart = intervals[0][0];
        int currentEnd = intervals[0][1];
      
        vector<vector<int>> mergedIntervals;
      
        for (int i = 1; i < intervals.size(); ++i) {
            if (currentEnd < intervals[i][0]) {
                mergedIntervals.push_back({currentStart, currentEnd});
                currentStart = intervals[i][0];
                currentEnd = intervals[i][1];
            } else {
                currentEnd = max(currentEnd, intervals[i][1]);
            }
        }
        mergedIntervals.push_back({currentStart, currentEnd});
      
        return mergedIntervals;
    }
};
