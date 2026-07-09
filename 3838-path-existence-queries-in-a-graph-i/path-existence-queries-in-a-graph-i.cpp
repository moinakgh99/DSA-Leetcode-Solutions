class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> component(n);
        component[0] = 0;

        for(int i = 1; i < n; i++) {
            if(nums[i] - nums[i-1] <= maxDiff) component[i] = component[i-1];
            else component[i] = component[i-1] + 1;
        }

        vector<bool> res;
        for(auto &it : queries) {
            res.push_back(component[it[0]] == component[it[1]]);
        }

        return res;
    }
};