class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        int i = 0, j = 0;
        long long ans = 0;
        long long sum = 0;
        unordered_set<int> st;

        while(j < n) {
            
            /* sbse pehe check krenga ki set me present h element ?, agar h to,
                window ko shrink krenge, aur set me se erase krdenga !!
            */
            while(st.count(nums[j])) {
                sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            // agar present nhi h !!
            sum += nums[j];
            st.insert(nums[j]);

            if(j - i + 1 == k) {
                ans = max(ans, sum);

                // agar j++ ki vja se window size bada hojae to ..
                sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            j++;
        }

        return ans;
    }
};