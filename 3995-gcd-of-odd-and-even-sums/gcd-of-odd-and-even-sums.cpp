class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumEven = 0, sumOdd = 0;
        for(int i = 1; i <= 2*n; i++) {
            if(i % 2 == 0) sumEven += i;
            else sumOdd += i;
        }

        return __gcd(sumEven, sumOdd);
    }
};