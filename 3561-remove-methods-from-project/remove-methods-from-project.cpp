class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        vector<bool> suspicious(n, false);

        for(auto &edge : invocations) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        q.push(k);
        suspicious[k] = true;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto &ngbr : adj[node]) {
                indegree[ngbr]--;

                if(!suspicious[ngbr]) {
                    q.push(ngbr);
                    suspicious[ngbr] = true;
                }
            }
        }

        vector<int> res;
        bool cannotRemove = false;

        for(int i = 0; i < n; i++) {
            if(suspicious[i] && indegree[i] > 0) {
                cannotRemove = true;
                break;
            }

            if(!suspicious[i]) res.push_back(i);
        }

        if(cannotRemove) {
            vector<int> allNodes(n);
            for(int i = 0; i < n; i++) allNodes[i] = i;
            return allNodes;
        }

        return res;
    }
};