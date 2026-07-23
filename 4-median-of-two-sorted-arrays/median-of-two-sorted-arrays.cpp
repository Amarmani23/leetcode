class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Always run binary search on the smaller array for efficiency and safety
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        
        int low = 0;
        int high = m;
        
        while (low <= high) {
            // Cut positions
            int cut1 = low + (high - low) / 2;
            int cut2 = (m + n + 1) / 2 - cut1;
            
            // Extract the 4 values around the cuts. 
            // If the cut is at the absolute edge, use -Infinity or +Infinity.
            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            
            int r1 = (cut1 == m) ? INT_MAX : nums1[cut1];
            int r2 = (cut2 == n) ? INT_MAX : nums2[cut2];
            
            // Check if the partition is valid
            if (l1 <= r2 && l2 <= r1) {
                // If total length is even, median is average of the max-left and min-right
                if ((m + n) % 2 == 0) {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                } 
                // If total length is odd, median is just the max of the left side
                else {
                    return max(l1, l2);
                }
            }
            // Cut1 is too far right, move left
            else if (l1 > r2) {
                high = cut1 - 1;
            }
            // Cut1 is too far left, move right
            else {
                low = cut1 + 1;
            }
        }
        
        return 0.0; // Fallback, should never be reached if inputs are valid
    }
};