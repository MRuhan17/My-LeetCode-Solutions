class Solution {
public:
    bool isMatch(string s, string p) {
        int stringLength = s.size();
        int patternLength = p.size();
      
        vector<vector<int>> memo(stringLength + 1, vector<int>(patternLength + 1, -1));
      
        function<bool(int, int)> matchHelper = [&](int stringIdx, int patternIdx) -> bool {
            if (patternIdx >= patternLength) {
                return stringIdx == stringLength;
            }
          
            if (memo[stringIdx][patternIdx] != -1) {
                return memo[stringIdx][patternIdx] == 1;
            }
          
            bool isMatchFound = false;
          
            if (patternIdx + 1 < patternLength && p[patternIdx + 1] == '*') {
                isMatchFound = matchHelper(stringIdx, patternIdx + 2) ||  
                              (stringIdx < stringLength && 
                               (s[stringIdx] == p[patternIdx] || p[patternIdx] == '.') && 
                               matchHelper(stringIdx + 1, patternIdx)); 
            }
            else {
                isMatchFound = stringIdx < stringLength && 
                              (s[stringIdx] == p[patternIdx] || p[patternIdx] == '.') && 
                              matchHelper(stringIdx + 1, patternIdx + 1);
            }
          
            memo[stringIdx][patternIdx] = isMatchFound ? 1 : 0;
          
            return isMatchFound;
        };
      
        return matchHelper(0, 0);
    }
};
