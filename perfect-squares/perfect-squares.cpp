// class Solution {
// public:
//     int numSquares(int n) {
//         int dp[n + 1];
//         memset(dp, INT_MAX, sizeof(dp));
//         dp[0] = 0;
//         for(int i = 1; i<=n; i++){
//             for(int j = 1; j<=i; j++){
//                 if(j*j <= i)
//                     dp[i] = min(dp[i], 1 + dp[i - j*j]);
//             }
//         }
//         return dp[n];
//     }
// };
class Solution 
{
public:
    int numSquares(int n) 
    {
        if (n <= 0)
        {
            return 0;
        }
        
        // cntPerfectSquares[i] = the least number of perfect square numbers 
        // which sum to i. Note that cntPerfectSquares[0] is 0.
        vector<int> cntPerfectSquares(n + 1, INT_MAX);
        cntPerfectSquares[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            // For each i, it must be the sum of some number (i - j*j) and 
            // a perfect square number (j*j).
            for (int j = 1; j*j <= i; j++)
            {
                cntPerfectSquares[i] = 
                    min(cntPerfectSquares[i], cntPerfectSquares[i - j*j] + 1);
            }
        }
        
        return cntPerfectSquares.back();
    }
};