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
    bool isSymmetric(TreeNode* root) {
        // An empty tree is always symmetric
        if (!root) return true;
        
        // Compare the left subtree and the right subtree
        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        // Base case: both nodes are null, meaning they match perfectly
        if (!t1 && !t2) return true;
        
        // If only one node is null, or their values don't match, they aren't mirrors
        if (!t1 || !t2) return false;
        if (t1->val != t2->val) return false;
        
        // Recursively check:
        // 1. Left child of t1 vs Right child of t2
        // 2. Right child of t1 vs Left child of t2
        return isMirror(t1->left, t2->right) && isMirror(t1->right, t2->left);
    }
};