/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        vector<vector<int>>result;
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>currentLevel;
            for(int i=0;i<size;i++){
                auto node=q.front();
                q.pop();
                currentLevel.push_back(node->val);
                for(auto child : node->children){
                    if(child != NULL){
                        q.push(child);
                    }
                }
            }
            result.push_back(currentLevel);

        }
        return result;
    }
};