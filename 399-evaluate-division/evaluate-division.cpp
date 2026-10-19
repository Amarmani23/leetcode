class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>>graph;
        for(int i = 0; i < equations.size();i++){
            string u = equations[i][0];
            string v= equations[i][1];
            double val = values[i];
            graph[u].push_back({v,val});
            graph[v].push_back({u,1.0/val});
        }
        vector<double>result;
        for(const auto &query:queries){
            string start = query[0];
            string target = query[1];
            if(graph.find(start) == graph.end() || graph.find(target) == graph.end()){
                result.push_back(-1.0);
                continue;
            }
            if(start == target){
                result.push_back(1.0);
                continue;
            }
            result.push_back(bfs(start, target,graph));
        }
        return result;
    }
private: 
    double bfs(const string &start,const string&target,unordered_map<string,vector<pair<string,double>>>&graph){
        queue<pair<string,double>>q;
        unordered_set<string>visited;
        q.push({start,1.0});
        visited.insert(start);
        while(!q.empty()){
            auto [curr,prod]=q.front();
            q.pop();
            if(curr==target) return prod;
            for(const auto &neighbor:graph[curr]){
                string next_node=neighbor.first;
                double edge_weight=neighbor.second;
                if(visited.find(next_node)==visited.end()){
                    visited.insert(next_node);
                    q.push({next_node,edge_weight*prod});
                }
            }
        }
        return -1.0;
    }
};