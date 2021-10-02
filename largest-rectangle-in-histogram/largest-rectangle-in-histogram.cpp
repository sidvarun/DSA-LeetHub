class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = INT_MIN;
        int index = 0;
        stack<pair<int, int>> s;
        for(int i = 0; i<heights.size(); i++){
            if(s.empty() || s.top().second <= heights[i])
                s.push({i, heights[i]});
            else{
                int shift = 0;
                while(!s.empty() && s.top().second > heights[i]){
                    // shift++;
                    int currHeight = s.top().second;
                    int startIndex = s.top().first;
                    s.pop();
                    int currWidth = i - startIndex;
                    res = max(res, currHeight * currWidth);
                    shift = startIndex;
                }
                // s.push({i - shift, heights[i]});
                s.push({shift, heights[i]});

            }
        }
        int n = heights.size();
        while(!s.empty()){
            res = max(res, s.top().second * (n - s.top().first));
            s.pop();
        }
        return res;
    }
};