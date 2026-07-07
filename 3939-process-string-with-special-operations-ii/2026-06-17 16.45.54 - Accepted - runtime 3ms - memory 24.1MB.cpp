class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.length();
        long long l = 0;

        // Calculating length from left to right
        for(char &c : s) {
            if(c == '#') l *= 2;
            else if(c == '%') continue;
            else if(c == '*') {
                if(l > 0) l--;
            }    
            else l++;   // for alphabets a to z
        }

        if(k >= l) return '.';

        // Now calculatitng value of k from right to left
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '#') {
                l = l/2;
                k = (k >= l) ? k - l : k;
            }
            else if(s[i] == '%') k = l - k - 1;  // no change in l
            else if(s[i] == '*') l++;  // no change in k
            else {
                l--;
                if(l == k) return s[i];
            } 

        }

        return '.';

    }
};