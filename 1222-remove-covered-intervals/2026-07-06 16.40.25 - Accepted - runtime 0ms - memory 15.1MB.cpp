class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        int n = intervals.size();

        // My Approach is giving wrong answer ...
        // sort(intervals.begin(), intervals.end());
        // int c = 0;

        // for(int i = 1; i < n; i++) {
        //     int a = intervals[i-1][0], b = intervals[i-1][1];
        //     int c = intervals[i][0], d = intervals[i][1];

        //     if(c <= a && d >= b) c++;
        // }
        // return n - c;


        // using O(n) space ... 
        sort(intervals.begin(), intervals.end(), [](vector<int> &vec1, vector<int> &vec2) {
            if(vec1[0] == vec2[0]) return vec1[1] > vec2[1];
            return vec1[0] < vec2[0];
        });

        vector<vector<int>> res;
        res.push_back(intervals[0]);

        for(int i = 1; i < n; i++) {
            if(res.back()[0] <= intervals[i][0] && res.back()[1] >= intervals[i][1]) continue;

            res.push_back(intervals[i]);
        }

        return res.size();
    }
};