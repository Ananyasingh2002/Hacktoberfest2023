class Solution:
    def rob(self, nums: List[int]) -> int:
        r1 = r2 = 0

        for h in nums:
            temp = max(r1+h, r2)
            r1 = r2
            r2 = temp
        
        return r2