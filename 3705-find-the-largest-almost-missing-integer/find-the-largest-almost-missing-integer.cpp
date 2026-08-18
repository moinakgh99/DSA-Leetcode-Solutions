class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;
        for(int x : nums) mp[x]++;

        // agar window size 1 h to , jiski freq 1 hogi vo answer hoga !!
        if(k == 1) {
            int ans = -1;
            for(auto x : mp) {
                if(x.second == 1) ans = max(ans, x.first);
            }
            return ans;
        }

        // agar poora ek single subarray hoga to, max element return krdenga ..
        if(k == n) return *max_element(nums.begin(), nums.end());

        // vrna check kro pehle y last element ko, agar vo unique hue to !!
        int ans = -1;
        if(mp[nums[0]] == 1) ans = max(ans, nums[0]);
        if(mp[nums[n-1]] == 1) ans = max(ans, nums[n-1]);

        return ans;
    }
};