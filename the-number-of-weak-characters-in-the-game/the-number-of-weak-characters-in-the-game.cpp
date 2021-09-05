class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        if(a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& arr) {
        int n = arr.size();
        // map<int, int> m;
        int c = 0;
        // vector<pair<int, int>> v;
        // for(int i = 0; i<n; i++)
        //     v.push_back({arr[i][0], arr[i][1]});
        sort(arr.begin(), arr.end(), cmp);
        int maxAtt = arr[n - 1][0];
        int maxDef = arr[n - 1][1];
        for(int i = n - 2; i>=0; i--){
            if(arr[i][1] < maxDef && arr[i][0] < maxAtt)
                c++;
            maxDef = max(maxDef, arr[i][1]);

        }
        return c;
    }
};