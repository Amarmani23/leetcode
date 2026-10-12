class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<vector<int>>adj(n);
        vector<int>answer(n);
        vector<int>InDegree(n,0);

        for(int i = 0 ;i < n;i++){
            answer[i]=i;
        }
        for(const auto& rel : richer){
            int u=rel[0];
            int v=rel[1];
            adj[u].push_back(v);
            InDegree[v]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(InDegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(int poorer : adj[curr]){
                int candidate=answer[curr];
                if(quiet[candidate]<quiet[answer[poorer]]){
                    answer[poorer]=candidate;
                }
                InDegree[poorer]--;
                if(InDegree[poorer]==0){
                    q.push(poorer);
                }
            }
        }
        return answer;
    }
};