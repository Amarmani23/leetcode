class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int>adj[n];
        for(auto & inv: invocations){
            adj[inv[0]].push_back(inv[1]);
        }
        vector<bool>isSuspicious(n,false);
        queue<int>q;
        q.push(k);
        isSuspicious[k]=true;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(int qr:adj[curr]){
                if(!isSuspicious[qr]){
                    isSuspicious[qr]=true;
                    q.push(qr);
                }

            }
        }
        for(auto &inv:invocations){
            int u=inv[0];
            int v=inv[1];
            if(!isSuspicious[u] && isSuspicious[v]){
                vector<int>allmethod(n);
                iota(allmethod.begin(),allmethod.end(),0);
                return allmethod;
            }
        }
        vector<int>result;
        for(int i=0;i<n;i++){
            if(!isSuspicious[i]){
                result.push_back(i);
            }
        }
        return result;
    }
};