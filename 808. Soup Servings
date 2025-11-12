import java.util.HashMap;
import java.util.Map;

class Solution {
    public double soupServings(int n) {
        // For large n, probability approaches 1
        if (n > 5000) return 1.0;
        int m = (n + 24) / 25; // ceil division
        
        // Memoization map
        Map<String, Double> memo = new HashMap<>();
        
        return dfs(m, m, memo);
    }
    
    private double dfs(int a, int b, Map<String, Double> memo) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1.0;
        if (b <= 0) return 0.0;
        
        String key = a + "," + b;
        if (memo.containsKey(key)) return memo.get(key);
        
        double result = 0.25 * (
            dfs(a - 4, b, memo) +
            dfs(a - 3, b - 1, memo) +
            dfs(a - 2, b - 2, memo) +
            dfs(a - 1, b - 3, memo)
        );
        memo.put(key, result);
        return result;
    }
}
