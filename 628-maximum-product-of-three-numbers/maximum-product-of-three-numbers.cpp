class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();

        // Approach 1 : Simple Brute Force, gives TLE ....
        // int mx = INT_MIN;
        // for(int i = 0; i < n; i++) {
        //     for(int j = i + 1; j < n; j++) {
        //         for(int k = j + 1; k < n; k++) {
        //             mx = max(mx, nums[i] * nums[j] * nums[k]);
        //         }
        //     }
        // }

        // return mx;


        // Approach 2 
        sort(nums.begin(), nums.end());
        int ifAllPositve = nums[n-1] * nums[n-2] * nums[n-3];
        int ifNegativePresent = nums[0] * nums[1] * nums[n-1];

        return max(ifAllPositve, ifNegativePresent);
    }
};