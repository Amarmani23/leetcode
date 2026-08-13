class Solution {
public:
    private:
    struct Node {
        int max_len;
        int prefix_len;
        int suffix_len;
        char prefix_char;
        char suffix_char;
    };

    vector<Node> tree;
    string s;

    Node merge(const Node& left, const Node& right, int left_len, int right_len) {
        Node res;
        res.prefix_char = left.prefix_char;
        res.suffix_char = right.suffix_char;

        // Merge prefix length
        res.prefix_len = left.prefix_len;
        if (left.prefix_len == left_len && left.prefix_char == right.prefix_char) {
            res.prefix_len += right.prefix_len;
        }

        // Merge suffix length
        res.suffix_len = right.suffix_len;
        if (right.suffix_len == right_len && right.suffix_char == left.suffix_char) {
            res.suffix_len += left.suffix_len;
        }

        // Merge max length
        res.max_len = max(left.max_len, right.max_len);
        if (left.suffix_char == right.prefix_char) {
            res.max_len = max(res.max_len, left.suffix_len + right.prefix_len);
        }

        return res;
    }

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node] = {1, 1, 1, s[start], s[start]};
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1], mid - start + 1, end - mid);
    }

    void update(int node, int start, int end, int idx, char ch) {
        if (start == end) {
            tree[node] = {1, 1, 1, ch, ch};
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, ch);
        } else {
            update(2 * node + 1, mid + 1, end, idx, ch);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1], mid - start + 1, end - mid);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        this->s = s;
        int n = s.length();
        int k = queryIndices.size();

        tree.resize(4 * n);
        build(1, 0, n - 1);

        vector<int> result(k);
        for (int i = 0; i < k; ++i) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            result[i] = tree[1].max_len;
        }

        return result;
    }
};