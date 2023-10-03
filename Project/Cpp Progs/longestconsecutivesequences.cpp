#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        std::unordered_set<int> numSet(nums.begin(), nums.end());
        int longestStreak = 0;

        for (int num : numSet) {
            if (numSet.find(num - 1) == numSet.end()) { // Check if num is the start of a streak
                int currentNum = num;
                int currentStreak = 1;

                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentStreak++;
                }

                longestStreak = std::max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};
