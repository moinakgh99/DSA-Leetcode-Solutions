class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int len = 0;

        for(int i = 0; i < n; i++) {
            int j = i+1;
            int inc = 1;

            while(j < n && nums[j-1] < nums[j]) {
                inc++;
                j++;
            }

            j = i+1;
            int dec = 1;
            while(j < n && nums[j-1] > nums[j]) {
                dec++;
                j++;
            }

            len = max(len, max(inc, dec));
        }

        return len;
    }
};