class Solution {
public:
    int gcdOfOddEvenSums(int n) {

        // Approach 1 .... Simple for Loop
        // int sumEven = 0, sumOdd = 0;
        // for(int i = 1; i <= 2*n; i++) {
        //     if(i % 2 == 0) sumEven += i;
        //     else sumOdd += i;
        // }

        // return __gcd(sumEven, sumOdd);


        // Approach 2 : Mathematical Formula ...
        // int sumOdd = n * n;
        // int sumEven = n * ( n + 1 );

        // return __gcd(sumOdd, sumEven);


        // Approach 3 : Derived from approach 2
        /*  __gcd(n * n, n * (n + 1));
            n * __gcd(n, n + 1);
            gcd for n and n + 1 will always be 1, so return only n ..
        */

        return n;
    }
};