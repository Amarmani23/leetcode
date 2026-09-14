// class Solution {
// public:
//     bool isPowerOfTwo(int n) {
//         if(n<=0) return false;
//         while(n%2==0){
//             n/=2;
//         }
//         return n==1;
//     }
// };


// by recursion -------------------

// class Solution {
// public:
//     bool isPowerOfTwo(int n) {
//         if(n<=0) return false;
//         if(n==1) return true;
//         if(n%2!=0) return false;
//         return isPowerOfTwo(n/2);
//     }
// };


//by bitwise ---------------

class Solution {
public:
    bool isPowerOfTwo(int n) {
        //-------by right-shift ---------
        // if(n<=0) return false;
        // while((n&1)==0){
        //     n>>=1;
        // }
        // return n==1;


        // --- left-shift ----------------
        if(n<=0) return false;
        long long tracker=1;
        while(tracker<n){
            tracker<<=1;
        }
        return tracker==n;
    }
};