class Solution {
public:
    int subarraysDivByK(vector<int>& arr, int k) {
        map<int, int> m;
        int n = arr.size();
        int res = 0;
        int sum = 0;
        int rem = 0;
        m[0] = 1;
        for(int i = 0; i < n; i++)
        {
            sum += arr[i];
            rem = sum % k;
            if(rem < 0){
                rem += k;
            }
            res += m[rem];
            m[rem]++;
        }
        return res;
    }
};