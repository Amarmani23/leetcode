class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        
        vector<int> last(m + 1, -1);
        last[m] = n;
        
        int ptr = n - 1;
        for (int j = m - 1; j >= 0; j--) {
            while (ptr >= 0 && word1[ptr] != word2[j]) {
                ptr--;
            }
            last[j] = ptr;
            ptr--;
        }
        
        vector<int> ans;
        int w1_idx = 0;
        bool used_change = false;
        
        for (int i = 0; i < m; i++) {
            while (w1_idx < n) {
                bool is_match = (word1[w1_idx] == word2[i]);
                if (is_match || (!used_change && w1_idx < last[i + 1])) {
                    if (!is_match) {
                        used_change = true;
                    }
                    ans.push_back(w1_idx);
                    w1_idx++;
                    break;
                }
                
                w1_idx++;
            }
        }
        
        if (ans.size() == m) {
            return ans;
        }
        return {};
    }
};