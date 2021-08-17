class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size() - 1;
        int left = 0;
        int right = n;
        int res = INT_MIN;
        while(left < right){
            res = max(res, min(height[left], height[right]) * (right - left));
            if(height[left] < height[right])
                left++;
            else
                right--;
        }
        return res;
    }
};