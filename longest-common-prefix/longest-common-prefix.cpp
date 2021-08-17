class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i = 0;
        int res = 0;
        if(strs.size() == 1)
            return strs[0];
        while(true){
            int j;
            for(j = 0; j<strs.size() - 1; j++){
                if(i == strs[j].size() || i == strs[j+1].size() || strs[j][i] != strs[j+1][i])
                    break;
            }
            if(j != strs.size() - 1)
                break;
            else 
                res++;
            i++;
        }
        return strs[0].substr(0, res);    
    }
};