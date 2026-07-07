class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int x : nums) {
            mp[x]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto x : mp) {
            pq.push({x.second, x.first});
            if(pq.size() > k) {
                pq.pop();
            }
        }


        vector<int> res;

        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;


    }
};