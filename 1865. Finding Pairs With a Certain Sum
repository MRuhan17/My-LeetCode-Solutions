class FindSumPairs {
    private int[] nums1;
    private int[] nums2;
    private Map<Integer, Integer> freq2;

    public FindSumPairs(int[] nums1, int[] nums2) {
        this.nums1 = nums1;
        this.nums2 = nums2;
        this.freq2 = new HashMap<>();
        for (int x : nums2) {
            freq2.put(x, freq2.getOrDefault(x, 0) + 1);
        }
    }

    public void add(int index, int val) {
        int oldVal = nums2[index];
        int cnt = freq2.get(oldVal);
        if (cnt == 1) {
            freq2.remove(oldVal);
        } else {
            freq2.put(oldVal, cnt - 1);
        }

        int newVal = oldVal + val;
        nums2[index] = newVal;
        freq2.put(newVal, freq2.getOrDefault(newVal, 0) + 1);
    }

    public int count(int tot) {
        int res = 0;
        for (int a : nums1) {
            int need = tot - a;
            res += freq2.getOrDefault(need, 0);
        }
        return res;
    }
}
