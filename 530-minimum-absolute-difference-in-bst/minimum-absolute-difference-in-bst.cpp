/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        if (!root) return 0;
        
        vector<int> vals;
        queue<TreeNode*> q;
        q.push(root);
        
        // Step 1: Collect all node values using BFS
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            vals.push_back(curr->val);
            
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        
        // Step 2: Sort the values
        sort(vals.begin(), vals.end());
        
        // Step 3: Find the minimum difference between adjacent elements
        int minDiff = INT_MAX;
        for (size_t i = 1; i < vals.size(); ++i) {
            minDiff = min(minDiff, vals[i] - vals[i - 1]);
        }
        
        return minDiff;
    }
};

