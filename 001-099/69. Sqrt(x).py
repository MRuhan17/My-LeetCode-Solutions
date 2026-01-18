class Solution(object):
    def mySqrt(self, x):

        l, r = 0, x
        while l <= r:
            mid = l + (r - l) // 2
            if x < mid * mid:
                r = mid - 1
            elif x >= (mid + 1) * (mid + 1):
                l = mid + 1
            else:
                return mid
