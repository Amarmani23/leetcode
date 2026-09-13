class Solution {
public:
    // 1. Pass 'curr' by reference so it persists across calls
    // 2. Pass a 'result' string by reference to capture the final answer
    void solve(int n, int k, vector<bool>& visited, string& curr, int& count, string& result) {
        // FIX 1: Base case checks against 'n', not 'k'
        if (curr.size() == n) {
            count++;
            if (count == k) {
                result = curr; // Save the successful permutation
            }
            return;
        }

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                // Early exit if we already found the k-th permutation
                if (count == k) return;

                visited[i] = true;
                curr.push_back('0' + i);
                
                solve(n, k, visited, curr, count, result);
                
                curr.pop_back(); // Backtrack
                visited[i] = false;
            }
        }
    }

    string getPermutation(int n, int k) {
        int count = 0;
        vector<bool> visited(n + 1, false);
        string curr = "";
        string result = "";
        
        solve(n, k, visited, curr, count, result);
        return result;
    }
};
