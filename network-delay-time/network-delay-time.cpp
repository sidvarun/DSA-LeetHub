class Solution{
    public:
        int networkDelayTime(vector<vector<int>>& times, int n, int k) {
            //dist set everyone to inf
            vector<int> dist(n+1,INT_MAX);
            dist[k]=0;

            //convert the graph into adj list
            vector<vector<pair<int,int>>> g(n+1);
            for(auto e: times){
                g[e[0]].push_back({e[1],e[2]});
            }

            //insert source in minHeap and set it's dist=0
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
            pq.push({0,k}); //{weight,node}

            //no need to track processed nodes(like we do in O(V^2) implementation), if doing this way
            while(!pq.empty()){
                auto p =pq.top();
                pq.pop();
                int u = p.second;
                for(auto nbr: g[u]){
                    int v = nbr.first, w = nbr.second;
                    if(dist[v] > dist[u]+w){
                        dist[v] = dist[u]+w;
                        pq.push({dist[v], v});
                    }
                }
            }
            int res= 0;
            for(int i=1; i<=n; i++){
                res = max(dist[i],res);
            }
            return res==INT_MAX ? -1 : res;
        }   
};