class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Place each number x at index x - 1 if 1 <= x <= n
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        // Step 2: Find the first index where nums[i] != i + 1
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        // Step 3: If 1 to n are all present
        return n + 1;
    }
};