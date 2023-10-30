class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ans = 0
        for num1 in nums:
            ans ^= num1
        
        return ans
