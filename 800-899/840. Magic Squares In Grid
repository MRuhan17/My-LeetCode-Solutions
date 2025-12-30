class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
      
        auto isMagicSquare = [&](int row, int col) -> int {
            if (row + 3 > rows || col + 3 > cols) {
                return 0;
            }
          
            vector<int> frequency(16, 0);
            vector<int> rowSums(3, 0);
            vector<int> colSums(3, 0);
            int mainDiagonalSum = 0;
            int antiDiagonalSum = 0;
          
            for (int i = row; i < row + 3; ++i) {
                for (int j = col; j < col + 3; ++j) {
                    int value = grid[i][j];
                  
                    if (value < 1 || value > 9 || ++frequency[value] > 1) {
                        return 0;
                    }
                  
                    rowSums[i - row] += value;
                    colSums[j - col] += value;
                  
                    if (i - row == j - col) {
                        mainDiagonalSum += value;
                    }
                  
                    if (i - row + j - col == 2) {
                        antiDiagonalSum += value;
                    }
                }
            }
          
            if (mainDiagonalSum != antiDiagonalSum) {
                return 0;
            }
          
            for (int k = 0; k < 3; ++k) {
                if (rowSums[k] != mainDiagonalSum || colSums[k] != mainDiagonalSum) {
                    return 0;
                }
            }
          
            return 1;
        };
      
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                count += isMagicSquare(i, j);
            }
        }
      
        return count;
    }
};
