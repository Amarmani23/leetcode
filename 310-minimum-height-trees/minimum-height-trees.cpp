class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1){
            return {0};
        }
        vector<vector<int>>adj(n);
        vector<int>degree(n,0);
        for(auto e : edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }
        
        queue<int>leaves;
        for(int i=0;i<n;i++){
            if(degree[i]==1){
                leaves.push(i);
            }
        }
        int remainingNode=n;

        while(remainingNode>2){
            int leaveCount=leaves.size();
            remainingNode -= leaveCount;
            for(int i=0;i<leaveCount;i++){
                int curr=leaves.front();
                leaves.pop();
                
                for(int j=0;j<adj[curr].size();j++){
                    int neighbour=adj[curr][j];
                    degree[neighbour]--;
                    if(degree[neighbour]==1){
                        leaves.push(neighbour);
                    }
                }
            }
        }
        vector<int>ans;
        while(!leaves.empty()){
            ans.push_back(leaves.front());
            leaves.pop();
        }
        return ans;
    }
};