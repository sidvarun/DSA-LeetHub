class Solution {
public:
    // static bool cmp(vector<int> a, vector<int> b){
    //     if(a[0] != b[0])
    //         return a[0] < b[0];
    //     if(a[1] != b[1])
    //         return a[1] < b[1];
    //     return a[2] < b[2];
    // }
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &v : cuboids)
            sort(v.begin(), v.end());
        sort(cuboids.begin(), cuboids.end());
        int res = INT_MIN;
        int n = cuboids.size();
        vector<int> dp(n, 0);
        for(int i = 0; i<n; i++){
            int maxm = 0;
            // dp[i] = cuboids[i][2];
            for(int j = 0; j<i; j++){
                if(cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2])
                    maxm = max(maxm, dp[j]);
                    // dp[i]=max(dp[i],dp[j]+cuboids[i][2]);
            }
            dp[i] = maxm + cuboids[i][2];
            res = max(res, dp[i]);
        }
        return res;
    }
};