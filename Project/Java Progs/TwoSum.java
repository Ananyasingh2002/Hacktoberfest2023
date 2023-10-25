/*
1.TWo Sum

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:
    Input: nums = [2,7,11,15], target = 9
    Output: [0,1]
    Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
    Input: nums = [3,2,4], target = 6
    Output: [1,2]

Example 3:
    Input: nums = [3,3], target = 6
    Output: [0,1]
 
Constraints:
    2 <= nums.length <= 104
    -109 <= nums[i] <= 109
    -109 <= target <= 109
    Only one valid answer exists.
*/

class TwoSum {
    public int[] twoSum(int[] nums, int target) {
        int arr[] = new int[2];
        for(int i=0 ; i<nums.length; i++){
            for(int j=0 ; j<nums.length; j++){
                if(i==j){
                    continue;
                }
                if((nums[i]+nums[j])==target){
                    arr[0]=i;
                    arr[1]=j;
                    break;
                }
            }
        }
        return arr;
    }
}

/*
 * Problem
    
 The problem statement describes a classic coding interview question. You are given an array of integers (nums) and an integer (target). Your task is to find two distinct numbers in the array that add up to the target. You need to return the indices of these two numbers.

 *Solution
    
    1. The twoSum function takes two arguments: nums, which is the list of integers, and target, which is the desired sum.
    
    2. The solution uses a nested loop. The outer loop iterates through the elements of the nums list using enumerate. The outer loop variable i represents the index, and x represents the element at that index.
    
    3.The inner loop also uses enumerate but starts from the i+1 index. This ensures that you don't use the same element twice (as the problem specifies). The inner loop variable j represents the index, and y represents the element at that index.
    
    4.The condition if x + y == target checks whether the sum of the current elements x and y is equal to the target.
    
    5.If a pair of elements is found that satisfies the condition, the next function returns a tuple (i, j) representing the indices of the two elements that add up to the target.
 */