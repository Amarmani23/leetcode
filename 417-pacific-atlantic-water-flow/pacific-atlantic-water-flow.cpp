class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> result;
        if(heights.empty() || heights[0].empty()) return result;
        int m=heights.size();
        int n=heights[0].size();

        queue<pair<int,int>>pq;
        queue<pair<int,int>>aq;
        vector<vector<bool>>preachable(m,vector<bool>(n,false));
        vector<vector<bool>>areachable(m,vector<bool>(n,false));
        for(int r=0;r<m;r++){
            pq.push({r,0});
            preachable[r][0]=true;

            aq.push({r,n-1});
            areachable[r][n-1]=true;
        }
        for(int c=0;c<n;c++){
            pq.push({0,c});
            preachable[0][c]=true;

            aq.push({m-1,c});
            areachable[m-1][c]=true;
        }
        bfs(heights,pq,preachable);
        bfs(heights,aq,areachable);

        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(preachable[r][c] &&areachable[r][c]){
                    result.push_back({r,c});
                }
            }
        }
        return result;
    }
private:
    const std::vector<std::pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    void bfs(const std::vector<std::vector<int>>& heights, 
             std::queue<std::pair<int, int>>& q, 
             std::vector<std::vector<bool>>& reachable) {
        
        int rows = heights.size();
        int cols = heights[0].size();

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (const auto& [dr, dc] : directions) {
                int nr = r + dr;
                int nc = c + dc;

                // Check bounds
                if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
                
                // Skip if already visited
                if (reachable[nr][nc]) continue;
                 // Water flows UPWARD from ocean to land (neighbor must be >= current cell)
                if (heights[nr][nc] >= heights[r][c]) {
                    reachable[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }
};