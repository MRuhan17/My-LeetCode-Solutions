class Solution {
public:
    string getPermutation(int n, int k) {
        string result;
        bitset<10> used;  
      
        for (int position = 0; position < n; ++position) {
            int factorial = 1;
            for (int i = 1; i < n - position; ++i) {
                factorial *= i;
            }
          
            for (int digit = 1; digit <= n; ++digit) {
                if (used[digit]) {
                    continue;
                }
              
                if (k > factorial) {
                    k -= factorial;
                } else {
                    result += to_string(digit);
                    used[digit] = true;
                    break;
                }
            }
        }
      
        return result;
    }
};
