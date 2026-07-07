class Solution {
public:
    int minimumCost(vector<int>& cost) {
        if(cost.size() == 2) return cost[0] + cost[1];
        sort(cost.begin(), cost.end(), greater<int>());
        int f = cost[0], s = cost[1];
        int sum = f + s;

        for(int i = 2; i < cost.size(); i++) {
            if(i % 3 != 2) sum += cost[i];
        }

        return sum;
    }
};