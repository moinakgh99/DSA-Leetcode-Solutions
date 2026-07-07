class Solution {
public:
    string maximumOddBinaryNumber(string s) {

        // // 1st Approach
        // int n = s.length();
        // string res(n,'0');

        // int i = 0;
        // for(char &ch : s) {
        //     if(ch == '1') {
        //         if(res[n-1] == '1') {
        //             res[i] = '1';
        //             i++;
        //         }
        //         else res[n-1] = '1';
        //     }
        // }

        // return res;

        // 2nd Approach
        int n = s.length();
        string res(n, '0');
        int cOne = 0;

        for(char &ch : s) {
            if(ch == '1') cOne++;
        }

        int i = 0;
        while(cOne > 1) {
            res[i] = '1';
            i++;
            cOne--;
        }
        res[n-1] = '1';

        return res;
    }
};