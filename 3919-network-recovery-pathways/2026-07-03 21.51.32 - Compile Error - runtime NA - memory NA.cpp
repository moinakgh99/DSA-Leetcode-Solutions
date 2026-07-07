class Solution {
public:
    typedef long long ll;
    typedef pair<long long, int> p;    // {cost, node}  node -> moving to next node

    bool check(int mid, int n, ll k, unordered_map<int, vector<vector<int,int>>> &adj) {
        // res[i] => min cost path from source to ith node
        vector<ll> res(n, LLONG_MAX);

        // min-heap used for dijkatsra algorithm
        priority_queue<p, vector<p>, greater<p>> pq;

        res[0] = 0;  // source p poochna k cost 0 hi hoga !!
        pq.push({0,0});  // 0 cost, 0 node     node -> moving to next node

        while(!pq.empty()) {
            ll d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(d > k) return false;  // agar distance k se bada ho gya
            if(node == n-1) return true;  // destination pooch gye beena kuch dikkat k

            // total cost reaching from source to node = d
            if(res[node] < d) continue;

            for(auto &vec : adj[node]) {
                int ngbr = vec[0];
                int cost = vec[1];

                if(cost < mid) continue;

                if(d + cost < res[ngbr]) {
                    res[ngbr] = d + cost;
                    pq.push({d+cost, ngbr});
                }
            } 
        }
        return false;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size(); // total n nodes

        // adjacency list u -> {(v, cost)}
        unordered_map<int, vector<vector<int,int>>> adj;

        int l = INT_MAX;
        int r = 0;

        for(auto &edge : edges) {
            int u = edge[0], v = edge[1], cost = edge[2];
            if(!online[u] || !online[v]) continue;

            adj[u].push_back({v, cost});
            l = min(l, cost);   // contains min edge weights
            r = max(r, cost);   // contains max edge weights
        }

        // Applying Binary Search
        int ans = -1;
        while(l <= r) {
            int mid = l + (r-l) / 2;

            if(check(mid, n, k, adj)) {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return ans;
    }
};