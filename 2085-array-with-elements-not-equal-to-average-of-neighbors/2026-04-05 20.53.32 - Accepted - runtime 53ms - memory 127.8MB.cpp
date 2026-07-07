class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = (n+1)/2;

        vector<int> res(n);
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                res[i] = nums[l];
                l++;
            } else {
                res[i] = nums[r];
                r++;
            }
        }

        return res;
    }
};