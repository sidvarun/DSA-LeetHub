class Solution {
public:
    void backTrack(vector<vector<int>> &res, vector<int> v, vector<int> nums, map<int, int> m){
        if(v.size() == nums.size()){
            res.push_back(v);
            return;
        }
        for(int i = 0; i<nums.size(); i++){
            if(m.find(nums[i]) == m.end()){
                m[nums[i]] = 1;
                v.push_back(nums[i]);
                backTrack(res, v, nums, m);
                v.pop_back();
                m.erase(nums[i]);
            } 
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> v;
        map<int, int> m;
        backTrack(res, v, nums, m);
        return res;
    }
};