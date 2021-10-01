class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = 0;
        int j = s.length() - 1;
        while(i<j && s[i] == ' ')
            i++;
        while(j>i && s[j] == ' ')
            j--;
        if(i == j)
            return 1;
        int start = i, end = i;
        while(end <= j){
            if(s[end] == ' '){
                end++;
                start = end;
            }
            else
                end++;
        }
        return end - start;
        
    }
};