class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length();
        int count_One = 0;

        for(char ch : s) { if(ch == '1') count_One++; }
        string res(n, '0');

        int i = 0;
        while(count_One > 1) {
            res[i] = '1';
            i++;
            count_One--;
        }

        res[n-1] = '1';

        return res;
    }
};