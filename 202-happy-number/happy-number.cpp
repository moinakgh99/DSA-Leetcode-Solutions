class Solution {
public:

    int squareSum(int n) {
        int sum = 0;

        while(n > 0) {
            int dig = n % 10;
            sum += dig * dig;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> used;

        while(true) {
            int sum = squareSum(n);

            if(sum == 1) return true;

            n = sum;

            if(used.find(n) != used.end()) return false;

            used.insert(n);
        }
    }
};