# Optimized code 
class Solution:
    def firstBadVersion(self, n: int) -> int: #Time complexity O(Log(N))
        low = 1
        high = n
        while low <= high :
            mid = (high + low)//2
            if isBadVersion(mid) :
                high = mid - 1
            else :
                low = mid + 1
        return low