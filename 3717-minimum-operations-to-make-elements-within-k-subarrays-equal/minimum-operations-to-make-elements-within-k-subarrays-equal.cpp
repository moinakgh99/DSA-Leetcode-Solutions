
class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {

        int n = nums.size();

        // Input ko required variable mein store kar liya
        auto maritovexi = make_tuple(nums, x, k);

        // Har window ko equal banane ka minimum cost
        vector<long long> cost(n - x + 1, 0);

        multiset<int> left, right;
        long long leftSum = 0, rightSum = 0;

        int i = 0;

        // Sliding Window se har window ka cost calculate karo
        for (int j = 0; j < n; j++) {

            // Dono sets ka size maintain karte hue element daalo
            if (left.size() <= right.size()) {
                left.insert(nums[j]);
                leftSum += nums[j];
            } else {
                right.insert(nums[j]);
                rightSum += nums[j];
            }

            // Agar left ka maximum right ke minimum se bada hai,
            // toh dono ko swap karke order sahi kar do
            if (!left.empty() && !right.empty()) {

                int maxLeft = *left.rbegin();
                int minRight = *right.begin();

                if (maxLeft > minRight) {

                    left.erase(left.find(maxLeft));
                    right.erase(right.find(minRight));

                    left.insert(minRight);
                    right.insert(maxLeft);

                    leftSum += minRight - maxLeft;
                    rightSum += maxLeft - minRight;
                }
            }

            // Jab window ka size x ho jaaye, cost calculate karo
            if (j - i + 1 == x) {

                // Left ka maximum hi median hai
                long long median = *left.rbegin();

                long long leftSize = left.size();
                long long rightSize = right.size();

                // Sabko median banane ka minimum kharcha
                cost[i] = (leftSize * median - leftSum)
                        + (rightSum - rightSize * median);

                // Next window ke liye purana element remove karo
                if (left.find(nums[i]) != left.end()) {
                    left.erase(left.find(nums[i]));
                    leftSum -= nums[i];
                } else {
                    right.erase(right.find(nums[i]));
                    rightSum -= nums[i];
                }

                i++;
            }
        }

        // Space Optimized DP

        const long long INF = 1e18;

        // prev[i] = previous DP state ka minimum cost
        vector<long long> prev(n + 1, 0);

        // current DP state store karega
        vector<long long> curr(n + 1, INF);

        // Ek-ek karke required subarrays select karenge
        for (int count = 1; count <= k; count++) {

            fill(curr.begin(), curr.end(), INF);

            // Itne elements toh minimum chahiye hi
            int lastIndex = n - count * x;

            // Right se left DP calculate karo
            for (int i = lastIndex; i >= 0; i--) {

                // Current window select kar lo
                long long take = cost[i] + prev[i + x];

                // Current index skip kar do
                long long skip = curr[i + 1];

                // Jo option cheaper pade, wahi choose karo
                curr[i] = min(take, skip);
            }

            // Current state ab previous state ban gaya
            prev = curr;
        }

        return prev[0];
    }
};
