class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> res;

        for(int i = 1; i < n; i++) {
            int a = intervals[i-1][0], b = intervals[i-1][1];
            int c = intervals[i][0], d = intervals[i][1];

            if(c <= a && d >= b) continue;
            res.push_back({a,b});
        }
        return n - res.size();
    }
};