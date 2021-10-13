class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        int n = nums.size();
        while(left < n && nums[left] != 0)
                    left++;
        for(int right = left + 1; right < n; right++){
            if(nums[right] != 0 && right > left){
                swap(nums[left], nums[right]);
                while(left < n && nums[left] != 0)
                    left++;
                if(left == n)
                    return;
            }
        }
    }
};