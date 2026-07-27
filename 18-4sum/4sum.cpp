class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        if (n < 4) return result;

        // 1. Sort the array
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; i++) {
            // Skip duplicate values for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Early Pruning for i
            long long minSumI = (long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3];
            if (minSumI > target) break; // Smallest possible sum is too big
            
            long long maxSumI = (long long)nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3];
            if (maxSumI < target) continue; // Largest possible sum is too small

            for (int j = i + 1; j < n - 2; j++) {
                // Skip duplicate values for the second element
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                // Early Pruning for j
                long long minSumJ = (long long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2];
                if (minSumJ > target) break;
                
                long long maxSumJ = (long long)nums[i] + nums[j] + nums[n - 1] + nums[n - 2];
                if (maxSumJ < target) continue;

                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    long long currentSum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (currentSum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        left++;
                        right--;

                        // Skip duplicate values for left and right pointers
                        while (left < right && nums[left] == nums[left - 1]) left++;
                        while (left < right && nums[right] == nums[right + 1]) right--;
                    } 
                    else if (currentSum < target) {
                        left++;
                    } 
                    else {
                        right--;
                    }
                }
            }
        }

        return result;
    }
    
};