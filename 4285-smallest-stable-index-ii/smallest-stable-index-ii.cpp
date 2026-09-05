class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> mxi(n), mini(n);

        int mx = INT_MIN, mn = INT_MAX;
        for(int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            mxi[i] = mx;
        }

        for(int i = n-1; i >= 0; i--) {
            mn = min(mn, nums[i]);
            mini[i] = mn;
        }

        int idx = -1;
        for(int i = 0; i < n; i++) {
            if( (mxi[i] - mini[i]) <= k) {
                idx = i;
                break;
            }
        }

        return idx;
    }
};