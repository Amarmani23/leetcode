class Solution {
public:
    bool isMatch(string s, string p) {
       int sIdx = 0, pIdx = 0;
        int starIdx = -1, sTmpIdx = -1;
        int n = s.length(), m = p.length();

        while (sIdx < n) {
            // Case 1: Direct character match OR '?' match
            if (pIdx < m && (p[pIdx] == '?' || p[pIdx] == s[sIdx])) {
                sIdx++;
                pIdx++;
            }
            // Case 2: Encountered '*' in pattern
            else if (pIdx < m && p[pIdx] == '*') {
                starIdx = pIdx;
                sTmpIdx = sIdx;
                pIdx++; // Assume '*' matches 0 characters first
            }
            // Case 3: Mismatch after a previous '*', backtrack!
            else if (starIdx != -1) {
                pIdx = starIdx + 1;
                sTmpIdx++;
                sIdx = sTmpIdx; // Make '*' match one more char from s
            }
            // Case 4: Mismatch with no preceding '*'
            else {
                return false;
            }
        }

        // Skip remaining '*' in pattern
        while (pIdx < m && p[pIdx] == '*') {
            pIdx++;
        }

        return pIdx == m;
    }
};