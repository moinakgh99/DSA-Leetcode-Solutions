class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        // Approach 1 : Using STLs ... O(n2) solution ..

        /*
        int ans = -1;
        for(int i = 0; i < n; i++) {
            int mxi = *max_element(nums.begin(), nums.begin() + i);
            int mini = *min_element(nums.begin() + i, nums.end());

            if( (mxi - mini) <= k) {
                ans = i;
                break;
            } 
        }

        return ans;
        */


        // Approach 2 : Using prefix Sum ...
        vector<int> maxi(n), mini(n);

        int idx = -1;
        int mx = INT_MIN, mn = INT_MAX;
        for(int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            maxi[i] = mx;
        }

        for(int i = n-1; i >= 0; i--) {
            mn = min(mn, nums[i]);
            mini[i] = mn;
        }

        for(int i = 0; i < n; i++) {
            if((maxi[i] - mini[i]) <= k) {
                idx = i;
                break;
            }
        }

        return idx;
    }
};