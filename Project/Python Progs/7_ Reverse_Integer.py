Link : https://leetcode.com/problems/reverse-integer/description/

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21

solution :

class Solution:
    def reverse(self, x: int) -> int:
        if not x:
            return x
        temp = [i for i in str(x)]
        i = '0'
        j = '-'
        temp = temp[::-1]
        while 0 <= len(temp):
            if temp[0] == i:
                temp.remove(temp[0])
            else:
                break
        if temp[-1] == j:
            temp.insert(0,j)
            temp.pop()
        result = int(''.join(map(str,temp)))
        if result > 2**31 - 1 or result < -2**31:
            return 0
        else:
            return result
