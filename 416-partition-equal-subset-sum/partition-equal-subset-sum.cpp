class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total=0;
        for(auto &it: nums){
            total+=it;
        }
        if(total&1){
            return false;
        }
        
        vector<vector<int>>dp(nums.size()+1,vector<int>(total+1,-1));
        return rec(nums,0,0,total,dp);
    }
private:
    bool rec(vector<int>& nums,int idx,int val,int &total,vector<vector<int>>&dp){
        if(idx==nums.size() ){
            return val==total/2;
        }
        if(dp[idx][val]!=-1){
            return dp[idx][val];
        }
        //not-taken
        bool notTake=rec(nums,idx+1,val,total,dp);

        //taken
        bool take=rec(nums,idx+1,val+nums[idx],total,dp);

        return dp[idx][val]=notTake || take;
    }
};