from collections import Counter

class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        count = Counter(text)
        # 'balloon' requires: b:1, a:1, l:2, o:2, n:1
        return min(count['b'], count['a'], count['l'] // 2, count['o'] // 2, count['n'])
