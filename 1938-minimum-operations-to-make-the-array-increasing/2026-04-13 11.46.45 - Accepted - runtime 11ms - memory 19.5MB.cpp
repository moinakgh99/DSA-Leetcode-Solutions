class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int diff = 0;
        for(int i = 1; i < n; i++) {
            if(nums[i] > nums[i-1]) continue;
            else {
                diff += (nums[i-1] + 1) - nums[i];
                nums[i] = 1 + nums[i-1];
            }
        }
        return diff;
    }
};