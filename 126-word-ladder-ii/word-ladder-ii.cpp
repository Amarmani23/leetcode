class Solution {
private:
    unordered_map<string, int> distance; // Stores minimum steps from beginWord to any word
    vector<vector<string>> result;

    void dfs(string& currentWord, const string& beginWord, vector<string>& currentPath) {
        if (currentWord == beginWord) {
            auto path = currentPath;
            reverse(path.begin(), path.end()); // Reverse to get correct order from begin to end
            result.push_back(path);
            return;
        }

        int currDist = distance[currentWord];
        string temp = currentWord;
        
        // Generate neighbors by changing one character at a time
        for (int i = 0; i < temp.size(); i++) {
            char originalChar = temp[i];
            for (char c = 'a'; c <= 'z'; c++) {
                temp[i] = c;
                
                // Backtrack only to words that are exactly one step closer to the beginWord
                if (distance.count(temp) && distance[temp] == currDist - 1) {
                    currentPath.push_back(temp);
                    dfs(temp, beginWord, currentPath);
                    currentPath.pop_back(); // Backtrack
                }
            }
            temp[i] = originalChar;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return {};

        // Step 1: BFS to find the shortest distance from beginWord to all reachable words
        queue<string> q;
        q.push(beginWord);
        distance[beginWord] = 1; 

        bool foundEnd = false;

        while (!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; k++) {
                string currentWord = q.front();
                q.pop();

                if (currentWord == endWord) {
                    foundEnd = true;
                    break; 
                }

                string temp = currentWord;
                for (int i = 0; i < temp.size(); i++) {
                    char originalChar = temp[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        temp[i] = c;
                        
                        // If it's a valid word and hasn't been visited yet
                        if (wordSet.count(temp) && !distance.count(temp)) {
                            distance[temp] = distance[currentWord] + 1;
                            q.push(temp);
                        }
                    }
                    temp[i] = originalChar;
                }
            }
            if (foundEnd) break; // Stop exploring deeper levels once endWord is reached
        }

        // If the endWord was never reached, no path exists
        if (!foundEnd) return {};

        // Step 2: DFS Backtracking from endWord to beginWord to construct paths
        vector<string> currentPath = {endWord};
        dfs(endWord, beginWord, currentPath);

        return result;
    }
};
