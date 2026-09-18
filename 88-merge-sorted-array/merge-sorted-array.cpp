class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Start filling from the last index of nums1 (m + n - 1)
        int lastIndex = m + n - 1;
        
        // Pass m - 1 and n - 1 as the actual zero-indexed pointers
        mergeHelper(nums1, m - 1, nums2, n - 1, lastIndex);
    }

private:
    void mergeHelper(vector<int>& nums1, int i, vector<int>& nums2, int j, int p) {
        // Base Case 1: All elements from nums2 are successfully merged
        if (j < 0) {
            return;
        }
        
        // Base Case 2: All elements from nums1 are exhausted, 
        // copy the remaining elements from nums2
        if (i < 0) {
            nums1[p] = nums2[j];
            mergeHelper(nums1, i, nums2, j - 1, p - 1);
            return;
        }
        
        // Recursive Step: Compare values and place the larger one at the back
        if (nums1[i] > nums2[j]) {
            nums1[p] = nums1[i];
            mergeHelper(nums1, i - 1, nums2, j, p - 1);
        } else {
            nums1[p] = nums2[j];
            mergeHelper(nums1, i, nums2, j - 1, p - 1);
        }
    }
};
