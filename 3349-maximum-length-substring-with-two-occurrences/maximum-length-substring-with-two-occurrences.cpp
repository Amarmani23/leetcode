class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int>count(26);
        int res=0;
        int left=0;
        for(int right=0;right<s.size();++right){
            int ch=s[right]-'a';
            ++count[ch];
            while(count[ch]>2){
                int ch1=s[left]-'a';
                --count[ch1];
                left++;
            }
            res=max(res,right-left+1);
        }
        return res;
    }
};