class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        int n = nums.size();

        // Store prefixSum -> latest index
        unordered_map<int, int> prefixIndex;

        prefixIndex[0] = -1;

        int totalSum = 0;

        // Build prefix sum map
        for (int i = 0; i < n; i++) {

            totalSum += nums[i];

            prefixIndex[totalSum] = i;
        }


        // If total sum is smaller than x,
        // it is impossible to remove elements with sum x.
        if (totalSum < x) {
            return -1;
        }


        /*
            Instead of removing elements from both ends,
            we find the longest subarray whose sum is:

                totalSum - x
        */

        int targetSubarraySum = totalSum - x;

        int longestSubarrayLength = INT_MIN;

        int currentPrefixSum = 0;


        // Find the longest subarray
        // having sum = totalSum - x
        for (int i = 0; i < n; i++) {

            currentPrefixSum += nums[i];

            int requiredPrefixSum = currentPrefixSum - targetSubarraySum;


            if (prefixIndex.count(requiredPrefixSum)) {

                int subarrayLength = i - prefixIndex[requiredPrefixSum];

                longestSubarrayLength = max(longestSubarrayLength, subarrayLength);
            }
        }


        // If no valid subarray exists
        if (longestSubarrayLength == INT_MIN) {
            return -1;
        }


        // Remove everything outside the longest
        // valid subarray.
        return n - longestSubarrayLength;
    }
};