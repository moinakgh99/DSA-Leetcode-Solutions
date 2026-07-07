class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n = costs.size();
        sort(costs.begin(), costs.end());
        int c = 0;
        for(int i = 0; i < n; i++) {
            coins -= costs[i];
            if(coins >= 0) c++;
            else break;
        }

        return c;
    }
};