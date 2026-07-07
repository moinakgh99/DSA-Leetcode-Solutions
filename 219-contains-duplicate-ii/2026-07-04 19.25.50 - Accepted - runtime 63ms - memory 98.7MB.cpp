class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();

        // O(n2) gives TLE ...
        // for(int i = 0; i < n; i++) {
        //     for(int j = i + 1; j < n; j++) {
        //         if(nums[i] == nums[j] && abs(i - j) <= k) return true;
        //     }
        // }
        // return false;


        // O(n) solutn is ....
        unordered_map<int,int> mp;

        for(int i = 0; i < n; i++) {
            auto it = mp.find(nums[i]);
            if(it != mp.end() && abs(i - it->second) <= k) return true;

            mp[nums[i]] = i;
        }
        return false;
    }
};