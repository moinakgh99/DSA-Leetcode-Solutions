class Solution {
public:
    int n;

    // nextIndex[i] = first interval that starts after intervals[i] ends
    vector<int> nextIndex;

    // Stores:
    // score -> maximum total weight
    // indices -> original indices of selected intervals
    struct State {
        long long score = -1;
        vector<int> indices;
    };

    // DP table
    // dp[i][k] = best answer considering intervals from i onwards
    //            when we can still select at most k intervals
    vector<vector<State>> dp;

    // Find the first interval whose start time > currentEnd
    int findNextIndex(vector<vector<int>>& intervals, int currentEnd) {

        int left = 0;
        int right = n - 1;

        int next = n;  // No valid next interval found

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (intervals[mid][0] > currentEnd) {

                // This interval can be selected next
                next = mid;

                // Try to find an even earlier valid interval
                right = mid - 1;

            } else {

                // Start time is not greater than currentEnd
                // So move to the right
                left = mid + 1;
            }
        }

        return next;
    }

    // Returns the best result starting from interval 'i'
    // with at most 'k' intervals allowed
    State solve(vector<vector<int>>& intervals, int i, int k) {

        // No intervals left OR no selections allowed
        if (k == 0 || i >= n) {
            return State();
        }

        // Already calculated
        if (dp[i][k].score != -1) {
            return dp[i][k];
        }

        // Current interval information
        int weight = intervals[i][2];
        int originalIndex = intervals[i][3];

        // First compatible interval after taking current interval
        int next = nextIndex[i];

        // --------------------------------------------------
        // OPTION 1: Skip the current interval
        // --------------------------------------------------
        State skip = solve(intervals, i + 1, k);

        // --------------------------------------------------
        // OPTION 2: Take the current interval
        // --------------------------------------------------

        State remaining = solve(intervals, next, k - 1);

        State take;

        take.score = remaining.score + weight;

        take.indices = remaining.indices;

        // Add current interval's original index
        take.indices.push_back(originalIndex);

        // Sort indices because lexicographically smallest
        // index sequence is required in case of equal scores
        sort(take.indices.begin(), take.indices.end());

        // --------------------------------------------------
        // Choose the better option
        // --------------------------------------------------

        State result;

        if (skip.score > take.score) {

            // Skipping gives greater weight
            result = skip;

        } else if (skip.score < take.score) {

            // Taking gives greater weight
            result = take;

        } else {

            // Same weight:
            // Choose lexicographically smaller index sequence
            result = (skip.indices < take.indices) ? skip : take;
        }

        return dp[i][k] = result;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        n = intervals.size();

        // Store the original index of every interval
        for (int i = 0; i < n; i++) {
            intervals[i].push_back(i);
        }

        // Sort intervals by start time
        sort(intervals.begin(), intervals.end());

        // Calculate the next compatible interval for every interval
        nextIndex.resize(n);

        for (int i = 0; i < n; i++) {

            int currentEnd = intervals[i][1];

            nextIndex[i] = findNextIndex(intervals, currentEnd);
        }

        // We can select at most 4 intervals
        const int MAX_INTERVALS = 4;

        // Initialize DP table
        dp.assign(
            n + 1,
            vector<State>(MAX_INTERVALS + 1)
        );

        return solve(intervals, 0, MAX_INTERVALS).indices;
    }
};