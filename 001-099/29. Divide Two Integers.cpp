class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 1) {
            return dividend;
        }
      
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
      
        bool isPositive = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0);
      
        dividend = dividend > 0 ? -dividend : dividend;
        divisor = divisor > 0 ? -divisor : divisor;
      
        int quotient = 0;
      
        while (dividend <= divisor) {
            int currentDivisor = divisor;
            int currentQuotient = 1;
          
            while (currentDivisor >= (INT_MIN >> 1) && dividend <= (currentDivisor << 1)) {
                currentDivisor <<= 1;  
                currentQuotient <<= 1; 
            }
          
            quotient += currentQuotient;
            dividend -= currentDivisor;
        }
      
        return isPositive ? quotient : -quotient;
    }
};
