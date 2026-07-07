class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();

        // Using O(n) space ....
        unordered_map<int,int> mp;
        vector<int> res;

        for(int &x : nums) mp[x]++;

        for(auto &it : mp) {
            if(it.second == 1) res.push_back(it.first);
        }

        return res;
    }
};