#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if (m == 0) return 0;
        int n = heightMap[0].size();
        if (n == 0) return 0;

        // Min-heap to store: {height, {row, col}}
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> minHeap;
        
        // Visited array to keep track of processed cells
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // 1. Push all boundary cells into the min-heap
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    minHeap.push({heightMap[i][j], {i, j}});
                    visited[i][j] = true;
                }
            }
        }

        int totalWater = 0;
        // Direction vectors for moving Up, Down, Left, Right
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        // 2. Process cells using Priority Queue BFS
        while (!minHeap.empty()) {
            auto curr = minHeap.top();
            minHeap.pop();

            int currHeight = curr.first;
            int r = curr.second.first;
            int c = curr.second.second;

            // Explore 4 neighbors
            for (int i = 0; i < 4; ++i) {
                int nr = r + dirs[i][0];
                int nc = c + dirs[i][1];

                // Ensure neighbor is within grid bounds and not visited
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = true;

                    // If neighbor is lower than the current boundary height, trap water
                    if (heightMap[nr][nc] < currHeight) {
                        totalWater += currHeight - heightMap[nr][nc];
                    }

                    // Push neighbor with the updated boundary level
                    minHeap.push({max(heightMap[nr][nc], currHeight), {nr, nc}});
                }
            }
        }

        return totalWater;
    }
};
