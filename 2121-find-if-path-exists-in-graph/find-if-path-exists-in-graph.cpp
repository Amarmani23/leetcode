//by adjecency matrix

// class Solution {
//     // bool dfs(vector<vector<bool>>&graph ,int src,int dest,vector<bool>&vis,int n){
//     //     if(src==dest) return true;
//     //     vis[src]=true;
//     //     for(int i=0;i<n;i++){
//     //         if(graph[src][i] && !vis[i]){
//     //             if(dfs(graph,i,dest,vis,n)){
//     //                 return true;
//     //             }
//     //         }
//     //     }
//     //     return false;
//     // }
    
//     bool bfs(vector<vector<bool>>&graph ,int src,int dest,vector<bool>&vis,int n){
//         queue<int>q;
//         q.push(src);
//         vis[src]=true;
//         while(!q.empty()){
//             int curr=q.front();
//             q.pop();
//             if(curr==dest) return true;
//             for(int i=0;i<n;i++){
//                 if(graph[curr][i] && !vis[i]){
//                     q.push(i);
//                     vis[i]=true;
//                 }
//             }

//         }
//         return false;
//     }
    

// public:
//     bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
//         vector<vector<bool>>graph(n,vector<bool>(n,false));

//         for(auto edge:edges){
//             int u=edge[0],v=edge[1];
//             graph[u][v]=true;
//             graph[v][u]=true;
//         }
//         vector<bool>vis(n,false);
//         // return dfs(graph,source,destination,vis,n);
//         return bfs(graph,source,destination,vis,n);
        
//     }
// };

//by adjecency list
class Solution{
        bool dfs(unordered_map<int,vector<int>>&graph,int src,int dest,vector<bool>&vis,int n){
            if(src==dest) return true;
            vis[src]=true;
            for(auto neighbour:graph[src]){
                if(!vis[neighbour]){
                    if(dfs(graph,neighbour,dest,vis,n)){
                        return true;
                    }
                }
            }
            return false;
        }
    public:
        bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
            unordered_map<int,vector<int>>graph;
            for(auto edge:edges){
                int u=edge[0],v=edge[1];
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
            vector<bool>vis(n,false);
            return dfs(graph,source,destination,vis,n);
        }

};