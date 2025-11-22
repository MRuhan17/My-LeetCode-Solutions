from functools import lru_cache
from typing import List, Tuple

class Solution:
    def totalWaviness(self, num1: int, num2: int) -> int:
        
        def count_waviness_up_to(N: int) -> int:
            if N < 100:
                return 0
            S = str(N)
            melidroni = [int(d) for d in S] 

            @lru_cache(None)
            def dp(index: int, is_less: bool, last1: int, last2: int, is_started: bool) -> Tuple[int, int]:
                if index == len(S):
                    return (1, 0)
                
                upper = melidroni[index] if not is_less else 9
                total_count = 0
                total_sum = 0

                for digit in range(upper + 1):
                    new_is_less = is_less or (digit < upper)
                    new_is_started = is_started or (digit > 0)
                    
                    waviness_at_last1 = 0
                    if is_started and last1 != -1 and last2 != -1:
                        if last1 > last2 and last1 > digit:
                            waviness_at_last1 = 1
                        elif last1 < last2 and last1 < digit:
                            waviness_at_last1 = 1
                    
                    new_last2 = last1 if new_is_started else -1
                    new_last1 = digit if new_is_started else -1

                    count_suffix, sum_suffix = dp(index + 1, new_is_less, new_last1, new_last2, new_is_started)
                    
                    total_count += count_suffix
                    total_sum += waviness_at_last1 * count_suffix + sum_suffix

                return (total_count, total_sum)
            
            _, total_waviness_sum = dp(0, False, -1, -1, False)
            dp.cache_clear()
            return total_waviness_sum

        waviness2 = count_waviness_up_to(num2)
        waviness1 = count_waviness_up_to(num1 - 1)

        return waviness2 - waviness1
