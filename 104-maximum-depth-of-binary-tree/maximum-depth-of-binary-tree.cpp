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
    // int maxDepth(TreeNode* root) {
    //     if(!root) return 0;
        
    //     int left=maxDepth(root->left);
    //     int right=maxDepth(root->right);
    //     return 1 + max(left,right);
    
    // }

// ITERATIVE APPROCH
//BFS
    int maxDepth(TreeNode* root){
        if(!root) return 0;
        int depth=0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            depth++;
            int levelsize=q.size();
           
            for(int i=0;i<levelsize;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        return depth;
    }
};