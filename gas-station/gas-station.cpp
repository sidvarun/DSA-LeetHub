class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        for(int i = 0; i<n; i++){
            int start = i;
            int index = (i + 1)%n;
            int currTank = gas[i] - cost[i];
            int c;
            if(currTank >= 0)
                c = 1;
            else
                continue;
            while(currTank >= 0){
                if(c == n)
                    return start;
                currTank += gas[index] - cost[index];
                index = (index + 1) % n;
                c++;
            }
            // i += index;
        }
        return -1;
    }
};