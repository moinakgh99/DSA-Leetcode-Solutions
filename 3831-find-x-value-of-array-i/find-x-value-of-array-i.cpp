class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {

        int n = nums.size();

        // result[remainder] = total number of subarrays
        // whose product % k == remainder
        vector<long long> result(k, 0);

        // Number of subarrays ending at the previous index
        // grouped by their product remainder
        vector<long long> previousRemainderCount(k, 0);

        for (int i = 0; i < n; i++) {

            // Number of subarrays ending at index i,
            // grouped by product remainder
            vector<long long> currentRemainderCount(k, 0);

            // Start a new subarray with nums[i]
            int currentElementRemainder = nums[i] % k;

            currentRemainderCount[currentElementRemainder]++;

            // Extend all subarrays that ended at i - 1
            for (int previousRemainder = 0;
                 previousRemainder < k;
                 previousRemainder++) {

                int newRemainder =
                    (long long)previousRemainder * nums[i] % k;

                currentRemainderCount[newRemainder] +=
                    previousRemainderCount[previousRemainder];
            }

            // Current becomes previous for the next iteration
            previousRemainderCount = move(currentRemainderCount);

            // Add all subarrays ending at i to the final answer
            for (int remainder = 0; remainder < k; remainder++) {
                result[remainder] += previousRemainderCount[remainder];
            }
        }

        return result;
    }
};