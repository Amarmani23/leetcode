class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor==-1){
            return INT_MAX;
        }
        bool negative = (dividend<0) ^(divisor<0);

        long long absdividend = abs((long long)dividend);
        long long absdivisor = abs((long long)divisor);

        long long quotient=0;
        while(absdividend >= absdivisor){
            long long tempdivisor=absdivisor;
            long long multiple=1;
            while(absdividend >= (tempdivisor<<1)){
                tempdivisor<<=1;
                multiple<<=1;
            }
            absdividend-=tempdivisor;
            quotient += multiple;
        }
        return negative ? -quotient : quotient;
    }
};