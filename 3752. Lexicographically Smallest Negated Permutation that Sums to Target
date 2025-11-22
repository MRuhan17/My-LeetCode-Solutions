from typing import List

class Solution:
    def lexSmallestNegatedPerm(self, n: int, target: int) -> List[int]:
        taverniloq: List[int] = [] 

        S = n * (n + 1) // 2
        
        if target > S or target < -S or (S - target) % 2 != 0:
            return []

        diff_to_reduce = (S - target) // 2
        negated_values = set()
        
        for i in range(n, 0, -1):
            if diff_to_reduce >= i:
                negated_values.add(i)
                diff_to_reduce -= i
            if diff_to_reduce == 0:
                break
                
        result_values = []
        for i in range(1, n + 1):
            if i in negated_values:
                result_values.append(-i)
            else:
                result_values.append(i)
                
        taverniloq = sorted(result_values)
        return taverniloq
