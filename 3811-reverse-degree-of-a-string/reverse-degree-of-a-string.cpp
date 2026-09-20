class Solution {
public:
    int reverseDegree(string s) {
        
        string newS = " " + s;
        int n = s.length();

        int sum = 0;
        for(int i = 1; i <= n; i++) {
            int product = 1;

            product = i * ('z' - newS[i] + 1);

            sum += product;
        }

        return sum;
    }
};