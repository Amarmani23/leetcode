class Solution {
public:
    bool Cycle(int node,vector<int>&state,vector<vector<int>>& graph){
        state[node]=1;
        for(int neighbour:graph[node]){
            if(state[neighbour]==1){
                return true;
            }
            if(state[neighbour]==0 && Cycle(neighbour,state,graph)){
                return true;

            }
        }
        state[node]=2;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();

        vector<int>state(n,0);
        vector<int>safe;
        for(int i=0;i<n;i++){
            if(!state[i]){
                Cycle(i,state,graph);
            }
        }
        for(int j=0;j<n;j++){
            if(state[j]==2){
                safe.push_back(j);
            }

        }
        return safe;
    }
};