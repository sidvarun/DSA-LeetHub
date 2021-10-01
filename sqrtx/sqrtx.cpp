class Solution {
public:
    int mySqrt(int x) {
        int res = 0;
        int l = 1;
        int r = x;
        while(l <= r){
            long long int mid = l + (r - l)/2;
            if(mid * mid == x){
                res = mid;
                break;
            }
            if(mid * mid < x && (mid + 1) * (mid + 1) > x){
                res = mid;
                break;
            }
            // if(mid * mid > x && mid == l){
            //     res = mid;
            //     break;
            // }
            if(mid * mid < x)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return res;
    }
};