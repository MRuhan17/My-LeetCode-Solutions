class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
      
        vector<string> rows(numRows);
      
        int currentRow = 0;
        int direction = -1;
      
        for (char ch : s) {
            rows[currentRow] += ch;
          
            if (currentRow == 0 || currentRow == numRows - 1) {
                direction = -direction;
            }
          
            currentRow += direction;
        }
      
        string result;
        for (const auto& row : rows) {
            result += row;
        }
      
        return result;
    }
};
