class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return 0;

        int maxIdx = 0, jumps = 0;
        int end = 0;

        for(int i = 0; i < n-1; i++) {

            maxIdx = max(maxIdx, i + nums[i]);
            
            if(i == end) {
                jumps++;
                end = maxIdx;
            }
        }

        return jumps;
    }
};