class Solution {
public:
    vector<int> weights;
    vector<int> prefix;
    int sum;
    Solution(vector<int>& w) {
        weights = w;
        sum = 0;
        for(int i = 0; i<w.size(); i++){
            sum += weights[i];
            prefix.push_back(sum);
        }
    }
    
    int pickIndex() {
        float randNum = (float) rand()/RAND_MAX;
        float target = randNum * sum;
        int index = lower_bound(prefix.begin(), prefix.end(), target) - prefix.begin();
        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */