// class Solution {
// public:
//     int calculate(string s) {
//         stack<int>st;
//         int n=s.length();
//         long long num=0;
//         long long result=0;
//         int sign=1;
//         for(int i=0;i<n;i++){
//             if(isdigit(s[i])){
//                 num=num*10+(s[i]-'0');
//             }else if(s[i]=='+'){
//                 result+=num*sign;
//                 num=0;
//                 sign=1;
//             }else if(s[i]=='-'){
//                 result+=num*sign;
//                 num=0;
//                 sign=-1;
//             }else if(s[i]=='('){
//                 st.push(result);
//                 st.push(sign);
//                 result=0;
//                 sign =1;
//                 num=0;
//             }else if(s[i]==')'){
//                 result+=num*sign;
//                 num=0;
//                 int st_sign=st.top();
//                 st.pop();
//                 int prev_result=st.top();
//                 st.pop();
//                 result*=st_sign;
//                 result+=prev_result;

//             }
//         }
//         result+=(num*sign);
//         return (int)result;
//     }
// };

// by recursion-----------------------------

class Solution {
public:
    int calculate(string s) {
        int i = 0; // The global pointer passed by reference
        return helper(s, i);
    }

private:
    int helper(string& s, int& i) {
        long long num = 0;
        long long result = 0;
        int sign = 1;

        while (i < s.length()) {
            char c = s[i];

            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } 
            else if (c == '+') {
                result += num * sign;
                num = 0;
                sign = 1;
            } 
            else if (c == '-') {
                result += num * sign;
                num = 0;
                sign = -1;
            } 
            else if (c == '(') {
                i++; // Skip '('
                // Recursively solve the inner expression
                num = helper(s, i); 
            } 
            else if (c == ')') {
                // End of current sub-expression
                result += num * sign;
                return (int)result;
            }
            i++; // Move to next character
        }

        result += num * sign;
        return (int)result;
    }
};
