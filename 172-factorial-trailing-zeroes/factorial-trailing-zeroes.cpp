class Solution {
public:
    int trailingZeroes(int n) {

// by recursion --------

        // if(n<5) return 0;
        // int ans=n/5;
        // ans+=trailingZeroes(ans);
        // return ans;


// by iterative aproche
        if(n<5) return 0;
        int count =0;
        while(n>=5){
            n/=5;
            count+=n;
        }
        return count;
    }
};