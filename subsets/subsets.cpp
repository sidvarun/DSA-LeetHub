class Solution {
public:
    void backTrack(vector<vector<int>> &res, vector<int> &v, vector<int> &nums, map<int, int> &m, int index){
        if(v.size() == nums.size()){
            res.push_back(v);
            return;
        }
        res.push_back(v);
        for(int i = index; i<nums.size(); i++){
            if(m.find(nums[i]) == m.end()){
                m[nums[i]] = 1;
                v.push_back(nums[i]);
                backTrack(res, v, nums, m, i + 1);
                v.pop_back();
                m.erase(nums[i]);
            } 
        }

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> v;
        map<int, int> m;
        backTrack(res, v, nums, m, 0);
        return res;
    }
};