// class Solution {
// public:
//     bool canPartition(vector<int>& nums) {
//         int total=0;
//         for(auto &it: nums){
//             total+=it;
//         }
//         if(total&1){
//             return false;
//         }
        
//         vector<vector<int>>dp(nums.size()+1,vector<int>(total+1,-1));
//         return rec(nums,0,0,total,dp);
//     }
// private:
//     bool rec(vector<int>& nums,int idx,int val,int &total,vector<vector<int>>&dp){
//         if(idx==nums.size() ){
//             return val==total/2;
//         }
//         if(dp[idx][val]!=-1){
//             return dp[idx][val];
//         }
//         //not-taken
//         bool notTake=rec(nums,idx+1,val,total,dp);

//         //taken
//         bool take=rec(nums,idx+1,val+nums[idx],total,dp);

//         return dp[idx][val]=notTake || take;
//     }
// };


// class Solution {
// public:
//     bool canPartition(vector<int>& nums) {
//         int total = 0;
//         for (int num : nums) {
//             total += num;
//         }
        
//         // If the total sum is odd, we cannot split it into two equal integer subsets
//         if (total & 1) return false; 
        
//         int target = total / 2;
//         int n = nums.size();
        
//         // dp[i][j] stores whether a sum of j can be formed using the first i elements
//         vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        
//         // Base case: A sum of 0 can always be formed (by picking an empty subset)
//         for (int i = 0; i <= n; i++) {
//             dp[i][0] = true;
//         }
        
//         // Fill the DP table iteratively
//         for (int i = 1; i <= n; i++) {
//             for (int j = 1; j <= target; j++) {
//                 // Option 1: Do not take the current element
//                 bool notTake = dp[i - 1][j];
                
//                 // Option 2: Take the current element (if its value doesn't exceed the target sum j)
//                 bool take = false;
//                 if (nums[i - 1] <= j) {
//                     take = dp[i - 1][j - nums[i - 1]];
//                 }
                
//                 dp[i][j] = notTake || take;
//             }
//         }
        
//         return dp[n][target];
//     }
// };



class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int num : nums) total += num;
        if (total & 1) return false;
        
        int target = total / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true; // Base case
        
        for (int num : nums) {
            // Traverse backwards to prevent using the same element multiple times
            for (int j = target; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }
        return dp[target];
    }
};
