class Solution {
public:

    int getDig(int nums) {
        int n = nums;

        int sum = 0;
        while(n > 0) {
            int dig = n % 10;
            sum += dig;

            n /= 10;
        }

        return sum;
    }

    int smallestIndex(vector<int>& nums) {
        int n = nums.size();

        int idx = -1;
        for(int i = 0; i < n; i++) {
            int sumNum = getDig(nums[i]);

            if(sumNum == i) {
                idx = i;
                break;
            }
        }

        return idx;
    }
};