class Solution {
public:
    int fib(int n) {
        if(n<=1) return n;
        int pre2=0;
        int pre1=1;
        int current=0;
        for(int i =2;i<=n;i++){
            current=pre1+pre2;
            pre2=pre1;
            pre1=current;
        }
        
        return current;
    }
};