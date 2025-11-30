class Solution {
    public int numFriendRequests(int[] ages) {
        int[] count = new int[121]; 
        for (int age : ages) {
            count[age]++;
        }

        int ans = 0;

        for (int ageA = 1; ageA <= 120; ageA++) {
            if (count[ageA] == 0) continue;  

            for (int ageB = 1; ageB <= 120; ageB++) {
                if (count[ageB] == 0) continue;  

                if (ageB <= 0.5 * ageA + 7) continue;
                if (ageB > ageA) continue;
                if (ageB > 100 && ageA < 100) continue;

                if (ageA == ageB) {
                    ans += count[ageA] * (count[ageA] - 1);
                } else {
                    ans += count[ageA] * count[ageB];
                }
            }
        }

        return ans;
    }
}
