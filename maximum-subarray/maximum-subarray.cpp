class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSoFar = nums[0];
        int res = nums[0];
        for(int i = 1; i<nums.size(); i++){
            maxSoFar = max(nums[i], maxSoFar + nums[i]);
            res = max(res, maxSoFar);
        }
        return res;
    }
};