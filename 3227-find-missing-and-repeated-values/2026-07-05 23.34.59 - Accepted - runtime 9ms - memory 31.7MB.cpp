class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> res;

        unordered_map<int,int> mp;

        for(int i = 0; i < n; i++) {
           for(int j = 0; j < n; j++) {
                mp[grid[i][j]]++;
           }
        }

        for(auto &it : mp) {
            if(it.second > 1) res.push_back(it.first);
        }

        for(int i = 1; i <= n*n; i++) {
            if(mp[i] == 0) res.push_back(i);
        }

        return res;


    }
};