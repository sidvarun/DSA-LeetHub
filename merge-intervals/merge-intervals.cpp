class Solution {
public:
    static bool cmp(vector<int> v1, vector<int> v2){
        if(v1[0] == v2[0])
            return v1[1] < v2[1];
        return v1[0] < v2[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int start = intervals[0][0];
        int end = intervals[0][1];
        vector<vector<int>> res;
        for(int i = 1; i<intervals.size(); i++){
            if(intervals[i][0] <= end){
                end = max(end, intervals[i][1]);
                // start = min(start, intervals[i][0]);
            }
            else{
                vector<int> t;
                t.push_back(start);
                t.push_back(end);
                res.push_back(t);
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        vector<int> t;
        t.push_back(start);
        t.push_back(end);
        res.push_back(t);
        return res;
    }
};