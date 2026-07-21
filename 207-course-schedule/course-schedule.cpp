class Solution {
public:
    // Returns true if a cycle is found, false otherwise
    bool DetectCycle(int node, unordered_map<int, vector<int>>& course, vector<int>& vis, vector<int>& visiting){
        vis[node] = 1;
        visiting[node] = 1;
        
        for(int j = 0; j < course[node].size(); j++){
            int neighbor = course[node][j];
            if(visiting[neighbor]) {
                return true; // Cycle found
            }
            if(!vis[neighbor] && DetectCycle(neighbor, course, vis, visiting)) {
                return true; // Cycle found deeper in recursion
            }
        }
        
        visiting[node] = 0;
        return false; // No cycle found along this path
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> course;
        
        // CONCEPTUAL FIX: Map bi -> ai because bi must be taken before ai
        for(auto p : prerequisites){
            int ai = p[0];
            int bi = p[1];
            course[bi].push_back(ai); 
        }
        
        vector<int> vis(numCourses, 0);
        vector<int> visiting(numCourses, 0);
        
        for(int i = 0; i < numCourses; i++){
            // If a cycle is detected anywhere, it's impossible to finish
            if(!vis[i] && DetectCycle(i, course, vis, visiting)){
                return false;
            }
        }
        return true;
    }
};
