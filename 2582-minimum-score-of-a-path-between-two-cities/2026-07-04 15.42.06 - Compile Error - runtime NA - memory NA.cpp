class Solution {
public:

    void dfs(int src, unordered_map<int, vector<pair<int, int>>> &adj, vector<bool> &visited(n, false), int &res) {

        visited[src] = true;

        for(auto &nbr : adj[src]) {
            int v = nbr.first;
            int d = nbr.second;

            res = min(res, d);

            if(!visited[v]) dfs(v, adj, visited, res);
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int, vector<pair<int, int>>> adj;

        // making adjacency list
        for(auto &edge : roads) {
            int u = edge[0], v = edge[1], dist = edge[2];
            adj[u].push_back({v, dist});
            adj[v].push_back({u, dist});
        }

        vector<bool> visited(n, false);

        int res = INT_MAX;

        dfs(1, adj, visited, res);

        return res;
    }
};