// class Solution {
// public:
//     int minSwaps(string s) {
//         if(s == "[]")
//             return 0;
//         int n = s.length();
//         int p1 = 0;
//         int p2 = n - 1;
//         int countOpenRight= 0;
//         int countCloseRight = 0;
//         int countOpenLeft = 0;
//         int countCloseLeft = 0;
//         int count = 0;
//         while(p1 < p2){
            
//         }
//         return count;
//     }
// };
class Solution {
public:
    int minSwaps(string s) {
        int left = 0, right = 0, N = s.size(), L = 0, R = N - 1, ans = 0; 
        while (L < R) {
            for (; L < R; ++L) {
                left += s[L] == '[' ? 1 : -1;
                if (left == -1) break;
            }
            if (L >= R) break; // no more unmatched branchets, break
            for (; L < R; --R) {
                right += s[R] == ']' ? 1 : -1;
                if (right == -1) break;
            }
            left = right = 1; // after swapping `s[L]` and `s[R]`, `left` and `right` will become `1`.
            ++L, --R;
            ++ans;
        }
        return ans;
    }
};