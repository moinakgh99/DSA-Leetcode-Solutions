class Solution {
public:
    typedef long long ll;

    string func(ll num, int len) {
        string str;

        for(int dig = 9; dig >= 2; dig--) {
            while(num % dig == 0) {
                str.push_back(dig + '0');
                num /= dig;
            }
        }

        while(str.length() < len) str.push_back('1');

        reverse(str.begin(), str.end());

        return str;
    }

    string smallestNumber(string num, long long t) {
        int n = num.length();

        /*
            1 -> 9 tk bss 2,3,5,7 factors hi niklenga !!!
            to sbse pehle t ko in factors se divide krenga ,
            agar divide hojate h to , thk h update krte rho use,
            vrna -1 return krdo, kyoki kbhi ans aaega hi nhi !!
        */
        ll temp = t;
        for(int factor : {2,3,5,7}) {
            while(temp % factor == 0) {
                temp /= factor;
            }
        }

        if(temp != 1) return "-1";

        /*
            Precompute krenga ek vector me, agar hum ith index lete h , to remaining factors ky bachenga t me se ...
            for ex: idx 0 me 2 h, to t se divide krke , jo factors bachenga vo aaga compute krte rhenga !!
        */
        vector<ll> remFactors(n+1, t);
        for(int i = 0; i < n; i++) {
            int dig = num[i] - '0';
            
            if(dig == 0) break;

            remFactors[i+1] = remFactors[i] / gcd(remFactors[i], (ll)dig);
        }

        if(remFactors[n] == 1) return num;  // for ex 2

        int zeroPos = num.find('0');
        int zeroIdx = n-1;
        if(zeroPos != -1) zeroIdx = zeroPos;

        for(int i = zeroIdx; i >= 0; i--) {
            ll required = remFactors[i];
            int freeSlots = n - i - 1;

            for(int dig = (num[i] - '0' + 1); dig <= 9; dig++) {
                ll furtherRequired = required / gcd(required, dig);
                string reqNumber = func(furtherRequired, freeSlots);

                if(reqNumber.length() == freeSlots) return num.substr(0, i) + char(dig + '0') + reqNumber;
                
            }
        }

        return func(t, n+1);
    }
};