class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> startTime;
        vector<int> endTime;
        int n = intervals.size();
        for(int i = 0; i<intervals.size(); i++){
            startTime.push_back(intervals[i][0]);
            endTime.push_back(intervals[i][1]);
        }
        sort(startTime.begin(), startTime.end());
        sort(endTime.begin(), endTime.end());
        int res = 1;
        int curr = 1;
        int currTime = endTime[0];
        int i = 1;
        int j = 0;
        while(i < n){
            currTime = endTime[j];
            if(startTime[i] < currTime){
                curr++;
                i++;
            }
            else{
                curr--;
                j++;
            }
            res = max(res, curr);
        }
        return res;
    }
};