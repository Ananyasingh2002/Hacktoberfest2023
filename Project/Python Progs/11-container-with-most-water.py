class Solution:
    def maxArea(self, height: List[int]) -> int:
        l, r = 0, len(height)-1
        h = max(height)
        res = 0

        while l < r:
            ar = min( [height[l] , height[r]] ) * (r-l)
            if ar > res:
                res = ar
            if height[l] < height[r]:
                l += 1
            else:
                r -= 1            
            if (r - l) * h <= res:
                break
        
        return res