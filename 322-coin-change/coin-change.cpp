class Solution {
public:
    // int solveMem(vector<int>& coins, vector<int>& dp, int x) {
    //     // Base case
    //     if (x == 0)
    //         return 0;

    //     if (x < 0)
    //         return INT_MAX;

    //     // Memoization
    //     if (dp[x] != -1)
    //         return dp[x];

    //     int mini = INT_MAX;

    //     for (int i = 0; i < coins.size(); i++) {
    //         int ans = solveMem(coins, dp, x - coins[i]);

    //         if (ans != INT_MAX) {
    //             mini = min(mini, 1 + ans);
    //         }
    //     }

    //     dp[x] = mini;
    //     return dp[x];
    // }

    int solveTab(vector<int>coins,int x){
        vector<int>dp(x+1,INT_MAX);
        dp[0]=0;
        for(int i=0;i<=x;i++){
            for(int j=0;j<coins.size();j++){
                if(i-coins[j] >=0 && dp[i-coins[j]] != INT_MAX){
                    dp[i]=min(dp[i],1+dp[i-coins[j]]);
                }
                
            }
        }
        if(dp[x]==INT_MAX)return -1;

        return dp[x];
    }

    int coinChange(vector<int>& coins, int amount) {
        // vector<int> dp(amount + 1, -1);

        // int ans = solveMem(coins, dp, amount);

        // return (ans == INT_MAX) ? -1 : ans;

        return solveTab(coins,amount);
    }
};