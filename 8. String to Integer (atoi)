class Solution:
    def myAtoi(self, s: str) -> int:
        s = s.lstrip()
        if not s:
            return 0
        
        sign = 1
        i = 0
        
        if s[i] == '-':
            sign = -1
            i += 1
        elif s[i] == '+':
            i += 1
            
        result = 0
        
        INT_MAX = 2**31 - 1
        INT_MIN = -2**31

        while i < len(s) and s[i].isdigit():
            digit = int(s[i])
            
            if sign == 1 and (result > INT_MAX // 10 or (result == INT_MAX // 10 and digit > 7)):
                return INT_MAX
            
            if sign == -1 and (result > INT_MAX // 10 or (result == INT_MAX // 10 and digit > 8)):
                return INT_MIN
                
            result = result * 10 + digit
            i += 1
        
        return sign * result
