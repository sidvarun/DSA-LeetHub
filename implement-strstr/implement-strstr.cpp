class Solution {
public:
    int strStr(string text, string pat){
        int m = pat.length();
        int n = text.length();
        for(int i = 0; i<=n-m; i++){
            int j;
            for(j = 0; j<m; j++){
                if(pat[j] != text[i + j])
                    break;
            }
            if(j == m)
                return i;
        }
        return -1;
    }
};