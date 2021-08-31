class Solution {
public:
    bool val;
    // bool dfs(vector<vector<int>> adj, vector<bool> &visited, int u, vector<bool> &st){
    //     visited[u] = true;
    //     st[u] = true;
    //     for(auto v : adj[u]){
    //         if(!visited[v] && dfs(adj, visited, v, st))
    //             return true;
    //         else if(st[v] == true)
    //             return true;
    //     }
    //     st[u] = false;
    //     return false;
    // }
    bool isCyclic(int N, vector<vector<int>> adj) {
        queue<int> q; 
	    vector<int> indegree(N, 0); 
	    for(int i = 0;i<N;i++) {
	        for(auto it: adj[i]) {
	            indegree[it]++; 
	        }
	    }
	    
	    for(int i = 0;i<N;i++) {
	        if(indegree[i] == 0) {
	            q.push(i); 
	        }
	    }
	    int cnt = 0;
	    while(!q.empty()) {
	        int node = q.front(); 
	        q.pop(); 
	        cnt++; 
	        for(auto it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it); 
	            }
	        }
	    }
	    if(cnt == N) return false; 
	    return true; 
	}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        val = true;
        vector<vector<int>> adj(numCourses);
        for(int i = 0; i<prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        // vector<bool> visited(numCourses, false);
        // vector<bool> st(numCourses, false);
        // for(int i = 0; i < numCourses; i++){
        //     if(adj[i].size() && !visited[i])
        //         if(dfs(adj, visited, i, st))
        //             return false;
        // }
//         for(int i = 0; i < numCourses; i++){
            
//         }
        return !isCyclic(numCourses, adj);
    }
};