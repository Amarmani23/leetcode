class Solution {
public:
    bool isValid(int x,int y,int m,int n){
        return (x<m && x>=0 && y<n&&y>=0);
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int m=matrix.size();
        int n=matrix[0].size();
        int x[]={0,-1,0,1};
        int y[]={-1,0,1,0};
        vector<vector<int>>outDegree(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<4;k++){
                    int ni=i+x[k];
                    int nj=j+y[k];
                    if(isValid(ni,nj,m,n) && matrix[ni][nj] > matrix[i][j]){
                        outDegree[i][j]++;
                    }
                }
                if(outDegree[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        int maxLen=0;
        while(!q.empty()){
            int size= q.size();
            maxLen++;
            for(int k=0;k<size;k++){
                auto[i,j]=q.front();
                q.pop();
                for(int l=0;l<4;l++){
                    int ni=i+x[l];
                    int nj=j+y[l];
                    if(isValid(ni,nj,m,n) && matrix[ni][nj]< matrix[i][j]){
                        outDegree[ni][nj]--;
                        if(outDegree[ni][nj]==0){
                            q.push({ni,nj});
                        }
                    }
                }
            }
        }
        return maxLen;

    }
};