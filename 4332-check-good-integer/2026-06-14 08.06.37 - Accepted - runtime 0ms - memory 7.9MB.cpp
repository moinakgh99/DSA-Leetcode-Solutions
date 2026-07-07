class Solution {
public:

    int sum(int n) {
        int sum = 0;
        while(n > 0) {
            sum += n%10;
            n = n/10;
        }
        return sum;
    }

    int square(int n) {
        int sum = 0;
        while(n > 0) {
            int dig = n%10;
            sum += dig * dig;
            n = n/10;
        }

        return sum;
    }
    
    bool checkGoodInteger(int n) {
        int digitSum = sum(n);
        int squareSum = square(n);

        return (squareSum - digitSum) >= 50 ? true : false;
    }
};