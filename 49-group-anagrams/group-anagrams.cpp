class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramMap;
        
        for (const string& str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            anagramMap[key].push_back(str);
        }
        
        vector<vector<string>> result;
        result.reserve(anagramMap.size());
        
        for (auto& pair : anagramMap) {
            result.push_back(move(pair.second));
        }
        
        return result;
    }
};