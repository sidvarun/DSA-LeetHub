class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0;
        for(int i = 0; i<nums.size(); ){
            nums[index++] = nums[i];
            while(i < nums.size() && nums[i] == nums[index - 1])
                i++;
        }
        return index;
    }
};