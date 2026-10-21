class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        // Check if already sorted
        if (is_sorted(s.begin(), s.end()))
            return 0;

        // Cannot sort an unsorted string of length 2
        if (n == 2)
            return -1;

        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        // One operation is enough
        if (s[0] == mn || s[n - 1] == mx)
            return 1;

        // Check whether min or max occurs in the middle
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == mn || s[i] == mx)
                return 2;
        }

        return 3;
    }
};