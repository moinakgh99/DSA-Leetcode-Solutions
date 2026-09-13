class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length();

        string res(n, '0');

        int c_one = 0;
        for(char ch : s) {
            if(ch == '1') c_one++;
        }

        int i = 0;
        while(i < n && c_one > 1) {
            res[i] = '1';
            c_one--;
            i++;
        }

        res[n-1] = '1';

        return res;
    }
};