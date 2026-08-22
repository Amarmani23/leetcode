// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
        
//         return rec(nums,0,0,target);
//     }
// private:
//     int rec(vector<int>& nums,int sum,int idx,int &target){
//         if(idx==nums.size()){
//             return sum == target ? 1:0;
//         }
//         int pos=rec(nums,sum+nums[idx],idx+1,target);
//         int neg = rec(nums,sum-nums[idx],idx+1,target);
//         return pos+neg;
//     }
// };
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalsum=0;
        for(auto &s:nums) totalsum+=s;

        vector<vector<int>>dp(nums.size(),vector<int>(2*totalsum+1,-1));
        return rec(nums,0,0,target,totalsum,dp);
    }
private:
    int rec(vector<int>& nums,int sum,int idx,int &target,int offset,vector<vector<int>>&dp){
        if(idx==nums.size()){
            return sum == target ? 1:0;
        }
        int colidx=sum+offset;
        if(dp[idx][colidx]!=-1) return dp[idx][colidx];
        int pos=rec(nums,sum+nums[idx],idx+1,target,offset,dp);
        int neg = rec(nums,sum-nums[idx],idx+1,target,offset,dp);
        return dp[idx][colidx]=pos+neg;
    }
};