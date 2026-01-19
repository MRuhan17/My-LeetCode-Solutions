class Solution {
    private int[][] transitions = new int[7][7];
  
    private Map<String, Boolean> memo = new HashMap<>();

    public boolean pyramidTransition(String bottom, List<String> allowed) {
        for (String triplet : allowed) {
            int leftBlock = triplet.charAt(0) - 'A';
            int rightBlock = triplet.charAt(1) - 'A';
            int topBlock = triplet.charAt(2) - 'A';
          
            transitions[leftBlock][rightBlock] |= (1 << topBlock);
        }
      
        return canBuildPyramid(bottom, new StringBuilder());
    }

    private boolean canBuildPyramid(String currentLevel, StringBuilder nextLevel) {
        if (currentLevel.length() == 1) {
            return true;
        }
      
        if (nextLevel.length() + 1 == currentLevel.length()) {
            return canBuildPyramid(nextLevel.toString(), new StringBuilder());
        }
      
        String memoKey = currentLevel + "." + nextLevel.toString();
        if (memo.containsKey(memoKey)) {
            return memo.get(memoKey);
        }
      
        int leftBlockIndex = currentLevel.charAt(nextLevel.length()) - 'A';
        int rightBlockIndex = currentLevel.charAt(nextLevel.length() + 1) - 'A';
      
        int possibleBlocks = transitions[leftBlockIndex][rightBlockIndex];
      
        for (int blockIndex = 0; blockIndex < 7; blockIndex++) {
            if (((possibleBlocks >> blockIndex) & 1) == 1) {
                nextLevel.append((char) ('A' + blockIndex));
              
                if (canBuildPyramid(currentLevel, nextLevel)) {
                    memo.put(memoKey, true);
                    return true;
                }
              
                nextLevel.deleteCharAt(nextLevel.length() - 1);
            }
        }
      
        memo.put(memoKey, false);
        return false;
    }
}
