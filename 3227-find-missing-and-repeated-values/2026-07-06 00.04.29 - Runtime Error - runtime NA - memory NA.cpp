class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        int n = grid.size();


        // Approach 1 : O(n2) time and space ...
        // unordered_map<int,int> mp;
        // vector<int> res;

        // for(int i = 0; i < n; i++) {
        //    for(int j = 0; j < n; j++) {
        //         mp[grid[i][j]]++;
        //    }
        // }

        // for(auto &it : mp) {
        //     if(it.second > 1) res.push_back(it.first);
        // }

        // for(int i = 1; i <= n*n; i++) {
        //     if(mp[i] == 0) res.push_back(i);
        // }

        // return res;


        /// Approach 2 : O(n2) time and O(1) space ....
        int sum = 0, gridSum = 0;
        int sqSum = 0, gridSqSum = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                gridSum += grid[i][j];
                gridSqSum += pow(grid[i][j], 2);
            }
        }

        for(int i = 1; i <= n*n; i++) {
            sum += i;
            sqSum += i*i;
        }

        int sqDiff = gridSqSum - sqSum;
        int sumDiff = gridSum - sum;
        
        int a = 0.5 * ((sqDiff / sumDiff) + sumDiff);
        int b = 0.5 * ((sqDiff / sumDiff) - sumDiff);

        return {a, b};
        
    }
};