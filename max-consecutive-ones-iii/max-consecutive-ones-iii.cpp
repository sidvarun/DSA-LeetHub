class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        int i = 0;
        int j = 0;
        while(j < n){
            if(nums[j] == 1)
                j++;
            else if(k > 0){
                k--;
                j++;
            }
            else{
                if(nums[i] == 0)
                    k++;
                i++;
            }
            res = max(res, j - i);
        }
        return res;
    }
};