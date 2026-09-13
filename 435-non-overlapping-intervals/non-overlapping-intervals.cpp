class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        int c = 0;
        vector<vector<int>> res;

        sort(intervals.begin(), intervals.end());

        res.push_back(intervals[0]);

        for(int i = 1; i < n; i++) {
            if(res.back()[1] <= intervals[i][0]) res.push_back(intervals[i]);
            else {
                c++;

                if(intervals[i][1] <= res.back()[1]) res.back() = intervals[i];
            }
        }

        return c;
    }
};