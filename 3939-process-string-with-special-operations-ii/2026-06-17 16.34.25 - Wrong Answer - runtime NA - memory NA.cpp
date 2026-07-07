class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.length();
        long long l = 0;

        // Calculating length from left to right
        for(char &c : s) {
            if(c == '#') l *= 2;
            else if(c == '%') continue;
            else if(c == '*') l--;
            else l++;   // for alphabets a to z
        }

        if(k >= l) return '.';

        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '#') {
                l = l/2;
                k = k - l;
            }
            else if(s[i] == '%') k = l - k - 1;
            else if(s[i] == '*') l++;
            else l--;

            if(l == k) return s[i];
        }

        return '.';

    }
};