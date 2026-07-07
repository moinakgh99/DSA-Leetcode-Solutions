class Solution {
public:
    long long sumAndMultiply(int n) {
        
        // My Approach ... ( Two Traversal ) ...
        
        // string str = to_string(n);
        // string res = "";

        // for(int i = 0; i < str.length(); i++) {
        //     if(str[i] != '0') res += str[i];
        // }

        // if(res.empty()) return 0;

        // long long sum = 0;
        // long long num = stoll(res);
        // long long nonZero = num;

        // while(num > 0) {
        //     int dig = num % 10;
        //     sum += dig;
        //     num = num / 10;
        // }

        // return nonZero * sum;



        // Single Traversal ....

        // long long sum = 0, newNum = 0, place = 1;
        // while(n > 0) {
        //     int dig = n % 10;

        //     if(dig != 0) {
        //         sum += dig;
        //         newNum = dig * place + newNum;
        //         place = place * 10;
        //     }

        //     n = n / 10;
        // }

        // return newNum * sum;



        // Using Stack ...
        long long sum = 0, newNum = 0;
        stack<int> st;

        while(n > 0) {
            int dig = n % 10;

            if(dig != 0) {
                sum += dig;
                st.push(dig);
            }

            n = n / 10;
        }

        while(!st.empty()) {
            newNum = newNum * 10 + st.top();
            st.pop();
        }

        return newNum * sum;
    }
};