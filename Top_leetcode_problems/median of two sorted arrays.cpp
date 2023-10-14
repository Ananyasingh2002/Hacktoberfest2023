class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int low=0;
        int high=n;
        int akshat;
        if (n > m) {
            return findMedianSortedArrays(nums2, nums1);
        }
        while(low<=high){
          int i1 = (low + high) / 2;
            int i2 = (n + m + 1) / 2 - i1;
            int maxLeft1 = (i1 == 0) ? INT_MIN : nums1[i1 - 1];
            int minRight1 = (i1 == n) ? INT_MAX : nums1[i1];
            int maxLeft2 = (i2 == 0) ? INT_MIN : nums2[i2 - 1];
            int minRight2 = (i2 == m) ? INT_MAX : nums2[i2];
            
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                if ((n + m) % 2 == 0) {
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                } else {
                    return max(maxLeft1, maxLeft2);
                }
            } else if (maxLeft1 > minRight2) {
                high = i1 - 1;
            } else {
                low = i1 + 1;
            }
        }
return -1;
    }
};

