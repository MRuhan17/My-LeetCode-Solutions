class Solution {
    private int[][] heights;
    private int rows;
    private int cols;

    public List<List<Integer>> pacificAtlantic(int[][] heights) {
        rows = heights.length;
        cols = heights[0].length;
        this.heights = heights;
    
        Deque<int[]> pacificQueue = new LinkedList<>();
        Deque<int[]> atlanticQueue = new LinkedList<>();
      
        Set<Integer> pacificVisited = new HashSet<>();
        Set<Integer> atlanticVisited = new HashSet<>();
       
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (row == 0 || col == 0) {
                    int encodedPosition = row * cols + col;
                    pacificVisited.add(encodedPosition);
                    pacificQueue.offer(new int[] {row, col});
                }
                if (row == rows - 1 || col == cols - 1) {
                    int encodedPosition = row * cols + col;
                    atlanticVisited.add(encodedPosition);
                    atlanticQueue.offer(new int[] {row, col});
                }
            }
        }
      
        bfs(pacificQueue, pacificVisited);
        bfs(atlanticQueue, atlanticVisited);
      
        List<List<Integer>> result = new ArrayList<>();
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                int encodedPosition = row * cols + col;
                if (pacificVisited.contains(encodedPosition) && 
                    atlanticVisited.contains(encodedPosition)) {
                    result.add(Arrays.asList(row, col));
                }
            }
        }
      
        return result;
    }

    private void bfs(Deque<int[]> queue, Set<Integer> visited) {
        int[] directions = {-1, 0, 1, 0, -1};
      
        while (!queue.isEmpty()) {
            int levelSize = queue.size();
            for (int i = 0; i < levelSize; i++) {
                int[] currentCell = queue.poll();
                int currentRow = currentCell[0];
                int currentCol = currentCell[1];
              
                for (int dir = 0; dir < 4; dir++) {
                    int nextRow = currentRow + directions[dir];
                    int nextCol = currentCol + directions[dir + 1];
                    int encodedNextPosition = nextRow * cols + nextCol;
                  
                    if (nextRow >= 0 && nextRow < rows && 
                        nextCol >= 0 && nextCol < cols && 
                        !visited.contains(encodedNextPosition) &&
                        heights[nextRow][nextCol] >= heights[currentRow][currentCol]) {
                        visited.add(encodedNextPosition);
                        queue.offer(new int[] {nextRow, nextCol});
                    }
                }
            }
        }
    }
}
