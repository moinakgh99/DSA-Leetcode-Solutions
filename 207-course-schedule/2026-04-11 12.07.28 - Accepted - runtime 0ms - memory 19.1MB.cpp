class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        for(auto &e : prerequisites) {
            int u = e[0];
            int v = e[1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        
        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        
        int c = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            c++;
            for(auto nbr : adj[node]) {
                indegree[nbr]--;
                if(indegree[nbr] == 0) q.push(nbr);
            }
        }
        
        if(c == numCourses) return true;
        else return false;
    }
};