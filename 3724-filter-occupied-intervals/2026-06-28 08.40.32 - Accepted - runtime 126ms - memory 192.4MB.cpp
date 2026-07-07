class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        sort(occupiedIntervals.begin(), occupiedIntervals.end());

        vector<vector<int>> merge;
        for(auto &x : occupiedIntervals) {
            if(merge.empty() || x[0] > merge.back()[1] + 1) merge.push_back(x);
            else merge.back()[1] = max(merge.back()[1], x[1]);
        }

        vector<vector<int>> res;
        for(auto &x : merge) {
            int left = x[0];
            int right = x[1];

            if(left > freeEnd || right < freeStart) {
                res.push_back({left, right});
                continue;
            }
            if(left < freeStart) res.push_back({left, freeStart - 1});
            if(right > freeEnd) res.push_back({freeEnd + 1, right});
        }

        return res;
    }
};