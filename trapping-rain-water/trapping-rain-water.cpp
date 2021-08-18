class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int n = height.size();
        vector<int> maxOnLeft;
        maxOnLeft.push_back(0);
        int maxm = height[0];
        for(int i = 1; i<n; i++){
            maxOnLeft.push_back(maxm);
            maxm = max(maxm, height[i]);
        }
        vector<int> maxOnRight;
        maxOnRight.push_back(0);
        maxm = height[n-1];
        for(int i = n-2; i>=0; i--){
            maxOnRight.push_back(maxm);
            maxm = max(maxm, height[i]);
        }
        reverse(maxOnRight.begin(), maxOnRight.end());
        for(int i = 1; i < n-1; i++){
            int subres = min(maxOnRight[i], maxOnLeft[i]) - height[i];
            if(subres > 0)
                res += subres;
        }
        return res;
    }
};