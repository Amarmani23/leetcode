class Solution {
public:
    string smallestPalindrome(string s, int k) {
        int n = s.length();
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        vector<int> half_freq(26, 0);
        char mid_char = '\0';
        int half_len = 0;

        for (int i = 0; i < 26; ++i) {
            if (freq[i] % 2 != 0) {
                mid_char = 'a' + i;
            }
            half_freq[i] = freq[i] / 2;
            half_len += half_freq[i];
        }

        // Helper to compute nCr capped at CAP = k + 1 to avoid overflow
        auto nCr = [&](int total, int r) -> long long {
            if (r < 0 || r > total) return 0;
            if (r == 0 || r == total) return 1;
            r = min(r, total - r);
            long long res = 1;
            long long cap = k + 1LL;

            for (int i = 1; i <= r; ++i) {
                res = res * (total - i + 1) / i;
                if (res >= cap) return cap;
            }
            return res;
        };

        // Calculates permutations of multiset: total! / (c1! * c2! * ... * c26!)
        // Computed as product of combinations: C(total, c1) * C(total - c1, c2) * ...
        auto countPermutations = [&](const vector<int>& counts) -> long long {
            long long res = 1;
            long long cap = k + 1LL;
            int rem = 0;
            for (int cnt : counts) rem += cnt;

            for (int cnt : counts) {
                if (cnt > 0) {
                    res = res * nCr(rem, cnt);
                    if (res >= cap) return cap;
                    rem -= cnt;
                }
            }
            return res;
        };

        // Check if there are at least k permutations
        if (countPermutations(half_freq) < k) {
            return "";
        }

        string left_half = "";

        // Construct left half character by character
        for (int i = 0; i < half_len; ++i) {
            for (int c = 0; c < 26; ++c) {
                if (half_freq[c] == 0) continue;

                half_freq[c]--;
                long long ways = countPermutations(half_freq);

                if (ways >= k) {
                    left_half += (char)('a' + c);
                    break;
                } else {
                    k -= ways;
                    half_freq[c]++; // Backtrack
                }
            }
        }

        string right_half = left_half;
        reverse(right_half.begin(), right_half.end());

        if (mid_char != '\0') {
            return left_half + mid_char + right_half;
        }
        return left_half + right_half;
    }
};