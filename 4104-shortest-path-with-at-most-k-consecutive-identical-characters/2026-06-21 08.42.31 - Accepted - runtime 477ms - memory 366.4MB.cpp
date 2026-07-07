class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> ad(n);
        
        for(auto &e : edges) {
            ad[e[0]].push_back({e[1], e[2]});
        }

        const long long INF = 1e18;

        vector<vector<long long>> d(n, vector<long long>(k+1, INF));

        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>> pq;

        d[0][1] = 0;
        pq.push({0,0,1});

        while(!pq.empty()) {
            auto c = pq.top();
            pq.pop();

            long long costs = c[0];
            int x = c[1];
            int s = c[2];

            if(costs > d[x][s]) continue;

            for(auto &[v,w] : ad[x]) {
                int newS;
                if(labels[x] == labels[v]) {
                    newS = s + 1;
                    if(newS > k) continue;
                }
                else newS = 1;

                long long newC = costs + w;
                if(newC < d[v][newS]){
                    d[v][newS] = newC;
                    pq.push({newC, v, newS});
                }
            }
        }

        long long res = INF;
        for(int i = 1; i <= k; i++) {
            res = min(res, d[n-1][i]);
        }

        return res == INF ? -1 : res;
    }
};