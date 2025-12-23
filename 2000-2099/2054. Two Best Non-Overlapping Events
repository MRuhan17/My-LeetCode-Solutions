class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        ranges::sort(events);

        int n = events.size();

        vector<int> maxValueFromIndex(n + 1);
        for (int i = n - 1; i >= 0; --i) {
            maxValueFromIndex[i] = max(maxValueFromIndex[i + 1], events[i][2]);
        }

        int maxSum = 0;

        for (const auto& currentEvent : events) {
            int currentValue = currentEvent[2];

            int left = 0;
            int right = n - 1;
            int firstTrueIndex = -1;

            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (events[mid][0] > currentEvent[1]) {
                    firstTrueIndex = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            if (firstTrueIndex != -1) {
                currentValue += maxValueFromIndex[firstTrueIndex];
            }
            maxSum = max(maxSum, currentValue);
        }

        return maxSum;
    }
};
