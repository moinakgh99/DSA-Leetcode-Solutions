class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int n = nums.size();

        // Using O(n) space ..
        unordered_map<int,int> mp;

        for(int x : nums) {
            mp[x]++;
        }

        for(auto &it : mp) {
            if(it.second == 1) return it.first;
        }
        return -1;
    }
};