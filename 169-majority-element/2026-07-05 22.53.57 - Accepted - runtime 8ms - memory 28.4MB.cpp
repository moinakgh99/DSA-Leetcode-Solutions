class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        int ele = floor(n/2);

        for(int x : nums) {
            mp[x]++;
        }

        for(auto &it : mp) {
            if(it.second > n/2) return it.first;
        }

        return -1;
    }
};