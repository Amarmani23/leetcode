class Solution {
public:
    long long trailingZero(long long n){
        long long count=0;
        while(n>=5){
            n/=5;
            count+=n;
        }
        return count;
    }
    int preimageSizeFZF(int k) {
        long long low=0;
        long long high=5LL *(k+1);
        while(low<=high){
            long long mid=low+(high-low)/2;
            long long zeroes=trailingZero(mid);
            if(zeroes==k) return 5;
            else if(zeroes<k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return 0;
    }
};