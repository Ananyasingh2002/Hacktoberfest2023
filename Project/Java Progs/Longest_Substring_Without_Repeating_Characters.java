/*
 * Given a string s, find the length of the longest substring without repeating characters.

 *Example 1:
    Input: s = "abcabcbb"
    Output: 3
    Explanation: The answer is "abc", with the length of 3.

 *Example 2:
    Input: s = "bbbbb"
    Output: 1
    Explanation: The answer is "b", with the length of 1.

 *Example 3:
    Input: s = "pwwkew"
    Output: 3
    Explanation: The answer is "wke", with the length of 3.
    Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 
 *Constraints:
    0 <= s.length <= 5 * 104
    s consists of English letters, digits, symbols and spaces.
 */


import java.util.*;
class Solution {
    public int lengthOfLongestSubstring(String s) {
        Set<Character> s1 = new HashSet<Character>();
        int left = 0;
        int max = 0;
        for(int right=0 ; right<s.length() ; right++){
            if(!s1.contains(s.charAt(right))){
                s1.add(s.charAt(right));
                max = Math.max(max,(right-left+1));
            }else{
                while(s.charAt(left) != s.charAt(right)){
                    s1.remove(s.charAt(left));
                    left++;
                }
                s1.remove(s.charAt(left));
                left++;
                s1.add(s.charAt(right));
            }
        }
        return max;
    }
}

/*
 * Intuition
    if you know sliding window...then it can be intuitive. But if you don't know ...no worry i will teach you...
    Refer below approach points.....

*Approach
    Use sliding window with hashset, use left and right pointers to move the window .
    If the set doesn't contains character then first add into the set and calculate the maxLength hand-in-hand...
    if character already present in the set that means you have to move your sliding window by 1 , before that you have to remove all   the characters that are infront of the character that is present already in window before.
    Now you have to remove that character also and move the left pointer and also add the new character into the set.
    THAT'S ALL........EASY APPROACH USING SIMPLE HASHSET+SLIDING WINDOW

*Complexity
    Time complexity: O(n)
    Space complexity: O(k), where k is the number of distinctive characters prsent in the hashset.
 */