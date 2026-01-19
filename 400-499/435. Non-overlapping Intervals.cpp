class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
      
        int intervalsToRemove = intervals.size();
      
        int previousEnd = INT_MIN;
      
        for (const auto& interval : intervals) {
            int currentStart = interval[0];
            int currentEnd = interval[1];
          
            if (previousEnd <= currentStart) {
                intervalsToRemove--;
                previousEnd = currentEnd;
            }
        }
      
        return intervalsToRemove;
    }
};
