class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        int n=s.length();
        long long num=0;
        long long result=0;
        int sign=1;
        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                num=num*10+(s[i]-'0');
            }else if(s[i]=='+'){
                result+=num*sign;
                num=0;
                sign=1;
            }else if(s[i]=='-'){
                result+=num*sign;
                num=0;
                sign=-1;
            }else if(s[i]=='('){
                st.push(result);
                st.push(sign);
                result=0;
                sign =1;
                num=0;
            }else if(s[i]==')'){
                result+=num*sign;
                num=0;
                int st_sign=st.top();
                st.pop();
                int prev_result=st.top();
                st.pop();
                result*=st_sign;
                result+=prev_result;

            }
        }
        result+=(num*sign);
        return (int)result;
    }
};