class Solution {
public:

    int mod = 1e9+7;

    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        
        // Approach 1 : Gives TLE ....
        /*
        int c = 0;
        for(int i = 0; i < n; i++) {
            int sum = 0;

            for(int j = i; j < n; j++) {
                sum += arr[j];

                if(sum % 2 != 0) c++;
            }
        }

        return c % mod;
        */

        vector<int> prefix(n, 0);
        prefix[0] = arr[0];

        for(int i = 1; i < n; i++) prefix[i] = prefix[i-1] + arr[i];

        int c = 0, even = 1, odd = 0;
        for(int i = 0; i < n; i++) {
            if(prefix[i] % 2 == 0) {
                c = (c + odd) % mod;
                even++;
            } else {
                c = (c + even) % mod;
                odd++;
            }
        }

        return c;
    }
};