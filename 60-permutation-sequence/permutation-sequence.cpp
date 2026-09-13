// class Solution {
// public:
//     // 1. Pass 'curr' by reference so it persists across calls
//     // 2. Pass a 'result' string by reference to capture the final answer
//     void solve(int n, int k, vector<bool>& visited, string& curr, int& count, string& result) {
//         // FIX 1: Base case checks against 'n', not 'k'
//         if (curr.size() == n) {
//             count++;
//             if (count == k) {
//                 result = curr; // Save the successful permutation
//             }
//             return;
//         }

//         for (int i = 1; i <= n; i++) {
//             if (!visited[i]) {
//                 // Early exit if we already found the k-th permutation
//                 if (count == k) return;

//                 visited[i] = true;
//                 curr.push_back('0' + i);
                
//                 solve(n, k, visited, curr, count, result);
                
//                 curr.pop_back(); // Backtrack
//                 visited[i] = false;
//             }
//         }
//     }

//     string getPermutation(int n, int k) {
//         int count = 0;
//         vector<bool> visited(n + 1, false);
//         string curr = "";
//         string result = "";
        
//         solve(n, k, visited, curr, count, result);
//         return result;
//     }
// };


//Mathematical Approch ----------------------
class Solution{
    public:
        void solve(int n,int k,vector<int>&fact,vector<int>&num,string &ans){
            if(num.empty()) return;
            int blocksize=fact[n-1];
            int index=k/blocksize;
            ans+=to_string(num[index]);
            num.erase(num.begin()+index);
            k=k%blocksize;
            solve(n-1,k,fact,num,ans);
        }
        string getPermutation(int n, int k) {
            string ans="";
            vector<int>fact(n+1,1);
            vector<int>num;
            for(int i=1;i<=n;i++){
                fact[i]=fact[i-1]*i;
                num.push_back(i);
            }
            k=k-1;
            solve(n,k,fact,num,ans);
            return ans;
        }

};