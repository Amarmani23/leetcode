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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int leftheight=minDepth(root->left);
        int rightheight=minDepth(root->right);
        if(leftheight && !rightheight || !leftheight && rightheight){
            return max(leftheight,rightheight)+1;
        }
        return min(leftheight,rightheight)+1;

    }
    
};