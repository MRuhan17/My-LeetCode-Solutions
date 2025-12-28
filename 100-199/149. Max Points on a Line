class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int numPoints = points.size();
        int maxPointsOnLine = 1; 
      
        for (int i = 0; i < numPoints; ++i) {
            int x1 = points[i][0];
            int y1 = points[i][1];
          
            for (int j = i + 1; j < numPoints; ++j) {
                int x2 = points[j][0];
                int y2 = points[j][1];
              
                int pointsOnCurrentLine = 2;
              
                for (int k = j + 1; k < numPoints; ++k) {
                    int x3 = points[k][0];
                    int y3 = points[k][1];
                  
                    int crossProduct1 = (y2 - y1) * (x3 - x1);
                    int crossProduct2 = (y3 - y1) * (x2 - x1);
                  
                    if (crossProduct1 == crossProduct2) {
                        pointsOnCurrentLine++;
                    }
                }
              
                maxPointsOnLine = max(maxPointsOnLine, pointsOnCurrentLine);
            }
        }
      
        return maxPointsOnLine;
    }
};
