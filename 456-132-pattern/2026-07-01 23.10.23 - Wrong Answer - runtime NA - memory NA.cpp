class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = i + 1, k = i + 2;

        while(k < n) {
            if(nums[i] > nums[k]) {
                i++;
                j++;
            }
            else if(nums[i] < nums[k] && nums[k] < nums[j]) return true;
            k++;
        }
        return false;

    }
};