class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
      
        int directions[5] = {0, 1, 0, -1, 0};
      
        int currentRow = 0;
        int currentCol = 0;
        int directionIndex = 0;
      
        vector<int> result;
      
        bool visited[rows][cols];
        memset(visited, false, sizeof(visited));
      
        for (int count = rows * cols; count > 0; --count) {
            result.push_back(matrix[currentRow][currentCol]);
          
            visited[currentRow][currentCol] = true;
          
            int nextRow = currentRow + directions[directionIndex];
            int nextCol = currentCol + directions[directionIndex + 1];
          
            if (nextRow < 0 || nextRow >= rows || 
                nextCol < 0 || nextCol >= cols || 
                visited[nextRow][nextCol]) {
                directionIndex = (directionIndex + 1) % 4;
            }
            currentRow += directions[directionIndex];
            currentCol += directions[directionIndex + 1];
        }
      
        return result;
    }
};
