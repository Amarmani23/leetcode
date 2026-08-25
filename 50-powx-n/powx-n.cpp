class Solution {
public:
    // double myPow(double x, int n) {
    //     double result=pow(x,n);
    //     return result;
    // }


    double myPow(double x, int n) {
        long long N = n;
        if(N<0){
            x=1/x;
            N=-N;
        }
        double result=1.0;
        double curr_product=x;
        while(N>0){
            if(N & 1){
                result*=curr_product;
            }
            curr_product*=curr_product;
            N/=2;
        }
        return result;
    }
};