class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int totalCount = 0;

        for (int row = 0; row < rows; row++) {
            int left = 0;
            int right = cols - 1;
            int firstTrueIndex = -1;

            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (grid[row][mid] < 0) {
                    firstTrueIndex = mid;
                    right = mid - 1;  
                } else {
                    left = mid + 1;  
                }
            }

            if (firstTrueIndex != -1) {
                totalCount += cols - firstTrueIndex;
            }
        }

        return totalCount;
    }
};
