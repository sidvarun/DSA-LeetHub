class Solution {
public:
    int partition(vector<int>&nums, int l, int h){
        int i = l - 1;
        int p = rand()%(h - l + 1) + l;
        swap(nums[p], nums[h]);
        for(int j = l; j < h; j++){
            if(nums[j] < nums[h]){
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[h]);
        return i + 1;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0;
        int n = nums.size();
        int r = n - 1;
        
        k = n - k + 1;
        
        while(l <= r){
            int p = partition(nums, l, r);
            
            if(p == k - 1)
                return p;
            
            else if(p > k - 1)
                r = p - 1;
            else
                l = p + 1;
        }
        return -1;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        vector<int> unique;
        for(int i = 0; i<nums.size(); i++){
            if(m.find(nums[i]) == m.end())
                unique.push_back(nums[i]);
            m[nums[i]]++;
        }
        
        // unordered_set<int> s;
        // for(auto x : m)
        //     s.insert(x.second);
        vector<int> freq;
        for(auto x : m)
            freq.push_back(x.second);
        int n = freq.size();
        int kPos = findKthLargest(freq, k);
        vector<int> res;
        int f = freq[kPos];
        for(int i = 0; i<unique.size(); i++)
            if(m[unique[i]] >= f)
                res.push_back(unique[i]);
        return res;
    }
};