class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<string> s;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    string s1 = to_string(board[i][j] - '0') + " belongs to row" + to_string(i); 
                    string s2 = to_string(board[i][j] - '0') + " belongs to col" + to_string(j); 
                    string s3 = to_string(board[i][j] - '0') + " belongs to grid" + to_string(i/3) + to_string(j/3); 
                    if(s.count(s1) != 0 || s.count(s2) != 0 || s.count(s3) != 0)
                        return false;
                    s.insert(s1);
                    s.insert(s2);
                    s.insert(s3);
                }
            }
        }
        return true;
    }
};