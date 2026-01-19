class Solution:
    def checkPerfectNumber(self, num: int) -> bool:
        if num == 1:
            return False

        ans = 1

        for i in range(2, int(num**0.5) + 1):
            
            if num % i == 0:
                ans += i + num // i

        return ans == num
