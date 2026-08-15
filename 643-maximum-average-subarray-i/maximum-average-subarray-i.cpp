class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        double sum = 0;
        double avg = 0, ans = INT_MIN;

        while(j < n) {
            sum += nums[j];

            if(j - i + 1 == k) {
                avg = sum / k;
                ans = max(ans, avg);

                sum -= nums[i];
                i++;
            }
            
            j++;
        }

        return ans;
    }
};