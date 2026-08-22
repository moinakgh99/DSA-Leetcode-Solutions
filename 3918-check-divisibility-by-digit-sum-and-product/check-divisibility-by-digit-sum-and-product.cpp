class Solution {
public:
    bool checkDivisibility(int n) {
        
        int sum = 0, product = 1;
        int num = n;
        while(n > 0) {
            int digit = n % 10;
            sum += digit;
            product *= digit;
            n /= 10;
        }

        int totalSum = sum + product;

        return (num % totalSum == 0) ? true : false;
    }
};