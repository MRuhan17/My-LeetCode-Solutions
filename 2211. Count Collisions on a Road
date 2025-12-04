class Solution {
    public int countCollisions(String directions) {
        int n = directions.length();
        char[] s = directions.toCharArray();

        int left = 0;
        while (left < n && s[left] == 'L') {
            left++;
        }

        int right = n - 1;
        while (right >= 0 && s[right] == 'R') {
            right--;
        }

        if (left > right) {
            return 0;
        }

        int total = right - left + 1;
        int stationary = 0;

        for (int i = left; i <= right; i++) {
            if (s[i] == 'S') {
                stationary++;
            }
        }

        return total - stationary;
    }
}
