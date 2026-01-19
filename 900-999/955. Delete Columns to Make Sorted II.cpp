class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        if (A.empty() || A.size() <= 1) {
            return 0;
        }
      
        int numStrings = A.size();
        int stringLength = A[0].length();
        int deletedColumns = 0;
      
        vector<bool> sorted(numStrings - 1, false);
      
        for (int col = 0; col < stringLength; col++) {
            bool shouldDelete = false;
          
            for (int row = 0; row < numStrings - 1; row++) {
                if (!sorted[row] && A[row][col] > A[row + 1][col]) {
                    shouldDelete = true;
                    break;
                }
            }
          
            if (shouldDelete) {
                deletedColumns++;
                continue;
            }
            for (int row = 0; row < numStrings - 1; row++) {
                if (A[row][col] < A[row + 1][col]) {
                    sorted[row] = true;
                }
            }
        }
      
        return deletedColumns;
    }
};
