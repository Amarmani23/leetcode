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
// class Solution {
// public:
//     int kthSmallest(TreeNode* root, int k) {
//         stack<TreeNode*>st;
//         TreeNode* curr=root;
//         while(curr!=nullptr || !st.empty()){
//             while(curr!=nullptr){
//                 st.push(curr);
//                 curr=curr->left;
//             }
//             curr=st.top();
//             st.pop();
//             k--;
//             if(k==0){
//                 return curr->val;
//             }
//             curr=curr->right;
//         }
//         return -1;
//     }
// };
class Solution {
public:
    
    int kthSmallest(TreeNode* root, int k) {
        int res=-1;
        dfs(root,k,res);
        return res;
    }
private:
    void dfs(TreeNode* root,int &k,int &res){
        if(root==nullptr || k<=0) return ;
        dfs(root->left,k,res);
        k--;
        if(k==0){
            res=root->val;
            return;
        }
        dfs(root->right,k,res);
        
    }
};