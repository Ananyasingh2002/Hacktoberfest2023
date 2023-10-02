class Solution {
    public boolean isMonotonic(int[] nums) {
        if (nums.length < 2) return true;

        int direction = 0;  // 0 means unknown, 1 means increasing, -1 means decreasing

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > nums[i-1]) {  // increasing
                if (direction == 0) direction = 1;
                else if (direction == -1) return false;
            } else if (nums[i] < nums[i-1]) {  // decreasing
                if (direction == 0) direction = -1;
                else if (direction == 1) return false;
            }
        }

        return true;
    }
}
