class Solution {
public:

    // int solve(vector<int>&nums,int n){
    //     if(n<0) return 0;
    //     if(n==0) return nums[0];
    //     int incl=solve(nums,n-2)+nums[n];
    //     int excl=solve(nums,n-1)+0;

    //     return max(incl,excl);
    // }


    // int solveMem(vector<int>&nums,vector<int>&dp,int n){
    //     if(n<0) return 0;
    //     if(n==0) return nums[0];

    //     if(dp[n]!=-1){
    //         return dp[n];
    //     }

    //     int incl=solveMem(nums,dp,n-2)+nums[n];
    //     int excl=solveMem(nums,dp,n-1)+0;

    //     dp[n]= max(incl,excl);
    //     return dp[n];
    // }

   int solveTab(vector<int>& nums) {
    int n = nums.size();

    if(n == 0)
        return 0;

    vector<int> dp(n, 0);

    dp[0] = nums[0];

    for(int i = 1; i < n; i++) {

        int incl = nums[i];

        if(i > 1)
            incl += dp[i-2];

        int excl = dp[i-1];

        dp[i] = max(incl, excl);
    }

    return dp[n-1];
}

    int rob(vector<int>& nums) {
        // int n=nums.size();
        // int ans=solve(nums,n-1);
        // return ans;

        //recurssion + memorization(dp)
        // int n=nums.size();
        // vector<int>dp(n+1,-1);
        // return solveMem(nums,dp,n-1);
        
        return solveTab(nums);
    }
};