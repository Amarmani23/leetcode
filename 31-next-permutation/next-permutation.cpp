class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        // Step 1: Find the first decreasing element from the right
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // Step 2: If pivot exists, find element strictly larger than nums[i] from the right
        if (i >= 0) {
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            // Step 3: Swap pivot with successor
            swap(nums[i], nums[j]);
        }

        // Step 4: Reverse the suffix to get the next lexicographical state
        reverse(nums.begin() + i + 1, nums.end());
    }
};