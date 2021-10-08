class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        vector<int> temp;
        for(int i = 0; i<=k; i++){
            temp = dist;
            for(auto edge : flights){
                int from = edge[0];
                int to = edge[1];
                int price = edge[2];
                if(dist[from] == INT_MAX)
                    continue;
                if(temp[to] > dist[from] + price)
                    temp[to] = dist[from] + price;
            }
            dist = temp;
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};