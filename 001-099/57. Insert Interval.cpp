class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.emplace_back(newInterval);
      
        return merge(intervals);
    }

private:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
      
        vector<vector<int>> mergedIntervals;
        mergedIntervals.emplace_back(intervals[0]);
      
        for (int i = 1; i < intervals.size(); ++i) {
            if (mergedIntervals.back()[1] < intervals[i][0]) {
                mergedIntervals.emplace_back(intervals[i]);
            } else {
                mergedIntervals.back()[1] = max(mergedIntervals.back()[1], intervals[i][1]);
            }
        }
      
        return mergedIntervals;
    }
};
