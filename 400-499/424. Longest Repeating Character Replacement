class Solution {
public:
    int characterReplacement(string s, int k) {
        int charFrequency[26] = {0};
      
        int left = 0;
      
        int maxFrequency = 0;
      
        int stringLength = s.length();
      
        for (int right = 0; right < stringLength; ++right) {
            charFrequency[s[right] - 'A']++;
            maxFrequency = max(maxFrequency, charFrequency[s[right] - 'A']);
          
            if (right - left + 1 - maxFrequency > k) {
                charFrequency[s[left] - 'A']--;
                left++;
            }
        }
      
        return stringLength - left;
    }
};
