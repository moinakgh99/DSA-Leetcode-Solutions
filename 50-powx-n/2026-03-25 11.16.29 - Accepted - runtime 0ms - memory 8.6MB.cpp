class Solution {
public:
    double func(double x, long long int n) {
        if(n == 0) return 1;
        double ans = func(x, n/2);

        if(n%2 == 0) return ans*ans;
        else return ans*ans*x;
    }


    double myPow(double x, long long int n) {
        if(n > 0) return func(x,n);
        else return 1 / func(x, -n);
    }
};