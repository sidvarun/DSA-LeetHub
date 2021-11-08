class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int maxm = 0;
        int minm = 0;
        for(auto x : nums){
            maxm += x;
            minm = max(minm, x);
        }
        int l = minm;
        int h = maxm;
        
        while(l < h){
            int mid = l + (h - l) / 2;
            
            int d = 1;
            int cap = 0;
            for(int i = 0; i<nums.size();){
                int x = nums[i];
                if(cap + x <= mid){
                    cap +=x;
                    i++;                    
                }
                else{
                    d++;
                    cap = 0;
                }
            }
            if(d > m)
                l = mid + 1;
            else
                h = mid;
        }
        return l;
    }
};