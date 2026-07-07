class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        // O(n) space and time ...
        // unordered_map<int,int> mp;
        // int ele = floor(n/2);

        // for(int x : nums) {
        //     mp[x]++;
        // }

        // for(auto &it : mp) {
        //     if(it.second > n/2) return it.first;
        // }

        // return -1;


        // O(n) time and O(1) space ..
        int f = 0, res = 0;
        for(int i = 0; i < n; i++) {
            if(f == 0) res = nums[i];

            if(res == nums[i]) f++;
            else f--;
        }
        return res;
    }
};