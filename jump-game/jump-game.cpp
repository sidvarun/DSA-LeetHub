class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        bool dp[n];
        memset(dp, false, sizeof(dp));
        dp[n - 1] = true;
        for(int i = n - 2; i >= 0; i--){
            for(int j = 1; j <= nums[i]; j++){
                if(i + j < n && dp[i + j]){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};