#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> result;
        std::vector<int> curr;

        // Step 1: Sort candidates to easily handle duplicate combinations
        std::sort(candidates.begin(), candidates.end());

        backtrack(candidates, target, result, curr, 0);
        return result;
    }

private:
    void backtrack(const std::vector<int>& candidates, int target, 
                   std::vector<std::vector<int>>& result, std::vector<int>& curr, int index) {
        
        // Base Case 1: Target reached
        if (target == 0) {
            result.push_back(curr);
            return;
        }

        // Branching
        for (int i = index; i < candidates.size(); ++i) {
            // Optimization: If current element exceeds target, remaining elements will too (since sorted)
            if (candidates[i] > target) {
                break;
            }

            // Skip duplicate elements at the same recursion depth
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }

            // Choose
            curr.push_back(candidates[i]);

            // Explore: Pass 'i + 1' so each element index is used at most once
            backtrack(candidates, target - candidates[i], result, curr, i + 1);

            // Backtrack
            curr.pop_back();
        }
    }
};