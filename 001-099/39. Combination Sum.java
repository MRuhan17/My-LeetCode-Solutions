class Solution {
    private List<List<Integer>> result = new ArrayList<>();
    private List<Integer> currentCombination = new ArrayList<>();
    private int[] candidates;

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);
        this.candidates = candidates;
      
        dfs(0, target);
      
        return result;
    }

   
    private void dfs(int startIndex, int remainingTarget) {
        if (remainingTarget == 0) {
            result.add(new ArrayList<>(currentCombination));
            return;
        }
      
        if (remainingTarget < candidates[startIndex]) {
            return;
        }
      
        for (int i = startIndex; i < candidates.length; ++i) {
            currentCombination.add(candidates[i]);
          
            dfs(i, remainingTarget - candidates[i]);
          
            currentCombination.remove(currentCombination.size() - 1);
        }
    }
}
