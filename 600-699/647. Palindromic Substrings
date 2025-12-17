class Solution {
public:
    int countSubstrings(string s) {
        int palindromeCount = 0;
        int stringLength = s.size();
      
        for (int centerIndex = 0; centerIndex < stringLength * 2 - 1; ++centerIndex) {
            int left = centerIndex / 2;
            int right = (centerIndex + 1) / 2;
          
            while (left >= 0 && right < stringLength && s[left] == s[right]) {
                ++palindromeCount;
            
                --left;
                ++right;
            }
        }
      
        return palindromeCount;
    }
};
