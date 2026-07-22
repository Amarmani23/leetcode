class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();

        if(k>=m+n-2){
            return m+n-2;
        }

        vector<vector<int>> max_k(m,vector<int>(n,-1));

        queue<vector<int>>q;
        q.push({0,0,k});
        max_k[0][0]=k;

        int step=0;
        vector<int>dirs={-1,0,1,0,-1};

        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto curr=q.front();
                q.pop();

                int r= curr[0];
                int c =curr[1];
                int rem_k =curr[2];

                if(r==m-1 && c==n-1){
                    return step;
                }
                for(int i=0;i<4;i++){
                    int nr=r +dirs[i];
                    int nc=c+dirs[i+1];
                    if(nr>=0 && nr<m &&nc>=0 && nc<n){
                        int next_k = rem_k - grid[nr][nc];
                        if(next_k >=0 && next_k >max_k[nr][nc]){
                            max_k[nr][nc] = next_k;
                            q.push({nr,nc,next_k});
                        }
                    }
                }
            }
            step++;
        }
        return -1;

    }

};