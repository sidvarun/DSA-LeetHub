class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if(s.length() == 0)
            return true;
        int i = 0;
        while(i<s.length()){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
                i++;
            }
            else if(st.empty())
                return false;
            else if((s[i] == ')' && st.top() == '(') || (s[i] == '}' && st.top() == '{') || (s[i] == ']' && st.top() == '[')){
                st.pop();
                i++;
            }
            else
                return false;
        }
        if(st.empty())
            return true;
        return false;
    }
};