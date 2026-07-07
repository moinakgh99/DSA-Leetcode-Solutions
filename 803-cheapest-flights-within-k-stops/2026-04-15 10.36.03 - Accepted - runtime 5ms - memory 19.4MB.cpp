class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        vector<int> stops(n, INT_MAX);
        pq.push({0, src, 0});

        while(!pq.empty()) {
            auto[cost, node, steps] = pq.top();
            pq.pop();
            if(node == dst) return cost;
            if(steps > k || steps > stops[node]) continue;

            stops[node] = steps;
            for(auto &it : adj[node]) {
                pq.push({cost + it.second, it.first, steps + 1});
            }
        }
        return -1;
    }
};