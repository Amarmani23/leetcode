class Solution {
public:
    bool dfs(int node,vector<vector<int>> &graph,vector<int>&state,vector<int>&ans){
        if(state[node]==1) return false;
        if(state[node]==2) return true;
        state[node]=1;
        for(auto neighbbour:graph[node]){
            if(!dfs(neighbbour,graph,state,ans)){
                return false;
            }
        }
        state[node]=2;
        ans.push_back(node);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        for(const auto &p:prerequisites){
            graph[p[0]].push_back(p[1]);
        }
        vector<int>ans;
        vector<int>state(numCourses);
        for(int i=0;i<numCourses;i++){
            if(state[i]==0){
                if(!dfs(i,graph,state,ans)){
                    return {};
                }
            }
        }
        return ans;

    }
};