class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        int maxIdx = 0;
        for(int i = 0; i < n; i++) {
            if(i > maxIdx) return false;

            maxIdx = max(i + nums[i], maxIdx);
        }

        return (maxIdx >= n-1);
    }
};