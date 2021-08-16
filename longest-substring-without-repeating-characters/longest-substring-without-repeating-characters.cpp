class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int l = 0;
        int r = 0;
        int n = s.length();
        map<char, int> m;
        for(int r = 0; r<n; r++){
            if(m.find(s[r]) != m.end())
                l = max(m[s[r]] + 1, l);
            m[s[r]] = r;
            res = max(res, r - l + 1);
        }
        return res;
    }
};