class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<int> dq;
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dq.push_back(0);
        for(int i = 1; i<n; i++){
            dp[i] = dp[dq.front()] + nums[i];
            if(dq.front() <= i - k)
                dq.pop_front();
            while(!dq.empty() && dp[dq.back()] <= dp[i])
                dq.pop_back();
            dq.push_back(i);
        }
        return dp[n - 1];
    }
};