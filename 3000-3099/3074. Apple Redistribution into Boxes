class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.rbegin(), capacity.rend());
      
        int totalApples = accumulate(apple.begin(), apple.end(), 0);
      
        for (int boxCount = 1; ; ++boxCount) {
            totalApples -= capacity[boxCount - 1];
          
            if (totalApples <= 0) {
                return boxCount;
            }
        }
    }
};
