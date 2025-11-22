class Solution {
    public int totalWaviness(int num1, int num2) {
        int total = 0;
        for (int n = num1; n <= num2; n++){
            String s = String.valueOf(n);
            int waviness = 0;
            if (s.length() < 3) continue;
            for (int i = 1; i < s.length()-1; i++){
                int prev = s.charAt(i-1) - '0';
                int curr = s.charAt(i) - '0';
                int next = s.charAt(i+1) - '0';
                if ((curr > prev && curr > next) || (curr < prev && curr < next)){
                    total++;
                }
            }
        }
        return total;
    }
}
