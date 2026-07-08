class Solution {
public:

    typedef long long ll;
    int mod = 1e9+7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        
        // TLE Coz of O(n2) ....

        // vector<int> finalAns;
        // for(int i = 0; i < queries.size(); i++) {

        //     int l = queries[i][0], r = queries[i][1];
            
        //     long long sum = 0, ans = 0;
        //     for(int j = l; j <= r; j++) {
        //         if(s[j] != '0') {
        //             int dig = s[j] - '0';
        //             sum += dig;
        //             ans = ((ans * 10) + dig) % mod;
        //         }
        //     }

        //     finalAns.push_back((1LL * ans * sum) % mod);
        // }

        // return finalAns;



        // Optimal Approach ...
        int n = s.length();
        vector<ll> digSum(n,0); // to calculate the sum upto last
        vector<int> nonZeroDig(n,0); // to count no. of non dig element
        vector<ll> pow10(n+1, 0); // to calculate the power of 10
        vector<ll> numberFormed(n, 0);  // to check the number formed upto last

        pow10[0] = 1;  // 10 ki power 0 hoti h 1, pehle hi push kra dia
        for(int i = 1; i <= n; i++) {
            pow10[i] = (1LL * pow10[i-1] * 10) % mod;
        }

        nonZeroDig[0] = (s[0] != '0') ? 1 : 0;
        for(int i =1; i < n; i++) {
            int dig = s[i] - '0';
            nonZeroDig[i] = nonZeroDig[i-1] + ((dig != 0) ? 1 : 0);
        }

        numberFormed[0] = s[0] - '0'; // bss pehla dig push kia h !!
        for(int i = 1; i < n; i++) {
            int dig = s[i] - '0';  // dig nikalo h !!
            if(dig != 0) {
                numberFormed[i] = ((numberFormed[i-1] * 10) + dig) % mod;
            }
            else numberFormed[i] = numberFormed[i-1];  // agar dig 0 rh to !!
        }

        digSum[0] = s[0] - '0';
        for(int i = 1; i < n; i++) {
            int dig = s[i] - '0';
            digSum[i] = digSum[i-1] + dig;
        }

        int m = queries.size();
        vector<int> res(m);

        for(int i = 0; i < m; i++) {
            int l = queries[i][0], r = queries[i][1];

            ll sum = digSum[r] - ((l == 0) ? 0 : digSum[l-1]);
            
            int number = (l == 0) ? 0 : numberFormed[l-1];
            int k = nonZeroDig[r] - ((l == 0) ? 0 : nonZeroDig[l-1]);
            ll x = (numberFormed[r] - (number * pow10[k] * 1ll % mod) + mod) % mod;

            res[i] = (int)((x * sum) % mod);
        }

        return res;

    }
};