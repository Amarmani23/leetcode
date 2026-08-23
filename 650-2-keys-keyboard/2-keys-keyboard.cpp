// class Solution {
// public:
//     int minSteps(int n) {
//         if(n==1) return 0;
//         return 1+rec(1,1,n);
//     }
// private:
//     int rec(int currlen,int cliplen,int n){
//         if(currlen == n){
//             return 0;
//         }
//         if(currlen>n) return 1e9;
//         int pasteonly=1e9;
//         if(cliplen>0){
//             pasteonly=1+rec(currlen+cliplen,cliplen,n);
//         }
//         int copyAndPaste=2+rec(currlen+currlen,currlen,n);
//         return min(pasteonly,copyAndPaste);
//     }
// };

//by mathematically (it alway sum of its prime factor eg 6=2+3)

class Solution {
public:
    int minSteps(int n) {
        int count=0;
        int factor=2;
        while(n>1){
            while(n%factor==0){
                count+=factor;
                n/=factor;
            }
            factor++;
        }
        return count;
    }
};