// class Solution {
// public:
//     bool isValid(int x,int y,int n,vector<vector<int>>& grid,vector<vector<bool>>&vis){
//         return (x>=0 && x<n && y>=0 && y<n and grid[x][y]==0 && !vis[x][y]);
//     }
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//         int n=grid.size();
//         if(grid[0][0]==1 || grid[n-1][n-1]) return -1;
//         if(n==1) return 1;


//         int dr[]={-1,-1,0,1,1,1,0,-1};
//         int dy[]={0,1,1,1,0,-1,-1,-1};
//         queue<pair<pair<int,int>,int>>q;
//         vector<vector<bool>>vis(n,vector<bool>(n,false));
//         q.push({{0,0},1});
//         vis[0][0]=true;
//         while(!q.empty()){
//             auto cell=q.front().first;
//             int length=q.front().second;
//             q.pop();
//             if(cell.first==n-1 && cell.second==n-1){
//                 return length;
//             }
//             for(int i =0;i<8;i++){
//                 int newx=cell.first+dr[i];
//                 int newy=cell.second+dy[i];
//                 if(isValid(newx,newy,n,grid,vis)){
//                     vis[newx][newy]=true;
//                     q.push({{newx,newy},length+1});
//                 }
//             }
//         }
//         return -1;
//     }
// };


//reduciing space complexity;

class Solution {
public:
    bool isValid(int x,int y,int n,vector<vector<int>>& grid){
        return (x>=0 && x<n && y>=0 && y<n and grid[x][y]==0);
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]) return -1;
        if(n==1) return 1;

        
        int dr[]={-1,-1,0,1,1,1,0,-1};
        int dy[]={0,1,1,1,0,-1,-1,-1};
        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},1});
        grid[0][0]=1;
        while(!q.empty()){
            auto cell=q.front().first;
            int length=q.front().second;
            q.pop();
            if(cell.first==n-1 && cell.second==n-1){
                return length;
            }
            for(int i =0;i<8;i++){
                int newx=cell.first+dr[i];
                int newy=cell.second+dy[i];
                if(isValid(newx,newy,n,grid)){
                    grid[newx][newy]=1;
                    q.push({{newx,newy},length+1});
                }
            }
        }
        return -1;
    }
};