class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int writeIndex = 0;
      
        for (int currentNum : nums) {
            if (writeIndex < 2 || currentNum != nums[writeIndex - 2]) {
                nums[writeIndex++] = currentNum;
            }
        }
      
        return writeIndex;
    }
};
