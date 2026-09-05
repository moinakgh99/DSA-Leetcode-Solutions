class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newIntervals) {
        int n = intervals.size();
        int i = 0;
        vector<vector<int>> res;

        while(i < n && intervals[i][1] < newIntervals[0]) {
            res.push_back(intervals[i]);
            i++;
        }

        while(i < n && intervals[i][0] <= newIntervals[1]) {
            newIntervals[0] = min(newIntervals[0], intervals[i][0]);
            newIntervals[1] = max(newIntervals[1], intervals[i][1]);
            i++;
        }

        res.push_back(newIntervals);

        while(i < n) {
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};