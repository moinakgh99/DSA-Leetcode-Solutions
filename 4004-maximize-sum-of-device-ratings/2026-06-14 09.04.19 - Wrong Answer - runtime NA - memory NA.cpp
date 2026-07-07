class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        long long sumS = 0;
        long long b = LLONG_MAX;
        vector<pair<int,int>> res;

        for(auto &c : units) {
            int dev1 = INT_MAX;
            int dev2 = INT_MAX;

            for(int it : c) {
                if(it < dev1) {
                    dev2 = dev1;
                    dev1 = it;
                }
                else if(it < dev2) dev2 = it;
            }

            res.push_back({dev1, dev2});

            b = min(b, (long long)dev1);
            sumS += dev2;
        }
        long long ans = 0;
        for(auto &[dev1, dev2] : res) {
            ans = max(ans, b + (sumS - dev2));
        }
        return ans;
    }
};