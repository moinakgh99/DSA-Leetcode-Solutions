class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;
        for(auto x : points) {
            int a = x[0];
            int b = x[1];
            int dist = (a*a) + (b*b);
            pq.push({dist,x});
            if(pq.size() > k) {
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;

    }
};