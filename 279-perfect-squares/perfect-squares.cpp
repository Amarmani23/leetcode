class Solution {
public:
    int numSquares(int n) {
        queue<pair<int,int>>q;
        q.push({n,0});

        vector<bool> visited(n + 1, false);
        visited[n] = true;
        while(!q.empty()){
            auto [current,step]=q.front();
            q.pop();
            for(int i=1;i*i<=current;i++){
                int remainder=current-i*i;
                if(remainder==0){
                    return step+1;
                }
                if(!visited[remainder]){
                    visited[remainder]=true;
                    q.push({remainder,step+1});
                }
            }
        }
        return 0;
    }
};