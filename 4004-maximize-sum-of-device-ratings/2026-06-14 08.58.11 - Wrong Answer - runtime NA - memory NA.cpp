class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        long long sumS = 0;
        long long b = LLONG_MIN;

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

            sumS += dev2;
            b = max(b, (long long) dev1 - dev2);
        }
        return sumS + b;
    }
};