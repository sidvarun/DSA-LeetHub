class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = INT_MIN;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0;
        int left = 1;
        int right = n - 1;
        for(int i = 0; i<nums.size() - 2 ; i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            left = i + 1;
            right = n - 1;
            while(left < right){
            int sum = nums[i] + nums[left] + nums[right];
            if(target == sum)
                return sum;
            if(abs(target - sum) < abs((long long)target - res)){
                res = sum;
            }
            if(target > sum)
                left++;
            else
                right--;
            
            }
        }
        return res;
    }
};