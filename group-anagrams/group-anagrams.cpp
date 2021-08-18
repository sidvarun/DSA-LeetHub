class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        vector<string> temp = strs;
        map<string, vector<string>> m;
        for(int i = 0; i<temp.size(); i++){
            sort(temp[i].begin(), temp[i].end());
            m[temp[i]].push_back(strs[i]);
        }
        for(auto v = m.begin(); v != m.end(); v++)
            res.push_back(v->second);
        return res;
    }
};