/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr){
            return "N,";
        }
        string result=to_string(root->val)+",";
        result+=serialize(root->left);
        result+=serialize(root->right);
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string>q;
        stringstream ss(data);
        string item;
        while(getline(ss,item,',')){
            q.push(item);
        }
        return buildTree(q);
    }

private:
    TreeNode* buildTree(queue<string>&q){
        string curr=q.front();
        q.pop();

        if(curr=="N"){
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(curr));

        node->left=buildTree(q);
        node->right=buildTree(q);
        return node;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));