class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int countLess = 0, equal = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] < pivot) countLess++;
            else if(nums[i] == pivot) equal++;
        }

        vector<int> res(n);
        int i = 0, j = countLess, k = countLess + equal;
        for(int x = 0; x < n; x++) {
            if(nums[x] < pivot) {
                res[i] = nums[x];
                i++;
            }
            else if(nums[x] == pivot) {
                res[j] = nums[x];
                j++;
            }
            else {
                res[k] = nums[x];
                k++;
            }
        }
        return res;
    }
};