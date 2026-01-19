class Solution {
    public long maxRunTime(int n, int[] batteries) {
        long total = 0;
        for (int b : batteries) total += b;

        long low = 0, high = total/n;
        
        java.util.function.LongPredicate canRun = t ->{
            long usable = 0;
            for (int b : batteries){
                usable += Math.min((long) b, t);
                if (usable >= t * n) return true;
            }
            return usable >= t * n;
        };

        while (low < high) {
            long mid = (low + high + 1) / 2;
            if (canRun.test(mid)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
}
