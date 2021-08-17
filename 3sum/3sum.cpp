class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() == 0)
            return res; 
        sort(nums.begin(), nums.end());
      
        for(int i = 0; i<nums.size() - 1; i++){
            int front = i + 1;
            int back = nums.size() - 1;
            int sum = nums[i] * -1;
            while(front < back){
                if(nums[front] + nums[back] < sum)
                    front++;
                else if(nums[front] + nums[back] > sum)
                    back--;
                else{
                    vector<int> v = {nums[i], nums[front], nums[back]};
                    res.push_back(v);
                    while(front < back && nums[back] == v[2])
                        back--;
                    while(front < back && nums[front] == v[1])
                        front++;
                }
            }
            while(i + 1 < nums.size() && nums[i+1] == nums[i])
                i++;
        }
        return res;
    }
};