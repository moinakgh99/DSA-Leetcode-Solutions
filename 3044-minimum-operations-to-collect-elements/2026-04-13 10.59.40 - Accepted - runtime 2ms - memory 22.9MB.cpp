class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> s;
        int c = 0;

        for(int i = n - 1; i >= 0; i--) {
            c++;
            if(nums[i] <= k) s.insert(nums[i]);
            if(s.size() == k) return c;
        }

        return c;
    }
};