class Solution {
public:

    void dfs(int idx, vector<vector<int>>& isConnected, vector<int> &visited) {
        visited[idx] = 1;
        int n = isConnected.size();

        for(int j = 0; j < n; j++) {
            if(isConnected[idx][j] == 1 && visited[j] == 0) {
                dfs(j, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> visited(n,0);
        int provinces = 0;

        for(int i = 0; i < n; i++) {
            if(visited[i] == 0) {
                provinces++;
                dfs(i,isConnected, visited);
            }
        }

        return provinces;
    }
};