class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
      
        function<void(int, int, string)> backtrack = [&](int openCount, int closeCount, string currentString) {
            if (openCount > n || closeCount > n || openCount < closeCount) {
                return;
            }
          
            if (openCount == n && closeCount == n) {
                result.push_back(currentString);
                return;
            }
          
            backtrack(openCount + 1, closeCount, currentString + "(");
          
            backtrack(openCount, closeCount + 1, currentString + ")");
        };
      
        backtrack(0, 0, "");
      
        return result;
    }
};
