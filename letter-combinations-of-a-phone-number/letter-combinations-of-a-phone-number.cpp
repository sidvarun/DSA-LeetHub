class Solution {
public:
    vector<string> letterCombinations(string digits) {
        queue<string> q;
        string ref[] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        if(digits == "")
            return res;
        q.push("");
        for(int i = 0; i<digits.length(); i++){
            int c = q.size();
            string str = ref[digits[i] - '0'];
            while(c--){
                string sub = q.front();
                q.pop();
                for(int j = 0; j<str.length(); j++)
                    q.push(sub + str[j]);
            }
        }
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};