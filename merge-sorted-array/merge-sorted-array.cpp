class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0){
            sort(nums1.begin(), nums1.begin() + m);
            return;
        }
        int i = m - 1;
        int j = 0;
        while(i >= 0 && j < n){
            if(nums1[i] > nums2[j]){
                swap(nums1[i], nums2[j]);
                i--;
                j++;
            }
            else
                i--;
        }
        sort(nums1.begin(), nums1.begin() + m);
        sort(nums2.begin(), nums2.end());
        int k = m;
        for(int j = 0; j<n; j++)
            nums1[k++] = nums2[j];
    }
};