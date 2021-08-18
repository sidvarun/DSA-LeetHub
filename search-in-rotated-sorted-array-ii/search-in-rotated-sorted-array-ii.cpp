class Solution {
public:
    bool binarySearch(vector<int> nums, int low, int high, int target){
        while(low <= high){
            int mid = low + (high - low) / 2;;
            if(nums[mid] == target)
                return true;
            if(nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return false;

    }
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = 0;
        for(int i = 1; i<n; i++){
            if(nums[i] < nums[i - 1]){
                pivot = i;
                break;
            }
        }
        if(target == nums[pivot])
            return true;
        if(target > nums[n-1])
            return binarySearch(nums, 0, pivot - 1, target);
        else
            return binarySearch(nums, pivot, n-1, target);
    }
};