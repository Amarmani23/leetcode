class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string prev=countAndSay(n-1);
        return runLengthEncode(prev);
    }
private:
    string runLengthEncode(string &str){
        string result="";
        int count=1;
        for(size_t i=0;i<str.length();++i){
            if(i+1<str.length() && str[i]==str[i+1]){
                count++;
            }else{
                result+=to_string(count)+str[i];
                count=1;
            }
        }
        return result;
    }
};