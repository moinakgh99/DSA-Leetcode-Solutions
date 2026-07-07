class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        int middle = floor(n/2);

        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
            if(mp[nums[middle]] > 1) return false;
        }
        return true;
    }
};