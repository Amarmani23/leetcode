class Solution {
public:
    bool winnerSquareGame(int n) {
        std::vector<bool> dp(n + 1, false);
        
        // Build the dp table from 1 to n
        for (int i = 1; i <= n; ++i) {
            for (int k = 1; k * k <= i; ++k) {
                // If we can force the opponent into a losing state, we win
                if (!dp[i - k * k]) {
                    dp[i] = true;
                    break; // No need to check other moves for this i
                }
            }
        }
        
        return dp[n];
    }
};