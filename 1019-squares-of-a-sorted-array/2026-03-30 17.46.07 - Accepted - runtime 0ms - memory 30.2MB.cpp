class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            nums[i] = nums[i] * nums[i];
        }

        vector<int> res(n);
        int i = 0, j = n - 1;
        for(int k = n - 1; k >= 0; k--) {
            if(nums[i] > nums[j]) {
                res[k] = nums[i];
                i++;
            }

            else {
                res[k] = nums[j];
                j--;
            }
        }

        return res;

    }
};