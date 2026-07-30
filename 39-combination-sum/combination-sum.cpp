class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int>curr;
        backtrack(candidates,result,curr,target,0);
        return result;
    }
private:
    void backtrack(vector<int>& candidates, vector<vector<int>>& result, vector<int>& curr, int target, int index) {
        if (target == 0) {
            result.push_back(curr);
            return;
        }
        if (target < 0) return; // Base case stopping condition

        for (int i = index; i < candidates.size(); ++i) {
            curr.push_back(candidates[i]);
            // Subtract candidates[i] directly -> O(1) state transition
            backtrack(candidates, result, curr, target - candidates[i], i);
            curr.pop_back();
        }
    }
};