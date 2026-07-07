class Solution {
public:
    long long sumAndMultiply(int n) {
        
        // My Approach ...
        string str = to_string(n);
        string res = "";

        for(int i = 0; i < str.length(); i++) {
            if(str[i] != '0') res += str[i];
        }

        if(res.empty()) return 0;

        long long sum = 0;
        long long num = stoll(res);
        long long nonZero = num;

        while(num > 0) {
            int dig = num % 10;
            sum += dig;
            num = num / 10;
        }

        return nonZero * sum;
    }
};