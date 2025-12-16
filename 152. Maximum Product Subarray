class Solution {
    public int maxProduct(int[] nums) {
        int maxEndingHere = nums[0];  
        int minEndingHere = nums[0];  
        int globalMaxProduct = nums[0];  
      
        for (int i = 1; i < nums.length; i++) {
            int previousMax = maxEndingHere;
            int previousMin = minEndingHere;
          
            maxEndingHere = Math.max(nums[i], 
                                    Math.max(previousMax * nums[i], 
                                            previousMin * nums[i]));
          
            minEndingHere = Math.min(nums[i], 
                                    Math.min(previousMax * nums[i], 
                                            previousMin * nums[i]));
          
            globalMaxProduct = Math.max(globalMaxProduct, maxEndingHere);
        }
      
        return globalMaxProduct;
    }
}
