class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size();
        int n = matrix[0].size();
        int rowBegin = 0, rowEnd = m - 1;
        int colBegin = 0, colEnd = n - 1;
        while(rowBegin <= rowEnd && colBegin <= colEnd){
            // Traverse Right
            for(int j = colBegin; j <= colEnd; j++){
                res.push_back(matrix[rowBegin][j]);
            }
            rowBegin++;
            // Traverse Down
            for(int i = rowBegin; i <= rowEnd; i++){
                res.push_back(matrix[i][colEnd]);
            }
            colEnd--;
            if(rowBegin <= rowEnd){
                // Traverse Left
                for(int j = colEnd; j>=colBegin; j--){
                    res.push_back(matrix[rowEnd][j]);
                }
            }
            rowEnd--;

            if(colBegin <= colEnd){
                // Traverse Up
                for(int i = rowEnd; i>=rowBegin; i--){
                    res.push_back(matrix[i][colBegin]);
                }
            }
            colBegin++;

        }
        return res;
    }
};