class Solution {
public:
    int longestValidParentheses(string s) {
        std::stack<int> st;
        st.push(-1); // Base index boundary
        int maxLength = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    // Current ')' acts as a new boundary
                    st.push(i);
                } else {
                    // Valid substring length = current index - top of stack
                    maxLength = std::max(maxLength, i - st.top());
                }
            }
        }

        return maxLength;
    }
};