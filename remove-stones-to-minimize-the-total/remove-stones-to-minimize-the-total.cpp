class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(int i = 0; i<piles.size(); i++)
            pq.push(piles[i]);
        while(k--){
            int curr = pq.top();
            pq.pop();
            curr = curr - curr/2;
            pq.push(curr);
        }
        int res = 0;
        while(!pq.empty()){
            res += pq.top();
            pq.pop();
        }
        return res;
    }
};