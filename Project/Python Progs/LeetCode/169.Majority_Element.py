class Solution:
    def majorityElement(self, nums: List[int]) -> int: #Time complexity is O(Nlog N)
        sorted_nums = sorted(nums)
        if sorted_nums[0] == sorted_nums[len(nums)//2]:
            return sorted_nums[0]
        else :
            return sorted_nums[len(nums)//2 + 1]
        
# Optimized Algorithm is Moore's algorithm Voting 
class Solution:
    def majority(self,nums: List[int]) -> int: # Time complexity is O(N)
        element = 0
        count = 0
        i = 0
        while i < len(nums) :
            if count == 0 :
                count = 1
                element = nums[i]
            elif nums[i] == element:
                count += 1
            else:
                count -= 1
        return element