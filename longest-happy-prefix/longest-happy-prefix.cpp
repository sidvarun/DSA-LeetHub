class Solution {
public:
    int lps(string s) {
	    // Your code goes here
	    int n = s.length();
	    int len = 0;
	    vector<int> lps(n, 0);
	    lps[0] = 0;
	    int i = 1;
	    while(i<n){
	        if(s[len] == s[i]){
	            len++;
	            lps[i] = len;
	            i++;
	        }
	       else{
	           if(len == 0){
	            lps[i] = 0;
	            i++;
	           }
	           else
	            len = lps[len - 1];
	       }
	    }
	    return lps[n-1];
    }
    string longestPrefix(string s) {
       int n = s.length();
       int len = lps(s);
       return s.substr(n - len);       
    }
};