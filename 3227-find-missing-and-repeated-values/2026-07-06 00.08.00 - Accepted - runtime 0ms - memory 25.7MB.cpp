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
        long long sum = 0, gridSum = 0;
        long long sqSum = 0, gridSqSum = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                gridSum += grid[i][j];
                gridSqSum += 1LL * grid[i][j] * grid[i][j];
            }
        }

        for(int i = 1; i <= n*n; i++) {
            sum += i;
            sqSum += i*i;
        }

        int sqDiff = gridSqSum - sqSum;
        int sumDiff = gridSum - sum;
        
        int a = ((sqDiff / sumDiff) + sumDiff) / 2;
        int b = ((sqDiff / sumDiff) - sumDiff) / 2;

        return {a, b};
        
    }
};