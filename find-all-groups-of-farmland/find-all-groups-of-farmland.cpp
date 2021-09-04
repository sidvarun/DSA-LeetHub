class Solution {
public:
    bool isSafe(int i, int j, int m, int n){
        if(i >= m || i < 0 || j < 0 || j >= n)
            return false;
        return true;
    }
    void bfs(vector<vector<int>> &land, vector<vector<int>> &visited, int i, int j, vector<int> &temp, int m, int n){
        queue<pair<int, int>> q;
        q.push({i, j});
        int fi = i;
        int fj = j;
        visited[fi][fj] = 1;
        while(!q.empty()){
            pair<int, int> curr = q.front();
            q.pop();
            fi = curr.first;
            fj = curr.second;
            // if(fi == m - 1 && fj == n - 1)
            //     break;
            // if(isSafe(fi, fj + 1, m, n) && land[fi][fj+1] == 0 && isSafe(fi + 1, fj, m, n) && land[fi + 1][fj] == 0){
            //     break;
            // }
            // if(isSafe(fi + 1, fj, m, n) && land[fi + 1][fj] == 0 && !isSafe(fi, fj + 1, m, n)){
            //       break;
            // }
            // if(isSafe(fi , fj + 1, m, n) && land[fi][fj + 1] == 0 && !isSafe(fi + 1, fj, m, n)){
            //    break;
            // }
            if(isSafe(fi, fj + 1, m, n) && land[fi][fj+1] && !visited[fi][fj+1]){
                visited[fi][fj+1] = 1;
                q.push({fi, fj + 1});
            }
            if(isSafe(fi + 1, fj, m, n) && land[fi + 1][fj] && !visited[fi + 1][fj]){
                visited[fi + 1][fj] = 1;
                q.push({fi + 1, fj});
            }
        }
        temp.push_back(fi);
        temp.push_back(fj);
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();
        vector<vector<int>> res;
        vector<vector<int>> visited(m, vector<int> (n, 0));
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(land[i][j] && !visited[i][j]){
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    bfs(land, visited, i, j, temp, m, n);
                    res.push_back(temp);
                }
            }
        }
        return res;
    }
};