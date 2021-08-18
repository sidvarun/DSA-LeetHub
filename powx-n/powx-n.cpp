class Solution {
public:
    double myPow(double x, int n) {
        bool sign = false;
        if(n < 0)
            sign = true;
        long long power = abs(n);
        double res = 1;
        while(power > 0){
            if(power % 2 != 0){
                res = res * x;
                power--;
            }
            else{
                x = x * x;
                power /= 2;
            }
        }
        return sign ? (double)1.0 / res : (double) res;
    }
};