class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxm = 0;
        for(auto x : nums)
            maxm = max(maxm, x);
        int l = 1;
        int h = maxm;
        while(l < h){
            int mid = l + (h - l) / 2;
            int totalStores = 0;
            for(auto x : nums)
                totalStores += ceil((double) x / mid);
            if(totalStores > threshold)
                l = mid + 1;
            else
                h = mid;
        }
        return l;
    }
};