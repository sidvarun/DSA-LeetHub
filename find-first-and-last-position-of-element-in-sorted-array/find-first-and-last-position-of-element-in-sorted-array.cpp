class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int mid = 0;
        vector<int> res;
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int pos1 = -1;
        int pos2 = -1;
        while(low <= high){
            mid = low + (high - low) / 2;;
            if(nums[mid] == target){
                if(mid == 0){
                  pos1 = mid;
                  break;
                }
                else if(nums[mid - 1] != nums[mid]){
                    pos1 = mid;
                    break;
                }
                else
                    high = mid - 1;
            }
            else if(nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        low = mid;
        high = n - 1;
        while(low <= high){
            mid = low + (high - low) / 2;;
            if(nums[mid] == target){
                if(mid == n - 1){
                  pos2 = mid;
                  break;
                }
                else if(nums[mid + 1] != nums[mid]){
                    pos2 = mid;
                    break;
                }
                else
                    low = mid + 1;
            }
            else if(nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        res.push_back(pos1);
        res.push_back(pos2);
        return res;
    }
};