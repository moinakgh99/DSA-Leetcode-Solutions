class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        int jumps = 0, maxIdx = 0;
        int end = 0;

        for(int i = 0; i < n-1; i++) {
            maxIdx = max(i + nums[i], maxIdx);

            if(i == end) {
                jumps++;
                end = maxIdx;
            }
        }

        return jumps;
    }
};